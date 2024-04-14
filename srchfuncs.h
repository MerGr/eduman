/***********************************
 *
 *           srchfuncs.h
 *    header file for search funcs
 *
 * *********************************/
#include "eduStruct.h"

etudiant *searchoneByApo(etudiant *, int);

etudiant *srchByNom(etudiant *, char *);

etudiant *srchByPrenom(etudiant *, char *);

etudiant *srchByDate(etudiant *, date);

etudiant *validlist(etudiant *);

etudiant *filierelist(etudiant *, e_filiere);
