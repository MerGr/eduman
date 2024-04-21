#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "modfuncs.h"
#include "filemanip.h"
#include "ajoutfuncs.h"

#define MAX_SIZE 2048
int entryls;

void write_to_file(FILE *writefile, etudiant *studntlist){
   int n;
   fseek(writefile, 0, SEEK_END);
   n = 1;
   while(studntlist != NULL){
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\t\t\t\tEtudiant %d\n", n);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\tApogee\t\t\t\t\t%d\t\t\n", studntlist->etud_info.apogee);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\tNom et Prenom\t\t\t%s %s\t\t\n",studntlist->etud_info.nom,studntlist->etud_info.prenom);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        if(studntlist->etud_info.genre == 1)
            fprintf(writefile, "|\tGenre\t\t\t\t\tFemme\t\t\n");
        else
            fprintf(writefile, "|\tGenre\t\t\t\t\tHomme\t\t\n");
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        switch(studntlist->etud_info.filiere){
            case 1:
                fprintf(writefile, "|\tFiliere\t\t\t\t\tSMI\t\t\n");
                break;
            case 2:
                fprintf(writefile, "|\tFiliere\t\t\t\t\tSMA\t\t\n");
                break;
            case 3:
                fprintf(writefile, "|\tFiliere\t\t\t\t\tSMP\t\t\n");
                break;
            case 4:
                fprintf(writefile, "|\tFiliere\t\t\t\t\tSMC\t\t\n");
                break;
            case 5:
                fprintf(writefile, "|\tFiliere\t\t\t\t\tSVI\t\t\n");
                break;
            case 6:
                fprintf(writefile, "|\tFiliere\t\t\t\t\tSTU\t\t\n");
                break;
        }
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\tDate d'inscription\t\t%02u/%02d/%04u\t\t\n",studntlist->etud_info.date_inscription.jour,(int)studntlist->etud_info.date_inscription.mois,studntlist->etud_info.date_inscription.annee);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\tDate de graduation\t\t%02u/%02d/%04u\t\t\n",studntlist->etud_info.graduation_date.jour,(int)studntlist->etud_info.graduation_date.mois,studntlist->etud_info.graduation_date.annee);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\tEmail Academique\t\t%s\t\t\n", studntlist->etud_info.academic_email);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "|\tNom du module\t\t\t\tNote du module\t\t\n");
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        for(int i=0; i<7; i++){
            fprintf(writefile, "|\t%s\t\t\t\t%.4f\t\t\n", studntlist->etud_info.modules[i].module_name, studntlist->etud_info.modules[i].module_note);
            fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        }
        fprintf(writefile, "|\tMoyenne\t\t\t\t\t%.04f\t\t\n", studntlist->etud_info.moy);
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        fprintf(writefile, "+----------------------------------+---------------------------------+\n");
        studntlist = studntlist->suiv; n++;
   }
   entryls = n;
}

void create(char *filename, etudiant *studntlist){
    char name[strlen(filename) + 5];
    snprintf( name, sizeof(name), "%s.txt", filename);

    FILE *file = fopen(name, "w+");
    if (file != NULL){
        write_to_file(file, studntlist);
    }
    else{
        printf("ERREUR ! Impossible d'ouvrir %s !\n", name);
    }

    fclose(file);
}

