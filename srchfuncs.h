/***********************************
 *
 *           srchfuncs.h
 *    header file for search funcs
 *
 * *********************************/
#include "eduStruct.h"
etudiant *searchoneByApo(etudiant *, int);

sortd *srchByNom(etudiant *, char *);

sortd *srchByPrenom(etudiant *, char *);

sortd *srchByDate(etudiant *, date);
