#include <stdio.h>
#include <string.h>
#include "eduStruct.h"
#include "tui.h"
#include "srchfuncs.h"

void draw_line(int w){
   for(int i = 0; i <=w; i++)
      printf("-");
   printf("\n");
}

void draw_table(etudiant *studntlist){
   int n, i, tabw = strlen("|  |    Apogee    |      Nom      |      Prenom      |  Genre  | Filiere | date d'inscription | date de graduation |     Email Academique     |    Module 1    | Note 1 |   Module 2   | Note 2 |   Module 3    | Note 3 |    Module 4   | Note 4 |  Module 5   | Note 5 |    Module 6    | Note 6 |    Module 7    | Note 7 | Moyenne |");
   draw_line(tabw);
   printf("|  |    Apogee    |      Nom      |      Prenom      |  Genre  | Filiere | date d'inscription | date de graduation |     Email Academique     |    Module 1    | Note 1 |   Module 2   | Note 2 |   Module 3    | Note 3 |    Module 4   | Note 4 |  Module 5   | Note 5 |    Module 6    | Note 6 |    Module 7    | Note 7 | Moyenne |\n");
   draw_line(tabw);
   n = 1;
   while(studntlist != NULL){
      printf("| %u |", n);
      printf(" %u |", studntlist->etud_info.apogee);
      printf(" %s |", studntlist->etud_info.nom);
      printf(" %s |", studntlist->etud_info.prenom);
      if(studntlist->etud_info.genre == 1)
         printf(" Femme |");
      else
         printf(" Homme |");
      printf(" %02u/%02d/%04u |", studntlist->etud_info.date_inscription.jour, studntlist->etud_info.date_inscription.mois, studntlist->etud_info.date_inscription.annee);
      printf(" %02u/%02d/%04u |", studntlist->etud_info.graduation_date.jour, studntlist->etud_info.graduation_date.mois, studntlist->etud_info.graduation_date.annee);
      printf(" %s |", studntlist->etud_info.academic_email);
      for(i = 0; i<studntlist->etud_info.num_of_modules; i++){
         printf(" %s |", studntlist->etud_info.modules[i].module_name);
         printf(" %.4f |", studntlist->etud_info.modules[i].module_note);
      }
      for(int j = i; j < 7; j++){
         printf("                |        |");
      }
      printf(" %.4f |\n", studntlist->etud_info.moy);
      draw_line(tabw);
      studntlist = studntlist->suiv; n++;
   }
}

void draw_student(etudiant_info *studnt){
   int n, i, tabw = strlen("|  | Apogee |      Nom      |      Prenom      | Genre | Filiere | date d'inscription | date de graduation |     Email Academique     |    Module 1    | Note 1 |   Module 2   | Note 2 |   Module 3    | Note 3 |    Module 4   | Note 4 |  Module 5   | Note 5 |    Module 6    | Note 6 |    Module 7    | Note 7 | Moyenne |");
   draw_line(tabw);
   printf("|  | Apogee |      Nom      |      Prenom      | Genre | Filiere | date d'inscription | date de graduation |     Email Academique     |    Module 1    | Note 1 |   Module 2   | Note 2 |   Module 3    | Note 3 |    Module 4   | Note 4 |  Module 5   | Note 5 |    Module 6    | Note 6 |    Module 7    | Note 7 | Moyenne |\n");
   draw_line(tabw);
   n = 1;
   while(studnt != NULL){
      printf("| %u |", n);
      printf(" %u |", studnt->apogee);
      printf(" %s |", studnt->nom);
      printf(" %s |", studnt->prenom);
      if(studnt->genre == 1)
         printf(" Femme |");
      else
         printf(" Homme |");
      switch(studnt->filiere){
         case 1:
            printf(" SMI |");
            break;
         case 2:
            printf(" SMA |");
            break;
         case 3:
            printf(" SMP |");
            break;
         case 4:
            printf(" SMC |");
            break;
         case 5:
            printf(" SVI |");
            break;
         case 6:
            printf(" STU |");
            break;
      }
      printf(" %02u/%02d/%04u |", studnt->date_inscription.jour, studnt->date_inscription.mois, studnt->date_inscription.annee);
      printf(" %02u/%02d/%04u |", studnt->graduation_date.jour, studnt->graduation_date.mois, studnt->graduation_date.annee);
      printf(" %s |", studnt->academic_email);
      for(i = 0; i<7; i++){
         printf(" %s |", studnt->modules[i].module_name);
         printf(" %.4f |", studnt->modules[i].module_note);
      }
      printf(" %.4f |\n", studnt->moy);
      draw_line(tabw);
   }
}


