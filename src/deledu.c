//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
#include <stdio.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "srchfuncs.h"

void delete_etud(etudiant **debut , int apog){
    etudiant *tmp = *debut, *p;

    do{
        p = tmp;
        tmp = tmp->suiv;
        if(tmp && tmp->etud_info.apogee == apog){
            if(tmp->suiv != NULL) p->suiv = tmp->suiv;
            free(tmp);
            break;
        }
    } while (tmp && tmp->etud_info.apogee != apog);
}
