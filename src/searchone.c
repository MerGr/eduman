//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
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
   while(start){
      if(start->etud_info.apogee == targetApo)
         break;
      start = start->suiv;  
   };

   return start;
}