etudiant *readfile(char* filename, int echototerm, etudiant* list, int import) {
    char name[strlen(filename) + 5], line[MAX_SIZE] = "";
    snprintf(name, sizeof(name), "%s.txt", filename);
    char tmpstr[10];

    FILE* file = fopen(name, "r");
    if (file != NULL) {
        etudiant* new_etudiant = NULL;

        while (fgets(line, MAX_SIZE, file) != NULL) {
            if (echototerm) printf("%s", line);

            if (strncmp(line, "+", 1) == 0 && entryls != 0 && import) {
                if (list == NULL) {
                    list = (etudiant*)malloc(sizeof(etudiant));
                    if (list == NULL) {
                        fprintf(stderr, "Memory allocation error\n");
                        return NULL;
                    }
                    new_etudiant = list;
                } else {
                    new_etudiant->suiv = (etudiant*)malloc(sizeof(etudiant));
                    if (new_etudiant->suiv == NULL) {
                        fprintf(stderr, "Memory allocation error\n");
                        return NULL;
                    }
                    new_etudiant = new_etudiant->suiv;
                }
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                sscanf(line, "| Apogee %d\n", &new_etudiant->etud_info.apogee);
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                sscanf(line, "| Nom et Prenom %s %s\n", new_etudiant->etud_info.nom, new_etudiant->etud_info.prenom);
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                sscanf(line, "| Genre %s\n", tmpstr);
                if(strcmp(tmpstr, "Homme"))
                    new_etudiant->etud_info.genre = 1;
                else
                    new_etudiant->etud_info.genre = 2;
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 

                fgets(line, MAX_SIZE, file);
                fgets(line, MAX_SIZE, file);
                fgets(line, MAX_SIZE, file);
                sscanf(line, "| Filiere %s\n", tmpstr);

                if (strcmp(tmpstr, "SMI") == 0)
                    new_etudiant->etud_info.filiere = SMI;
                else if (strcmp(tmpstr, "SMA") == 0)
                    new_etudiant->etud_info.filiere = SMA;
                else if (strcmp(tmpstr, "SMP") == 0)
                    new_etudiant->etud_info.filiere = SMP;
                else if (strcmp(tmpstr, "SMC") == 0)
                    new_etudiant->etud_info.filiere = SMC;
                else if (strcmp(tmpstr, "SVI") == 0)
                    new_etudiant->etud_info.filiere = SVI;
                else if (strcmp(tmpstr, "STU") == 0)
                    new_etudiant->etud_info.filiere = STU;
                
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                sscanf(line, "| Date d'inscription %u/%d/%u\n", &new_etudiant->etud_info.date_inscription.jour, (int *)&new_etudiant->etud_info.date_inscription.mois, &new_etudiant->etud_info.date_inscription.annee);
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                sscanf(line, "| Date de graduation %u/%d/%u\n", &new_etudiant->etud_info.graduation_date.jour, (int *)&new_etudiant->etud_info.graduation_date.mois, &new_etudiant->etud_info.graduation_date.annee);
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                sscanf(line, "| Email Academique %s\n", new_etudiant->etud_info.academic_email);
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 
                fgets(line, MAX_SIZE, file); 

                int stop = 1;
                for (int i = 0; i < 7; i++) {
                    fgets(line, MAX_SIZE, file); 
                    sscanf(line, "| %s %f\n", new_etudiant->etud_info.modules[i].module_name, &new_etudiant->etud_info.modules[i].module_note);
                    if(!(strcmp(new_etudiant->etud_info.modules[i].module_name, "---")) && stop){
                        new_etudiant->etud_info.num_of_modules = i+1;
                        stop--;
                    }
                    fgets(line, MAX_SIZE, file); 
                }

                fgets(line, MAX_SIZE, file);
                sscanf(line, "| Moyenne %f\n", &new_etudiant->etud_info.moy);

                new_etudiant->suiv = NULL;
                ajout_fin(list);
            }
        }

        fclose(file);
        return list;
    }

    return NULL;
}



void modfile(char *filename, etudiant *studntlist){
    readfile(filename, 0, NULL, 0);

    etudiant *tmplist = studntlist;
    char name[strlen(filename) + 5], line[MAX_SIZE] = "";
    unsigned int nums_to_del[entryls], tmp,i = 0;
    snprintf( name, sizeof(name), "%s.txt", filename);
    rename(name, "tmpbackup.txt");

    FILE *file = fopen(name, "w+");
    if(file != NULL){
        nums_to_del[0] = 0; //INIT for check
        do{
            do{
                printf("Entrez ligne a modifier (0 pour continuer): "); scanf("%u", &tmp);
            } while(tmp>entryls);
            if(tmp) {
                    nums_to_del[i] = tmp;
                    ++i;
            }
        } while(tmp);

        tmp=0;
        i=0;
        while(fgets(line, MAX_SIZE, file) != NULL){
            if(tmp != nums_to_del[i]*2){
                studntlist = studntlist->suiv;
            }
            else{
                modifier_etudiant(&studntlist->etud_info);
                studntlist = studntlist->suiv;
                i++;
            }
            tmp++;
        }

        write_to_file(file, tmplist);
    }
    else{
        printf("ERREUR! Impossible d'ouvrir %s !\n", name);
    }

    remove("tmpbackup.txt");
    fclose(file);
}
