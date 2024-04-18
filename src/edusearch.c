/****************************************
 *                edusearch.c
 *    Search etudiant by name/enrolldate
 * **************************************/

#include "srchfuncs.h"
#include <string.h>
#include <stdlib.h>

etudiant *srchByNom(etudiant *etud_info, char *name){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(!(strcasecmp(etud_info->etud_info.nom, name))){
         srt->etud_info = etud_info->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etud_info = etud_info->suiv;
   } while(etud_info->suiv != NULL);

   return head;
}

etudiant *srchByPrenom(etudiant *etud_info, char *name){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(!(strcasecmp(etud_info->etud_info.prenom, name))){
         srt->etud_info = etud_info->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etud_info = etud_info->suiv;
   } while(etud_info->suiv != NULL);

   return head;
}

etudiant *srchByDate(etudiant *etud_info, date targetDate){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etud_info->etud_info.date_inscription.jour == targetDate.jour
         && etud_info->etud_info.date_inscription.mois == targetDate.mois
         && etud_info->etud_info.date_inscription.annee == targetDate.annee){
         srt->etud_info = etud_info->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etud_info = etud_info->suiv;
   } while(etud_info->suiv != NULL);

   return head;
}

etudiant *validlist(etudiant *etud_info){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etud_info->etud_info.moy >= 10.){
         srt->etud_info = etud_info->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etud_info = etud_info->suiv;
   } while(etud_info->suiv != NULL);

   return head;
}

etudiant *filierelist(etudiant *etud_info, e_filiere targetfiliere){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etud_info->etud_info.filiere == targetfiliere){
         srt->etud_info = etud_info->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etud_info = etud_info->suiv;
   } while(etud_info->suiv != NULL);

   return head;
}

