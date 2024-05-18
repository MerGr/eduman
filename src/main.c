//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
#include <stdio.h>
#include <stdlib.h>
#include "srchfuncs.h"
#include "eduStruct.h"
#include "filemanip.h"
#include "tui.h"
#include "modfuncs.h"
#include "ajoutfuncs.h"
#include "delfuncs.h"
#include "sortfuncs.h"

int main(){
   etudiant *student_list, *srchtarget, *sortd;
   char srchstr[50];
   int apo, edunum, option[3];
   date targetdate;
   e_filiere targetfil;

   student_list = NULL;

   boolean firstrun = 1;

   FILE *mainlistfile;

   menu_one(option);
   
   do{
      
      switch(option[0]){
         case 1:   //Mode Interactive
            if(firstrun){
               firstrun = 0;
               option[1] = 1;
            } else {
               menu_two(option);
            }
            switch (option[1]){
               case 6: //Supprimer Etudiant
                  if(student_list){
                     printf("Numero Apogee d'etudiant : ");
                     scanf("%d", &apo);
                     delete_etud(&student_list, apo);

                     break;
                  }

                  break;
               case 5: //Rechercher
                  if(student_list){ 
                     option[2] = searchselect();
                     switch (option[2]){
                        case 1:
                           printf("Numero Apogee d'etudiant : ");
                           scanf("%d", &apo);
                           srchtarget = searchoneByApo(student_list, apo);
                           if(!srchtarget) {printf("%d pas trouve !\n", apo);}
                           else {draw_student(&srchtarget->etud_info, 1);}

                           break;
                        case 2:
                           printf("Nom a chercher : "); scanf("%[^\n]s", srchstr);
                           srchtarget = srchByNom(student_list, srchstr);
                           if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                           else draw_table(srchtarget);

                           break;
                        case 3:
                           printf("Prenom a chercher : "); scanf("%[^\n]s", srchstr);
                           srchtarget = srchByPrenom(student_list, srchstr);
                           if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                           else draw_table(srchtarget);

                           break;
                        case 4:
                           printf("Date inscription a chercher (format : DD/MM/YYYY) : ");
                           scanf("%u/%d/%u", &targetdate.jour, (int *)&targetdate.mois, &targetdate.annee);
                           srchtarget = srchByDate(student_list, targetdate);
                           if(!srchtarget) printf("Date pas trouve!\n");
                           else draw_table(srchtarget);

                           break;
                     }
                  }

                  break;
               case 4: //Tri
                  if(student_list){ 
                     option[2]=sortselect();
                     switch (option[2]){
                        case 1:
                           student_list = sort_apogee(student_list);
                           draw_table(student_list);

                           break;
                        case 2:
                           student_list = sort_moy(student_list);
                           draw_table(student_list);

                           break;
                        case 3:
                           student_list = sort_date_inscription(student_list);
                           draw_table(student_list);

                           break;
                     }
                  }

                  break;
               case 3: //Consultation
                  if(student_list){ 
                     option[2]=viewselect();
                     switch (option[2]){
                        case 1:
                           draw_table(student_list);
                           break;
                        case 2:
                           sortd = validlist(student_list);
                           if(!sortd) printf("Aucun etudiant dans la liste est admit !\n");
                           else draw_table(sortd);

                           break;
                        case 3:
                           targetfil = filselect();
                           sortd = filierelist(student_list, targetfil);
                           if(!sortd) printf("Aucun etudiant dans la filiere specifie a ete trouve !\n");
                           else draw_table(sortd);

                           break;
                     }
                  }

                  break;
               case 2: //Modification
                  if(student_list){ 
                     option[2]=modselect();
                     switch (option[2]){
                        case 1:
                           printf("Numero Apogee d'etudiant : ");
                           scanf("%d", &apo);
                           student_list = modifier_etud_info(student_list, (int)apo);
                           break;
                        case 2:
                           do{
                              printf("Nombre d'etudiants : ");
                              scanf("%d", &edunum);
                           } while(edunum < 0);
                           for(int i = 0; i<edunum; i++){
                              ajout_fin(&student_list);
                           }
                           //TODO : this is horrible, this doesn't work, must be fixed
                        }
                     printf("Nouvelle Liste :\n");
                     draw_table(student_list);
                     break;
                  }

                  break;
               case 1: //Creation
                  printf("Nombre d'etudiants : ");
                  scanf("%d", &edunum);
                  if(student_list) free_list(&student_list);
                  for(int i = 0; i<edunum; i++)
                        ajout(&student_list);
                  draw_table(student_list);
                  break;
               case 0: //Quitter
                  break;
            } break;

         case 2: //Mode fichiers
            if(firstrun == 1){
               mainlistfile = fopen("list.csv", "r");
               if(mainlistfile == NULL) {
                  option[1] = 1;
                  printf("Fichier list.csv introuvable ! Veuillez creer une base de donnees !\n");
                  fclose(mainlistfile);
               }
               else {
                  fclose(mainlistfile);
                  if(!student_list) readfile("list", 1, &student_list);
                  printf("list.csv importe !\n");
                  menu_two(option);
               }
               firstrun = 0;
            } else {
               menu_two(option);
            }
            switch(option[1]){
               case 6: //Supprimer Etudiant
                  if(student_list){ 
                     printf("Numero Apogee d'etudiant : ");
                     scanf("%d", &apo);
                     delete_etud(&student_list, apo);
                     create("list", student_list);
                     readfile("list", 1, &student_list);
                     break;
                  }

                  break;
               case 5: //Rechercher
                  if(student_list){ 
                     option[2] = searchselect();
                     switch (option[2]){
                        case 1:
                           printf("Numero Apogee d'etudiant : ");
                           scanf("%d", &apo);
                           srchtarget = searchoneByApo(student_list, apo);
                           if(!(srchtarget)) {printf("%d pas trouve !\n", apo);}
                           else{
                              snprintf(srchstr, 50, "%d", apo);
                              create(srchstr, srchtarget);
                              printf("%d.csv cree\n", apo);
                           }
                           break;
                        case 2:
                           printf("Nom a chercher : "); scanf(" %s", srchstr);
                           srchtarget = srchByNom(student_list, srchstr);
                           if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                           else{
                              create(srchstr, srchtarget);
                              printf("%s.csv cree\n", srchstr);
                           }

                           break;
                        case 3:
                           printf("Prenom a chercher : "); scanf(" %s", srchstr);
                           srchtarget = srchByPrenom(student_list, srchstr);
                           if(!srchtarget) printf("%s pas trouve!\n", srchstr);
                           else{
                              create(srchstr, srchtarget);
                              printf("%s.csv cree\n", srchstr);
                           }
                           break;
                        case 4:
                           printf("Date inscription a chercher (format : DD/MM/YYYY) : ");
                           scanf("%u/%d/%u", &targetdate.jour, (int *)&targetdate.mois, &targetdate.annee);
                           srchtarget = srchByDate(student_list, targetdate);
                           if(!srchtarget) printf("Date pas trouve!\n");
                           else{
                              snprintf(srchstr, 50, "%02u-%02d-%04u", targetdate.jour, targetdate.mois, targetdate.annee);
                              create(srchstr, srchtarget);
                              printf("%s.csv cree\n", srchstr);
                           }
                           break;
                     }
                  }

                  break;
               case 4: //Tri
                  if(student_list){ 
                     option[2]=sortselect();
                     switch (option[2]){
                        case 1:
                           student_list = sort_apogee(student_list);
                           create("TriParApo", student_list);
                           printf("TriParApo.csv cree!\n");

                           break;
                        case 2:
                           student_list = sort_moy(student_list);
                           create("TriParMoy", student_list);
                           printf("TriParMoy.csv cree!\n");

                           break;
                        case 3:
                           student_list = sort_date_inscription(student_list);
                           create("TriParDate", student_list);
                           printf("TriParDate.csv cree!\n");

                           break;
                     }
                  }

                  break;
               case 3: //Consultation
                  if(student_list){ 
                     option[2]=viewselect();
                     switch (option[2]){
                        case 1:
                           readfile("list", 1, &student_list);
                           break;
                        case 2:
                           sortd = validlist(student_list);
                           if(!sortd) printf("Aucun etudiant dans la liste est admit !\n");
                           else{
                              create("list_admis", sortd);
                              readfile("list_admis", 1, &sortd);
                           }
                           break;
                        case 3:
                           targetfil = filselect();
                           sortd = filierelist(student_list, targetfil);
                           if(!sortd) printf("Aucun etudiant dans la filiere specifie a ete trouve !\n");
                           else{
                              switch(targetfil){
                                 case 1:
                                    create("list_SMI", sortd);
                                    readfile("list_SMI", 1, &sortd);
                                    break;
                                 case 2:
                                    create("list_SMA", sortd);
                                    readfile("list_SMA", 1, &sortd);
                                    break;
                                 case 3:
                                    create("list_SMP", sortd);
                                    readfile("list_SMP", 1, &sortd);
                                    break;
                                 case 4:
                                    create("list_SMC", sortd);
                                    readfile("list_SMC", 1, &sortd);
                                    break;
                                 case 5:
                                    create("list_SVI", sortd);
                                    readfile("list_SVI", 1, &sortd);
                                    break;
                                 case 6:
                                    create("list_STU", sortd);
                                    readfile("list_STU", 1, &sortd);
                                    break;
                              }
                           }

                           break;
                     }
                  }

                  break;
               case 2: //Modification
                  if(student_list){
                     option[2]=modselect();
                     switch (option[2]){
                        case 1: //Modifier
                           modfile("list", student_list);
                           break;
                        case 2: //Ajouter
                           do{
                              printf("Nombre d'etudiants : ");
                              scanf("%d", &edunum);
                           } while(edunum < 0);
                           for(int i=0; i<edunum; i++)
                                 ajout_fin(&student_list);
                           create("list", student_list);
                           printf("list.csv cree avec succes!\n");
                        }
                     printf("Nouvelle Liste :\n");
                     readfile("list", 1, &student_list);
                     break;
                  }

                  break;
               case 1: //Creation
                     printf("Nombre d'etudiants : ");
                     scanf("%d", &edunum);
                     if(student_list) free_list(&student_list);
                     for(int i = 0; i<edunum; i++)
                              ajout(&student_list);
                     create("list", student_list);
                     readfile("list", 1, &student_list);
                     printf("list.csv cree avec succes!\n");

                  break;
               case 0: //Retour
                  break;
               default:
                  printf("ERREUR ! BASE DE DONNEES NON EXISTANTE");
                  menu_two(option);
            } break;
      }
      
   } while(option[1] != 0);

   if(student_list) free_list(&student_list);
   return 0;
}
