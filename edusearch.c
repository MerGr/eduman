/****************************************
 *                edusearch.c
 *    Search etudiant by name/enrolldate
 * **************************************/

#include "srchfuncs.h"
#include <string.h>
#include <stdlib.h>
//Linked List of sorted students

typedef struct sortd{
   etudiant_info stdnt;
   struct sortd *suiv;
}sortd;


sortd *srchByNom(etudiant *stdnt, char *name){
   sortd *nxt, *srt, *head;

   srt = (sortd *) malloc(sizeof(sortd));
   head = srt;
   do{
      if(!(strcasecmp(stdnt->etud_info.nom, name))){
         srt->stdnt = stdnt->etud_info;
         nxt = (sortd *) malloc(sizeof(sortd));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      stdnt = stdnt->suiv;
   } while(stdnt->suiv != NULL);

   return head;
}

sortd *srchByPrenom(etudiant *stdnt, char *name){
   sortd *nxt, *srt, *head;

   srt = (sortd *) malloc(sizeof(sortd));
   head = srt;
   do{
      if(!(strcasecmp(stdnt->etud_info.prenom, name))){
         srt->stdnt = stdnt->etud_info;
         nxt = (sortd *) malloc(sizeof(sortd));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      stdnt = stdnt->suiv;
   } while(stdnt->suiv != NULL);

   return head;
}

sortd *srchByDate(etudiant *stdnt, date targetDate){
   sortd *nxt, *srt, *head;

   srt = (sortd *) malloc(sizeof(sortd));
   head = srt;
   do{
      if(stdnt->etud_info.date_inscription.jour == targetDate.jour
         && stdnt->etud_info.date_inscription.mois == targetDate.mois
         && stdnt->etud_info.date_inscription.annee == targetDate.annee){
         srt->stdnt = stdnt->etud_info;
         nxt = (sortd *) malloc(sizeof(sortd));
         srt->suiv = nxt;
         srt = srt->suiv;
      }
      stdnt = stdnt->suiv;
   } while(stdnt->suiv != NULL);

   return head;
}
