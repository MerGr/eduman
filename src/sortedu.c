//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
#include <stdio.h>
#include "eduStruct.h"


//ALGORITHME TRI PAR FUSION
etudiant *merge(etudiant *left, etudiant *right, int option) {
    etudiant *result = NULL;

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    switch(option){
        case 1: //Tri croissant Apogee
            if (left->etud_info.apogee <= right->etud_info.apogee) {
                result = left;
                result->suiv = merge(left->suiv, right, 1);
            } else {
                result = right;
                result->suiv = merge(left, right->suiv, 1);
            }
            break;
        case 2: //Tri croissant moyenne
            if (left->etud_info.moy <= right->etud_info.moy) {
                result = left;
                result->suiv = merge(left->suiv, right, 2);
            } else {
                result = right;
                result->suiv = merge(left, right->suiv, 2);
            }
            break;
        case 3: //Tri croissant Date Inscription
            if(left->etud_info.date_inscription.annee <= right->etud_info.date_inscription.annee ||
                (left->etud_info.date_inscription.annee == right->etud_info.date_inscription.annee && 
                left->etud_info.date_inscription.mois <= right->etud_info.date_inscription.mois) ||
                (left->etud_info.date_inscription.annee == right->etud_info.date_inscription.annee && 
                left->etud_info.date_inscription.mois == right->etud_info.date_inscription.mois &&
                left->etud_info.date_inscription.jour <= right->etud_info.date_inscription.jour)
                ){
                    result = left;
                    result->suiv = merge(left->suiv, right, 3);
            } else {
                result = right;
                result->suiv = merge(left, right->suiv, 2);
            }
    }

    return result;
}

etudiant *sort_apogee(etudiant *debut){
    if (debut == NULL || debut->suiv == NULL)
        return debut;

    etudiant *middle = debut;
    etudiant *end = debut->suiv;

    while (end != NULL && end->suiv != NULL) {
        middle = middle->suiv;
        end = end->suiv->suiv;
    }

    etudiant *right = middle->suiv;
    middle->suiv = NULL;

    return merge(sort_apogee(debut), sort_apogee(right), 1);
}

//ordre decroissant
etudiant *sort_moy(etudiant* debut ){
    if (debut == NULL || debut->suiv == NULL)
        return debut;

    etudiant *middle = debut;
    etudiant *end = debut->suiv;

    while (end != NULL && end->suiv != NULL) {
        middle = middle->suiv;
        end = end->suiv->suiv;
    }

    etudiant *right = middle->suiv;
    middle->suiv = NULL;

    return merge(sort_moy(debut), sort_moy(right), 2);
}

//ordre decroissant
etudiant *sort_date_inscription(etudiant* debut ){
    if (debut == NULL || debut->suiv == NULL)
        return debut;

    etudiant *middle = debut;
    etudiant *end = debut->suiv;

    while (end != NULL && end->suiv != NULL) {
        middle = middle->suiv;
        end = end->suiv->suiv;
    }

    etudiant *right = middle->suiv;
    middle->suiv = NULL;

    return merge(sort_date_inscription(debut), sort_date_inscription(right), 3);
}