//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "modfuncs.h"
#include "filemanip.h"
#include "ajoutfuncs.h"
#include "tui.h"

#define MAX_SIZE 2048
int entryls;

void write_to_file(FILE *writefile, etudiant *list){
   etudiant *studntlist = list;
   int n;
   fprintf(writefile,"N, Apogee, Nom, Prenom, Genre, Filiere, Date d'inscription, Date de graduation,");
   fprintf(writefile,"Email academique, Module 1, Note 1, Module 2, Note 2, Module 3, Note 3, Module 4,");
   fprintf(writefile,"Note 4, Module 5, Note 5, Module 6, Note 6, Module 7, Note 7, Moyenne\n");
   n = 1;
   while(studntlist != NULL){

        fprintf(writefile, "%d,", n);

        fprintf(writefile, "%07d,", studntlist->etud_info.apogee);

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
    etudiant *p = studntlist;
    char name[strlen(filename) + 5];
    snprintf( name, sizeof(name), "%s.csv", filename);

    FILE *file = fopen(name, "w");
    if (file != NULL){
        write_to_file(file, p);
    }
    else{
        printf("ERREUR ! Impossible d'ouvrir %s !\n", name);
    }

    fclose(file);
}

void readfile(char *filename, int echototerm, etudiant **out) {
    char name[strlen(filename) + 5], line[MAX_SIZE];
    snprintf(name, sizeof(name), "%s.csv", filename);

    int n=1;

    FILE *file = fopen(name, "r");
    if (file != NULL){

        fgets(line, sizeof(line), file);

        etudiant *list = NULL;
        while (fgets(line, sizeof(line), file) != NULL){
            etudiant *new_etudiant = (etudiant *) malloc(sizeof(etudiant));
            strtok(line, ","); // Skip N
            
            sscanf(strtok(NULL, ","), "%d,", &new_etudiant->etud_info.apogee);
            sscanf(strtok(NULL, ","), "%s,", new_etudiant->etud_info.nom);
            sscanf(strtok(NULL, ","), "%s,", new_etudiant->etud_info.prenom);
            char genre[6];
            sscanf(strtok(NULL, ","), "%s,", genre);
            if (strcmp(genre, "Femme") == 0) {
                new_etudiant->etud_info.genre = 1;
            } else if (strcmp(genre, "Homme") == 0) {
                new_etudiant->etud_info.genre = 2;
            }
            char filiere[4];
            sscanf(strtok(NULL, ","), "%s,", filiere);
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
            sscanf(strtok(NULL, ","), "%s,", new_etudiant->etud_info.academic_email);
            for (int i = 0; i < 7; i++) {
                sscanf(strtok(NULL, ","), "%s,", new_etudiant->etud_info.modules[i].module_name);
                sscanf(strtok(NULL, ","), "%f,", &new_etudiant->etud_info.modules[i].module_note);
            }
            sscanf(strtok(NULL, ","), "%f", &new_etudiant->etud_info.moy);
            
            new_etudiant->suiv = NULL;

            if(list == NULL){
                list = new_etudiant;
            }
            else{
                etudiant *p = list;
                while (p->suiv != NULL) {
                    p = p->suiv;
                }
                p->suiv = new_etudiant;
            }

            n++;
        }

        if(echototerm && list){
            draw_table(list);
        }

        entryls = n-1;

        fclose(file);

        *out = list;
    }
}



void modfile(char *filename, etudiant *studntlist){
    int apo;
    printf("Numero Apogee d'etudiant : ");
    scanf("%d", &apo);
    studntlist = modifier_etud_info(studntlist, (int)apo);
    create(filename, studntlist);
}