void menu(unsigned int *out){
   memset(out, 0, 3*sizeof(int));
   do{
      puts(
      "                                                                                                                           \n\n"
      "           _          _          _                  _   _         _                   _                                      \n"
      "          /\\ \\       /\\ \\       /\\_\\               /\\_\\/\\_\\ _    / /\\                /\\ \\     _                 \n"
      "         /  \\ \\     /  \\ \\____ / / /         _    / / / / //\\_\\ / /  \\              /  \\ \\   /\\_\\                 \n"
      "        / /\\ \\ \\   / /\\ \\_____\\\\ \\ \\__      /\\_\\ /\\ \\/ \\ \\/ / // / /\\ \\            / /\\ \\ \\_/ / /        \n"
      "       / / /\\ \\_\\ / / /\\/___  / \\ \\___\\    / / //  \\____\\__/ // / /\\ \\ \\          / / /\\ \\___/ /               \n"
      "      / /_/_ \\/_// / /   / / /   \\__  /   / / // /\\/________// / /  \\ \\ \\        / / /  \\/____/                       \n"
      "     / /____/\\  / / /   / / /    / / /   / / // / /\\/_// / // / /___/ /\\ \\      / / /    / / /                           \n"
      "    / /\\____\\/ / / /   / / /    / / /   / / // / /    / / // / /_____/ /\\ \\    / / /    / / /                            \n" 
      "   / / /______ \\ \\ \\__/ / /    / / /___/ / // / /    / / // /_________/\\ \\ \\  / / /    / / /                           \n"
      "  / / /_______\\ \\ \\___\\/ /    / / /____\\/ / \\/_/    / / // / /_       __\\ \\_\\/ / /    / / /                         \n"
      "  \\/__________/  \\/_____/     \\/_________/          \\/_/ \\_\\___\\     /____/_/\\/_/     \\/_/                      \n\n\n"                                                                                                           
      "     *******************************************************************************************         \n"
      "     **                              Bienvenue a Eduman !                                     **         \n"
      "     **                              Choisir votre mode :                                     **         \n"
      "     **                                                                                       **         \n"
      "     **          1- Mode Interactif (ATTENTION ! Sans Sauvegarde)                             **         \n"
      "     **          2- Mode manipulation des fichiers                                            **         \n"
      "     **                                                                                       **         \n"
      "     **          3- Quitter                                                                   **         \n"
      "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%u", &out[0]);
   } while(out[0] > 3 || out[0] <= 0);
   if(out[0] != 3){
      do{
         puts(
         "                                                                                                                           \n\n"
         "           _          _          _                  _   _         _                   _                                      \n"
         "          /\\ \\       /\\ \\       /\\_\\               /\\_\\/\\_\\ _    / /\\                /\\ \\     _                 \n"
         "         /  \\ \\     /  \\ \\____ / / /         _    / / / / //\\_\\ / /  \\              /  \\ \\   /\\_\\                 \n"
         "        / /\\ \\ \\   / /\\ \\_____\\\\ \\ \\__      /\\_\\ /\\ \\/ \\ \\/ / // / /\\ \\            / /\\ \\ \\_/ / /        \n"
         "       / / /\\ \\_\\ / / /\\/___  / \\ \\___\\    / / //  \\____\\__/ // / /\\ \\ \\          / / /\\ \\___/ /               \n"
         "      / /_/_ \\/_// / /   / / /   \\__  /   / / // /\\/________// / /  \\ \\ \\        / / /  \\/____/                       \n"
         "     / /____/\\  / / /   / / /    / / /   / / // / /\\/_// / // / /___/ /\\ \\      / / /    / / /                           \n"
         "    / /\\____\\/ / / /   / / /    / / /   / / // / /    / / // / /_____/ /\\ \\    / / /    / / /                            \n" 
         "   / / /______ \\ \\ \\__/ / /    / / /___/ / // / /    / / // /_________/\\ \\ \\  / / /    / / /                           \n"
         "  / / /_______\\ \\ \\___\\/ /    / / /____\\/ / \\/_/    / / // / /_       __\\ \\_\\/ / /    / / /                         \n"
         "  \\/__________/  \\/_____/     \\/_________/          \\/_/ \\_\\___\\     /____/_/\\/_/     \\/_/                      \n\n\n"                                                                                                           
         "     *******************************************************************************************         \n"
         "     **                              Bienvenue a Eduman !                                     **         \n"
         "     **                            Choisir votre operation :                                  **         \n"
         "     **                                                                                       **         \n"
         "     **          1- Creer une base de donnees                                                 **         \n"
         "     **          2- Modifier la base                                                          **         \n"
         "     **          3- Consulter la base                                                         **         \n"
         "     **          4- Trier la base                                                             **         \n"
         "     **          5- Rechercher dans la base                                                   **         \n"
         "     **          6- Supprimer un etudiant                                                     **         \n"
         "     **                                                                                       **         \n"
         "     **          0- Retour                                                                    **         \n"
         "     *******************************************************************************************         \n"
         );
         printf("Votre choix : "); scanf("%u", &out[1]);
      } while(out[1] > 6 || out[1] < 0);
   }
}

