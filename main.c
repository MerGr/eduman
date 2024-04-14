#include <stdio.h>
#include <stdlib.h>
#include "srchfuncs.h"
#include "eduStruct.h"
#include "filemanip.h"
#include "tui.h"
#include "modedu.h"

int main(){
   etudiant *student_list, *srchtarget, *head, *sortd;
   char *srchstr[50];
   unsigned short option[3]; 
   unsigned int apo, edunum;
   date targetdate;
   e_filiere targetfil;

   menu(option);

   switch(option[0]){
      case 1:   //Mode Interactive
         switch (option[1]){
            case 6: //Supprimer Etudiant
               if(student_list){
                  printf("Numero Apogee d'etudiant : ");
                  scanf("%u", &apo);
                  student_list = delete_etud(student_list, apo);
                  if(!student_list) printf("Erreur !\n");
                  else printf("Etudiant Code Apogee %u supprime !\n", apo);

                  break;
               }
            case 5: //Rechercher
               if(student_list){
                  option[3] = searchselect();
                  switch (option[3]){
                     case 1:
                        printf("Numero Apogee d'etudiant : ");
                        scanf("%u", &apo);
                        srchtarget = searchoneByApo(student_list, apo)
                        if(!srchtarget) printf("%u pas trouve !\n", apo);
                        else draw_student(srchtarget.etud_info);

                        break;
                     case 2:
                        printf("Nom a chercher : "); scanf("%s", srchstr);
                        srchtarget = srchByNom(student_list, srchstr);
                        if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                        else draw_table(srchtarget);

                        break;
                     case 3:
                        printf("Prenom a chercher : "); scanf("%s", srchstr);
                        srchtarget = srchByPrenom(student_list, srchstr);
                        if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                        else draw_table(srchtarget);

                        break;
                     case 4:
                        printf("Date inscription a chercher (format : DD/MM/YYYY) : ");
                        scanf("%u/%d/%u", &targetdate.jour, &targetdate.mois, &targetdate.annee);
                        srchtarget = srchByDate(student_list, targetdate);
                        if(!srchtarget) printf("Date pas trouve!\n");
                        else draw_table(srchtarget);

                        break;
                  }

                  break;
               }
            case 4: //Tri
               if(student_list){
                  option[3]=sortselect();
                  switch (option[3]){
                     case 1:
                        student_list = triParApo(student_list);
                        draw_table(student_list);

                        break;
                     case 2:
                        student_list = triParMoy(student_list);
                        draw_table(student_list);

                        break;
                     case 3:
                        student_list = triParDate(student_list);
                        draw_table(student_list);

                        break;
                  }

                  break;
               }
            case 3: //Consultation
               if(student_list){
                  option[3]=viewselect();
                  switch (option[3]){
                     case 1:
                        draw_table(student_list);
                        break;
                     case 2:
                        sortd = validlist(student_list);
                        if(!sortd) printf("Aucun etudiant dans la liste est admit !\n");
                        else draw_table(sortd);

                        break;
                     case 3:
                        targetfil = filselect(student_list);
                        sortd = filierelist(student_list, targetfil);
                        if(!sortd) printf("Aucun etudiant dans la filiere specifie a ete trouve !\n");
                        else draw_table(sortd);

                        break;
                  }

                  break;
               }
            case 2: //Modification
               if(student_list){
                  printf("Numero Apogee d'etudiant : ");
                  scanf("%u", &apo);
                  student_list = modifier_etud_info(student_list, (int)apo);
                  printf("Nouvelle Liste :\n");
                  draw_table(student_list);
               }

               break;
            case 1: //Creation
               printf("Nombre d'etudiants : ");
               scanf("%u", &edunum);
               for(int i = 1; i<=edunum; i++){
                  student_list = ajout_fin(student_list);
               }

               break;
            case 0: //Retour
               menu();
         } break;
      
      case 2: //Mode fichiers
         FILE *mainlistfile;
         mainlistfile = fopen("list.txt", r);
         if(ferror(mainlistfile)) printf("Fichier list.txt introuvable ! Veuillez creer une base de donnees !\n"); 
         else readfile("list", 0, student_list, 1);
         switch(option[1]){
            case 6: //Supprimer Etudiant
               if(student_list){
                  printf("Numero Apogee d'etudiant : ");
                  scanf("%u", &apo);
                  student_list = delete_etud(student_list, apo);
                  if(!student_list) printf("Erreur !\n");
                  else { 
                     printf("Etudiant Code Apogee %u supprime !\n", apo);
                     create("StudentList", student_list);
                  }
                  break;
               }
            case 5: //Rechercher
               if(student_list){
                  option[3] = searchselect();
                  switch (option[3]){
                     case 1:
                        printf("Numero Apogee d'etudiant : ");
                        scanf("%u", &apo);
                        srchtarget = searchoneByApo(student_list, apo)
                        if(!srchtarget) printf("%u pas trouve !\n", apo);
                        else{
                           itoa((int) apo, srchstr, 70);
                           create(srchstr, srchtarget);
                           printf("%u.txt cree\n", apo);
                        }
                        break;
                     case 2:
                        printf("Nom a chercher : "); scanf("%s", srchstr);
                        srchtarget = srchByNom(student_list, srchstr);
                        if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                        else{
                           create(srchstr, srchtarget);
                           printf("%s.txt cree\n", srchstr);
                        }

                        break;
                     case 3:
                        printf("Prenom a chercher : "); scanf("%s", srchstr);
                        srchtarget = srchByPrenom(student_list, srchstr);
                        if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                        else{
                           create(srchstr, srchtarget);
                           printf("%s.txt cree\n", srchstr);
                        }
                        break;
                     case 4:
                        printf("Date inscription a chercher (format : DD/MM/YYYY) : ");
                        scanf("%u/%d/%u", &targetdate.jour, &targetdate.mois, &targetdate.annee);
                        srchtarget = srchByDate(student_list, targetdate);
                        if(!srchtarget) printf("Date pas trouve!\n");
                        else{
                           snprintf(srchstr, 50, "%02u/%02d/%04u", targetdate.jour, targetdate.mois, targetdate.annee);
                           create(srchstr, srchtarget);
                           printf("%s.txt cree\n");
                        }
                        break;
                  }

                  break;
               }
            case 4: //Tri
               if(student_list){
                  option[3]=sortselect();
                  switch (option[3]){
                     case 1:
                        student_list = triParApo(student_list);
                        create("TriParApo", student_list);
                        printf("TriParApo.txt cree!\n");

                        break;
                     case 2:
                        student_list = triParMoy(student_list);
                        create("TriParMoy", student_list);
                        printf("TriParMoy.txt cree!\n");

                        break;
                     case 3:
                        student_list = triParDate(student_list);
                        create("TriParDate", student_list);
                        printf("TriParDate.txt cree!\n");

                        break;
                  }

                  break;
               }
            case 3: //Consultation
               if(student_list){
                  option[3]=viewselect();
                  switch (option[3]){
                     case 1:
                        readfile("list", 1, NULL, 0);
                        break;
                     case 2:
                        sortd = validlist(student_list);
                        if(!sortd) printf("Aucun etudiant dans la liste est admit !\n");
                        else{
                           create("list_admis", sortd);
                           readfile("list_admis", 1, NULL, 0);
                        }
                        break;
                     case 3:
                        targetfil = filselect(student_list);
                        sortd = filierelist(student_list, targetfil);
                        if(!sortd) printf("Aucun etudiant dans la filiere specifie a ete trouve !\n");
                        else{
                           switch(targetfil){
                              case 1:
                                 create("list_SMI", sortd);
                                 readfile("list_SMI", 1, NULL, 0);
                                 break;
                              case 2:
                                 create("list_SMA", sortd);
                                 readfile("list_SMA", 1, NULL, 0);
                                 break;
                              case 3:
                                 create("list_SMP", sortd);
                                 readfile("list_SMP", 1, NULL, 0);
                                 break;
                              case 4:
                                 create("list_SMC", sortd);
                                 readfile("list_SMC", 1, NULL, 0);
                                 break;
                              case 5:
                                 create("list_SVI", sortd);
                                 readfile("list_SVI", 1, NULL, 0);
                                 break;
                              case 6:
                                 create("list_STU", sortd);
                                 readfile("list_STU", 1, NULL, 0);
                                 break;
                           }
                        }

                        break;
                  }

                  break;
               }
            case 2: //Modification
               if(student_list){
                  modfile("list", student_list);
                  readline("list", 1, NULL, 0);
               }

               break;
            case 1: //Creation

               printf("Nombre d'etudiants : ");
               scanf("%u", &edunum);
               for(int i = 1; i<=edunum; i++){
                  student_list = ajout_fin(student_list);
               }
               create("list", student_list);
               printf("list.txt cree avec succes!\n")
               break;
            case 0: //Retour
               menu();
         } break;
   }
   return 0;
}
