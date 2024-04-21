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
   fprintf(writefile,"N, Apogee, Nom, Prenom, Genre, Filiere, Date d'inscription, Date de graduation,");
   fprintf(writefile,"Email academique, Module 1, Note 1, Module 2, Note 2, Module 3, Note 3, Module 4,");
   fprintf(writefile,"Note 4, Module 5, Note 5, Module 6, Note 6, Module 7, Note 7, Moyenne\n");
   n = 1;
   while(studntlist != NULL){

        fprintf(writefile, "%d,", n);

        fprintf(writefile, "%d,", studntlist->etud_info.apogee);

        fprintf(writefile, "%s,%s,",studntlist->etud_info.nom,studntlist->etud_info.prenom);

        if(studntlist->etud_info.genre == 1)
            fprintf(writefile, "Femme,");
        else
            fprintf(writefile, "Homme,");

        switch(studntlist->etud_info.filiere){
            case 1:
                fprintf(writefile, "SMI,");
                break;
            case 2:
                fprintf(writefile, "SMA,");
                break;
            case 3:
                fprintf(writefile, "SMP,");
                break;
            case 4:
                fprintf(writefile, "SMC,");
                break;
            case 5:
                fprintf(writefile, "SVI,");
                break;
            case 6:
                fprintf(writefile, "STU,");
                break;
        }

        fprintf(writefile, "%02u/%02d/%04u,",studntlist->etud_info.date_inscription.jour,(int)studntlist->etud_info.date_inscription.mois,studntlist->etud_info.date_inscription.annee);

        fprintf(writefile, "%02u/%02d/%04u,",studntlist->etud_info.graduation_date.jour,(int)studntlist->etud_info.graduation_date.mois,studntlist->etud_info.graduation_date.annee);

        fprintf(writefile, "%s,", studntlist->etud_info.academic_email);

        for(int i=0; i<7; i++){
            fprintf(writefile, "%s,%.4f,", studntlist->etud_info.modules[i].module_name, studntlist->etud_info.modules[i].module_note);
    
        }
        fprintf(writefile, "%.04f\n", studntlist->etud_info.moy);


        studntlist = studntlist->suiv; n++;
   }
   entryls = n;
}

void create(char *filename, etudiant *studntlist){
    char name[strlen(filename) + 5];
    snprintf( name, sizeof(name), "%s.csv", filename);

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
    char name[strlen(filename) + 5], line[MAX_SIZE];
    snprintf(name, sizeof(name), "%s.csv", filename);

    int n=1;

    FILE *file = fopen(name, "r");
    if (file != NULL) {

        fgets(line, sizeof(line), file);
    
        while (fgets(line, sizeof(line), file) != NULL) {
            etudiant *new_etudiant = malloc(sizeof(etudiant));
            if (!new_etudiant) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            
            strtok(line, ","); // Skip N
            
            sscanf(strtok(NULL, ","), "%d", &new_etudiant->etud_info.apogee);
            sscanf(strtok(NULL, ","), "%[^,],%[^,]", new_etudiant->etud_info.nom, new_etudiant->etud_info.prenom);
            char genre[6];
            sscanf(strtok(NULL, ","), "%[^,],", genre);
            if (strcmp(genre, "Femme") == 0) {
                new_etudiant->etud_info.genre = 1;
            } else if (strcmp(genre, "Homme") == 0) {
                new_etudiant->etud_info.genre = 2;
            }
            char filiere[4];
            sscanf(strtok(NULL, ","), "%[^,],", filiere);
            if (strcmp(filiere, "SMI") == 0) {
                new_etudiant->etud_info.filiere = 1;
            } else if (strcmp(filiere, "SMA") == 0) {
                new_etudiant->etud_info.filiere = 2;
            } else if (strcmp(filiere, "SMP") == 0) {
                new_etudiant->etud_info.filiere = 3;
            } else if (strcmp(filiere, "SMC") == 0) {
                new_etudiant->etud_info.filiere = 4;
            } else if (strcmp(filiere, "SVI") == 0) {
                new_etudiant->etud_info.filiere = 5;
            } else if (strcmp(filiere, "STU") == 0) {
                new_etudiant->etud_info.filiere = 6;
            }
            sscanf(strtok(NULL, ","), "%2u/%2u/%4u,", &new_etudiant->etud_info.date_inscription.jour,
                                                    &new_etudiant->etud_info.date_inscription.mois,
                                                    &new_etudiant->etud_info.date_inscription.annee);
            sscanf(strtok(NULL, ","), "%2u/%2u/%4u,", &new_etudiant->etud_info.graduation_date.jour,
                                                    &new_etudiant->etud_info.graduation_date.mois,
                                                    &new_etudiant->etud_info.graduation_date.annee);
            sscanf(strtok(NULL, ","), "%[^,],", new_etudiant->etud_info.academic_email);
            for (int i = 0; i < 7; i++) {
                sscanf(strtok(NULL, ","), "%[^,],%f,", new_etudiant->etud_info.modules[i].module_name,
                                                    &new_etudiant->etud_info.modules[i].module_note);
            }
            sscanf(strtok(NULL, ","), "%f", &new_etudiant->etud_info.moy);
            
            new_etudiant = new_etudiant->suiv;
            n++;
        }
        
        entryls = n;

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

    snprintf( name, sizeof(name), "%s.csv", filename);
    rename(name, "tmpbackup.csv");

    FILE *file = fopen(name, "w+");
    if(file != NULL){
        nums_to_del[0] = 0; //INIT for check
        do{
            do{
                printf("Entrez Etudiants a modifier (MAX %d) (0 pour continuer): ", entryls); scanf("%u", &tmp);
            } while(tmp>entryls);
            if(tmp){
                    nums_to_del[i] = tmp;
                    ++i;
            }
        } while(tmp);

        tmp=0;
        i=0;
        while(fgets(line, MAX_SIZE, file) != NULL){
            
            if(tmp != nums_to_del[i]){
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

    remove("tmpbackup.csv");
    fclose(file);
}
