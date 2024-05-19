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
    etudiant *tmp = *debut, *p = tmp;

    if(tmp->etud_info.apogee == apog){
            if(tmp->suiv) *debut = tmp->suiv;
            else *debut = NULL;
            free(tmp);
    } 
    else {
        do{
            if(tmp->suiv && tmp->suiv->etud_info.apogee == apog){
                p = tmp;
                tmp = tmp->suiv;
                if(tmp->suiv) p->suiv = tmp->suiv;
                else p->suiv = NULL;
                free(tmp);
                break;
            }

            tmp = tmp->suiv;

        } while(tmp);
    }
}