unsigned int searchselect(){
   unsigned int out;
   do{
      puts(
         "     *******************************************************************************************         \n"
         "     **                                  Recherche                                            **         \n"
         "     **                            Choisir votre operation :                                  **         \n"
         "     **                                                                                       **         \n"
         "     **          1- Rechercher un etudiant par code apogee                                    **         \n"
         "     **          2- Rechercher par Nom                                                        **         \n"
         "     **          3- Rechercher par Prenom                                                     **         \n"
         "     **          4- Rechercher par Date d'inscription                                         **         \n"
         "     **                                                                                       **         \n"
         "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%u", &out);
   } while(out > 4 || out <= 0);

   return out;
}

unsigned int sortselect(){
   unsigned int out;
   do{
      puts(
         "     *******************************************************************************************         \n"
         "     **                                     Tri                                               **         \n"
         "     **                            Choisir votre operation :                                  **         \n"
         "     **                                                                                       **         \n"
         "     **          1- Tri par Code Apogee                                                       **         \n"
         "     **          2- Tri par Moyenne                                                           **         \n"
         "     **          3- Tri par Date d'inscription                                                **         \n"
         "     **                                                                                       **         \n"
         "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%u", &out);
   } while(out > 3 || out <= 0);

   return out;
}

unsigned int viewselect(){
   unsigned int out;
   do{
      puts(
         "     *******************************************************************************************         \n"
         "     **                                 Consultation                                          **         \n"
         "     **                            Choisir votre operation :                                  **         \n"
         "     **                                                                                       **         \n"
         "     **          1- Consulter tous les etudiants                                              **         \n"
         "     **          2- Consulter tous les etudiants admis                                        **         \n"
         "     **          3- Consulter tous les etudiants d'une filiere                                **         \n"
         "     **                                                                                       **         \n"
         "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%u", &out);
   } while(out > 3 || out <= 0);

   return out;
}

e_filiere filselect(){
   e_filiere out;
   do{
      puts(
         "     *******************************************************************************************         \n"
         "     **                                Consultation                                           **         \n"
         "     **                              Choisir la filiere :                                     **         \n"
         "     **                                                                                       **         \n"
         "     **          1- SMI                                                                       **         \n"
         "     **          2- SMA                                                                       **         \n"
         "     **          3- SMP                                                                       **         \n"
         "     **          4- SMC                                                                       **         \n"
         "     **          5- SVI                                                                       **         \n"
         "     **          6- STU                                                                       **         \n"
         "     **                                                                                       **         \n"
         "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%d", (int *)&out);
   } while(out > 6 || out <= 0);

   return out;
}