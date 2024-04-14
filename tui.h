/***********************************
 *
 *           tui.h
 *    header file for TUI funcs
 *
 * *********************************/
#include "eduStruct.h"

void draw_line(int);
void draw_table(etudiant *);
void draw_student(etudiant_info *);
void menu(unsigned short *);
unsigned short searchselect();
unsigned short sortselect();
unsigned short viewselect();
e_filiere filselect();