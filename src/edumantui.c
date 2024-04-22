#include <stdio.h>
#include <string.h>
#include "eduStruct.h"
#include "tui.h"
#include "srchfuncs.h"

extern boolean firstrun;

void draw_student(etudiant_info *etud, int entryls){
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\t\t\t\tEtudiant %d\n", entryls);
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\tApogee\t\t\t\t\t%d\t\t\n", etud->apogee);
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\tNom et Prenom\t\t\t%s %s\t\t\n",etud->nom,etud->prenom);
   printf("+----------------------------------+---------------------------------+\n");
   if(etud->genre == 1)
      printf("|\tGenre\t\t\t\t\tFemme\t\t\n");
   else
      printf("|\tGenre\t\t\t\t\tHomme\t\t\n");
   printf("+----------------------------------+---------------------------------+\n");
   switch(etud->filiere){
      case 1:
         printf("|\tFiliere\t\t\t\t\tSMI\t\t\n");
         break;
      case 2:
         printf("|\tFiliere\t\t\t\t\tSMA\t\t\n");
         break;
      case 3:
         printf("|\tFiliere\t\t\t\t\tSMP\t\t\n");
         break;
      case 4:
         printf("|\tFiliere\t\t\t\t\tSMC\t\t\n");
         break;
      case 5:
         printf("|\tFiliere\t\t\t\t\tSVI\t\t\n");
         break;
      case 6:
         printf("|\tFiliere\t\t\t\t\tSTU\t\t\n");
         break;
   }
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\tDate d'inscription\t\t%02u/%02d/%04u\t\t\n",etud->date_inscription.jour,(int)etud->date_inscription.mois,etud->date_inscription.annee);
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\tDate de graduation\t\t%02u/%02d/%04u\t\t\n",etud->graduation_date.jour,(int)etud->graduation_date.mois,etud->graduation_date.annee);
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\tEmail Academique\t\t%s\t\t\n", etud->academic_email);
   printf("+----------------------------------+---------------------------------+\n");
   printf("|\tNom du module\t\t\t\tNote du module\t\t\n");
   printf("+----------------------------------+---------------------------------+\n");
   for(int i=0; i<7; i++){
      printf("|\t%s\t\t\t\t%.4f\t\t\n", etud->modules[i].module_name, etud->modules[i].module_note);
      printf("+----------------------------------+---------------------------------+\n");
   }
   printf("|\tMoyenne\t\t\t\t\t%.04f\t\t\n", etud->moy);
   printf("+----------------------------------+---------------------------------+\n");
   printf("+----------------------------------+---------------------------------+\n");
}

void draw_table(etudiant *stdntlist){
   etudiant *p = stdntlist;
   int n = 1;
   do{
      draw_student(&p->etud_info, n);
      n++;
      if(p->suiv) p = p->suiv;
   }while(p->suiv != NULL);
}


void menu_one(int *out){
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
      "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%d", &out[0]);
   } while(out[0] > 2 || out[0] <= 0);
}

void menu_two(int *out){
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
      "     **          0- Quitter                                                                   **         \n"
      "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%d", &out[1]);
   } while(out[1] > 6 || out[1] < 0);
}

int searchselect(){
   int out;
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
      printf("Votre choix : "); scanf("%d", &out);
   } while(out > 4 || out <= 0);

   return out;
}

int sortselect(){
   int out;
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
      printf("Votre choix : "); scanf("%d", &out);
   } while(out > 3 || out <= 0);

   return out;
}

int viewselect(){
   int out;
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
      printf("Votre choix : "); scanf("%d", &out);
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

int modselect(){
   int out;
   do{
      puts(
         "     *******************************************************************************************         \n"
         "     **                                 Modification                                          **         \n"
         "     **                            Choisir votre operation :                                  **         \n"
         "     **                                                                                       **         \n"
         "     **          1- Modifier les entrees existantes                                           **         \n"
         "     **          2- Ajouter une entree                                                        **         \n"
         "     **                                                                                       **         \n"
         "     *******************************************************************************************         \n"
      );
      printf("Votre choix : "); scanf("%d", &out);
   } while(out > 2 || out <= 0);

   return out;
}