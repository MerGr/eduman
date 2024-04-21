#include <stdio.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "srchfuncs.h"

int delete_etud(etudiant *debut , int apog){
    etudiant *temp = searchoneByApo(debut,apog) ;
    etudiant *Q, *p=debut;

    if(temp != NULL){
        while(p != NULL){
            Q=p;
            p=p->suiv ;
            if(temp == p){
                Q->suiv = p->suiv ;
                free(p);
            }
        }

        return 1;
    }

    return 0;
}
