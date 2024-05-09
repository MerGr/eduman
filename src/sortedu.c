#include <stdio.h>
#include "eduStruct.h"

// ordre croissant
etudiant * sort_apogee(etudiant* debut ){
    etudiant *p=debut  , *temp;
    etudiant_info data ;
    if(debut != NULL){
        for(p = debut ; p->suiv != NULL ; p = p->suiv ){
            for(temp = p->suiv ; temp != NULL ; temp = temp->suiv ){
                if( temp->etud_info.apogee < p->etud_info.apogee){
                    data = p->etud_info ;
                    p->etud_info = temp->etud_info ;
                    temp->etud_info =data ;
                }
            }
        }
    }
    return debut;
}

//ordre decroissant
etudiant *sort_moy(etudiant* debut ){
    etudiant *p=debut  , *temp;
    etudiant_info data ;
    if(debut != NULL){
        for(p = debut ; p->suiv != NULL ; p = p->suiv ){
            for(temp = p->suiv ; temp != NULL ; temp = temp->suiv ){
                if( temp->etud_info.moy > p->etud_info.moy){
                    data = p->etud_info ;
                    p->etud_info = temp->etud_info ;
                    temp->etud_info =data ;
                }
            }
        }
    }
    return debut;
}

//ordre decroissant
etudiant *sort_date_inscription(etudiant* debut ){
    etudiant *p=debut  , *temp;
    etudiant_info data ;
    if(debut != NULL){
        for(p = debut ; p->suiv != NULL ; p = p->suiv ){
            for(temp = p->suiv ; temp != NULL ; temp = temp->suiv ){
                if( temp->etud_info.date_inscription.annee > p->etud_info.date_inscription.annee){
                    data = p->etud_info ;
                    p->etud_info = temp->etud_info ;
                    temp->etud_info =data ;
                }
            }
        }
    }
    return debut;
}