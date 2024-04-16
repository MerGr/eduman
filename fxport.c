#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "modfuncs.h"
#include "filemanip.h"

#define MAX_SIZE 2048
int entryls;

void fdraw_line(FILE *writefile, int w){
   for(int i = 0; i <=w; i++)
      fprintf( writefile, "-");
   fprintf( writefile, "\n");
}

void write_to_file(FILE *writefile, etudiant *studntlist){
   int n, i, tabw = strlen("|  | Apogee |      Nom      |      Prenom      | Genre | Filiere | date d'inscription | date de graduation |     Email Academique     |    Module 1    | Note 1 |   Module 2   | Note 2 |   Module 3    | Note 3 |    Module 4   | Note 4 |  Module 5   | Note 5 |    Module 6    | Note 6 |    Module 7    | Note 7 | Moyenne |");
   fseek (writefile, 0, SEEK_END);
   unsigned int filesize = ftell(writefile);

   if(filesize == 0){ 
    fdraw_line(writefile, tabw);
    fprintf( writefile, "|  | Apogee |      Nom      |      Prenom      | Genre | Filiere | date d'inscription | date de graduation |     Email Academique     |    Module 1    | Note 1 |   Module 2   | Note 2 |   Module 3    | Note 3 |    Module 4   | Note 4 |  Module 5   | Note 5 |    Module 6    | Note 6 |    Module 7    | Note 7 | Moyenne |\n");
   }
   fdraw_line(writefile, tabw);
   n = 1;
   while(studntlist != NULL){
      fprintf( writefile, "| %d |", n);
      fprintf( writefile, " %d |", studntlist->etud_info.apogee);
      fprintf( writefile, " %s |", studntlist->etud_info.nom);
      fprintf( writefile, " %s |", studntlist->etud_info.prenom);
      if(studntlist->etud_info.genre == 1)
         fprintf( writefile, " Femme |");
      else
         fprintf( writefile, " Homme |");
      switch(studntlist->etud_info.filiere){
         case 1:
            fprintf( writefile, " SMI |");
            break;
         case 2:
            fprintf( writefile, " SMA |");
            break;
         case 3:
            fprintf( writefile, " SMP |");
            break;
         case 4:
            fprintf( writefile, " SMC |");
            break;
         case 5:
            fprintf( writefile, " SVI |");
            break;
         case 6:
            fprintf( writefile, " STU |");
            break;
      }  
      fprintf( writefile, " %02u/%02d/%04u |", studntlist->etud_info.date_inscription.jour, studntlist->etud_info.date_inscription.mois, studntlist->etud_info.date_inscription.annee);
      fprintf( writefile, " %02u/%02d/%04u |", studntlist->etud_info.graduation_date.jour, studntlist->etud_info.graduation_date.mois, studntlist->etud_info.graduation_date.annee);
      fprintf( writefile, " %s |", studntlist->etud_info.academic_email);
      for(i = 0; i<7; i++){
         fprintf( writefile, " %s |", studntlist->etud_info.modules[i].module_name);
         fprintf( writefile, " %.4f |", studntlist->etud_info.modules[i].module_note);
      }
      fprintf( writefile, " %.4f |\n", studntlist->etud_info.moy);
      fdraw_line(writefile, tabw);
      studntlist = studntlist->suiv; n++;
   }
   entryls = n;
}

void create(char *filename, etudiant *studntlist){
    char name[strlen(filename) + 4];
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

void readfile(char *filename, boolean echototerm, etudiant *list, boolean import){
    char name[strlen(filename) + 4], line[MAX_SIZE] = "";
    snprintf( name, sizeof(name), "%s.txt", filename);
    etudiant *new_etudiant= (etudiant *) malloc(sizeof(etudiant));
    etudiant *p = new_etudiant;

    entryls = 0;
    FILE *file = fopen(name, "r");
    if(file != NULL){
        while(fgets(line, MAX_SIZE, file) != NULL){
            if(echototerm) printf("%s", line);
            if((!(entryls % 2)) && entryls != 0 && import){
                fscanf(file, "| %d |    %d    |      %s      |      %s      |  %d  | %d | %u/%d/%u | %u/%d/%u |     %s     |    %s    | %f |   %s   | %f |   %s    | %f |    %s   | %f |  %s   | %f |    %s    | %f |    %s    | %f | %f |\n"
                , &entryls //Dirty fix
                , &new_etudiant->etud_info.apogee, new_etudiant->etud_info.nom, new_etudiant->etud_info.prenom, (int *)&new_etudiant->etud_info.genre, (int *)&new_etudiant->etud_info.filiere
                , &new_etudiant->etud_info.date_inscription.jour, (int *)&new_etudiant->etud_info.date_inscription.mois, &new_etudiant->etud_info.date_inscription.annee
                , &new_etudiant->etud_info.graduation_date.jour, (int *)&new_etudiant->etud_info.graduation_date.mois, &new_etudiant->etud_info.graduation_date.annee
                , new_etudiant->etud_info.academic_email
                , new_etudiant->etud_info.modules[0].module_name,&new_etudiant->etud_info.modules[0].module_note
                , new_etudiant->etud_info.modules[1].module_name,&new_etudiant->etud_info.modules[1].module_note
                , new_etudiant->etud_info.modules[2].module_name,&new_etudiant->etud_info.modules[2].module_note
                , new_etudiant->etud_info.modules[3].module_name,&new_etudiant->etud_info.modules[3].module_note
                , new_etudiant->etud_info.modules[4].module_name,&new_etudiant->etud_info.modules[4].module_note
                , new_etudiant->etud_info.modules[5].module_name,&new_etudiant->etud_info.modules[5].module_note
                , new_etudiant->etud_info.modules[6].module_name,&new_etudiant->etud_info.modules[6].module_note
                , &new_etudiant->etud_info.moy);

                for(int i = 0; i<7; i++){
                    if(!strncmp(new_etudiant->etud_info.modules[i].module_name, "NaN", 3)){
                        new_etudiant->etud_info.moy = i; break;
                    }
                }

                new_etudiant->suiv = (etudiant *) malloc(sizeof(etudiant));
                new_etudiant = new_etudiant->suiv;
            }
            entryls++;
        }
        if(import){
            free(new_etudiant);
            list = p;
        }
        fclose(file);
    }
}

void modfile(char *filename, etudiant *studntlist){
    readfile(filename, 0, NULL, 0);

    etudiant *tmplist = studntlist;
    char name[strlen(filename) + 4], line[MAX_SIZE] = "";
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

    fclose(file);
}