/***********************************
 *
 *           filemanip.h
 *    header file for file manip funcs
 *
 * *********************************/
#include "eduStruct.h"

void fdraw_line(FILE *, int);
void write_to_file(FILE *, etudiant *);

void create(char *, etudiant *);
void readline(char *, yORn, etudiant *, yORn);
void modfile(char *, etudiant *);