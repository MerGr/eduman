//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
/****************************************
 *                edusearch.c
 *    Search etudiant by name/enrolldate
 * **************************************/

#include "srchfuncs.h"
#include <string.h>
#include <stdlib.h>

etudiant *srchByNom(etudiant *etudlist, char *name){
   etudiant *nxt, *srt, *head;
   int found = 0;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(!(strcasecmp(etudlist->etud_info.nom, name))){
         found = 1;
         srt->etud_info = etudlist->etud_info;
         if (etudlist->suiv) {
            nxt = (etudiant *) malloc(sizeof(etudiant));
            srt->suiv = nxt;
            srt = srt->suiv;
         }
      }
      etudlist = etudlist->suiv;
   } while(etudlist);

   if(found) return head;
   else return NULL;
}

etudiant *srchByPrenom(etudiant *etudlist, char *name){
   etudiant *nxt, *srt, *head;
   int found = 0;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(!(strcasecmp(etudlist->etud_info.prenom, name))){
         found = 1;
         srt->etud_info = etudlist->etud_info;
         if (etudlist->suiv) {
            nxt = (etudiant *) malloc(sizeof(etudiant));
            srt->suiv = nxt;
            srt = srt->suiv;
         }
      }
      etudlist = etudlist->suiv;
   } while(etudlist);

   if(found) return head;
   else return NULL;
}

etudiant *srchByDate(etudiant *etudlist, date targetDate){
   etudiant *nxt, *srt, *head;
   int found = 0;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etudlist->etud_info.date_inscription.jour == targetDate.jour
         && etudlist->etud_info.date_inscription.mois == targetDate.mois
         && etudlist->etud_info.date_inscription.annee == targetDate.annee){
         found = 1;
         srt->etud_info = etudlist->etud_info;
         if (etudlist->suiv) {
            nxt = (etudiant *) malloc(sizeof(etudiant));
            srt->suiv = nxt;
            srt = srt->suiv;
         }
      }
      etudlist = etudlist->suiv;
   } while(etudlist);

   if(found) return head;
   else return NULL;
}

etudiant *validlist(etudiant *etudlist){
   etudiant *nxt, *srt, *head;
   int found = 0;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etudlist->etud_info.moy >= 10){
         found = 1;
         srt->etud_info = etudlist->etud_info;
         if (etudlist->suiv) {
            nxt = (etudiant *) malloc(sizeof(etudiant));
            srt->suiv = nxt;
            srt = srt->suiv;
         }
      }
      etudlist = etudlist->suiv;
   } while(etudlist && etudlist->suiv);

   if(found) return head;
   else return NULL;
}

etudiant *filierelist(etudiant *etudlist, e_filiere targetfiliere){
   etudiant *nxt, *srt, *head;
   int found = 0;

   srt = (etudiant *) malloc(sizeof(etudiant));
   head = srt;
   do{
      if(etudlist->etud_info.filiere == targetfiliere){
         found = 1;
         srt->etud_info = etudlist->etud_info;
         if (etudlist->suiv) {
            nxt = (etudiant *) malloc(sizeof(etudiant));
            srt->suiv = nxt;
            srt = srt->suiv;
         }
      }
      etudlist = etudlist->suiv;
   } while(etudlist && etudlist->suiv);

   if(found) return head;
   else return NULL;
}

