#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "eduStruct.h"

etudiant *searchoneByApo(etudiant *, int ) ;


etudiant * delete_etud(etudiant* debut , int apog){
    etudiant* temp = searchoneByApo(debut,apog) ;
    etudiant *p=debut  , *Q;

    if(temp == NULL){
        printf(" \n Il n'existe pas d'eutudiant correspondant à ce numero d'apogee \n");
    }
    else{
        while(p != NULL){
            Q=p;
            p=p->suiv ;
            if(temp == Q){
                Q->suiv = p->suiv ;
                free(p);
            }
        }  
    }
    return debut;
}



