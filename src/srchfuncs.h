//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
/***********************************
 *
 *           srchfuncs.h
 *    header file for search funcs
 *
 * *********************************/
#include "eduStruct.h"

extern etudiant *searchoneByApo(etudiant *, int);

extern etudiant *srchByNom(etudiant *, char *);

extern etudiant *srchByPrenom(etudiant *, char *);

extern etudiant *srchByDate(etudiant *, date);

extern etudiant *validlist(etudiant *);

extern etudiant *filierelist(etudiant *, e_filiere);
