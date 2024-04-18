#include <stdio.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "srchfuncs.h"

void delete_etud(etudiant* debut , int apog){
    etudiant *temp = searchoneByApo(debut,apog) ;
    etudiant *Q, *p=debut;

    if(temp == NULL){
        printf(" \n Il n'existe pas d'eutudiant correspondant à ce numero d'apogee \n");
    }
    else{
        while(p != NULL){
            Q=p;
            p=p->suiv ;
            if(temp == p){
                Q->suiv = p->suiv ;
                free(p);
            }
        }
    }
}
