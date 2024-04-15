#include <stdio.h>
#include "eduStruct.h"
#include "srchfuncs.h"

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



