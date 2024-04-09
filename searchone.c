/******************************************
 *
 *                searchone
 *
 *    Recherche un etudiant par Apogee
 *
 * ****************************************/

#include "srchfuncs.h"
#include "eduStruct.h"
etudiant *searchoneByApo(etudiant *start, int targetApo){
   do{
      if(start->etud_info.apogee == targetApo)
         return start;
      else{
         if(start->suiv != NULL) start = start->suiv;
      }
   } while(start->suiv != NULL);

   return start->suiv;
}
