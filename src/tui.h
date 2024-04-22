//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
/***********************************
 *
 *           tui.h
 *    header file for TUI funcs
 *
 * *********************************/
#include "eduStruct.h"

extern void draw_table(etudiant *);
extern void draw_student(etudiant_info *, int);
extern void menu_one(int *);
extern void menu_two(int *);
extern int searchselect();
extern int sortselect();
extern int viewselect();
extern int modselect();
extern e_filiere filselect();