/***********************************
 *
 *           tui.h
 *    header file for TUI funcs
 *
 * *********************************/
#include "eduStruct.h"

extern void draw_line(int);
extern void draw_table(etudiant *);
extern void draw_student(etudiant_info *);
extern void menu(unsigned int *);
extern unsigned int searchselect();
extern unsigned int sortselect();
extern unsigned int viewselect();
extern e_filiere filselect();