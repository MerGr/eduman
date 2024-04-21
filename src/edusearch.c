/****************************************
 *                edusearch.c
 *    Search etudiant by name/enrolldate
 * **************************************/

#include "srchfuncs.h"
#include <string.h>
#include <stdlib.h>

etudiant *srchByNom(etudiant *etudlist, char *name){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(!(strcasecmp(etudlist->etud_info.nom, name))){
         srt->etud_info = etudlist->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etudlist = etudlist->suiv;
   } while(etudlist->suiv != NULL);

   return head;
}

etudiant *srchByPrenom(etudiant *etudlist, char *name){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(!(strcasecmp(etudlist->etud_info.prenom, name))){
         srt->etud_info = etudlist->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etudlist = etudlist->suiv;
   } while(etudlist->suiv != NULL);

   return head;
}

etudiant *srchByDate(etudiant *etudlist, date targetDate){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etudlist->etud_info.date_inscription.jour == targetDate.jour
         && etudlist->etud_info.date_inscription.mois == targetDate.mois
         && etudlist->etud_info.date_inscription.annee == targetDate.annee){
         srt->etud_info = etudlist->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etudlist = etudlist->suiv;
   } while(etudlist->suiv != NULL);

   return head;
}

etudiant *validlist(etudiant *etudlist){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etudlist->etud_info.moy >= 10.){
         srt->etud_info = etudlist->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etudlist = etudlist->suiv;
   } while(etudlist->suiv != NULL);

   return head;
}

etudiant *filierelist(etudiant *etudlist, e_filiere targetfiliere){
   etudiant *nxt, *srt, *head;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etudlist->etud_info.filiere == targetfiliere){
         srt->etud_info = etudlist->etud_info;
         nxt = (etudiant *) malloc(sizeof(etudiant));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      etudlist = etudlist->suiv;
   } while(etudlist->suiv != NULL);

   return head;
}

