//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
/***********************************
 *
 *           filemanip.h
 *    header file for file manip funcs
 *
 * *********************************/
#include "eduStruct.h"

extern void fdraw_line(FILE *, int);
extern void write_to_file(FILE *, etudiant *);

extern void create(char *, etudiant *);
extern void readfile(char *, int, etudiant **);
extern void modfile(char *, etudiant *);