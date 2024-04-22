//
//  GRAOUI ABDERRAHMANE - 2023152
//  
//  EL AMLI Naima - 1717283
//
//  EDUMAN
//
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "eduStruct.h"
#include "srchfuncs.h"
#include "ajoutfuncs.h"
#include "tui.h"


//pour que l'utilisateur recupere l'id de chaque module
void show_modules_info(etudiant_info* etud){
    for(int i = 0 ; i<etud->num_of_modules ; i++){
        printf("-------------------------------------------------------------------------------------------\n");
        printf("L'ID du module : %d \n" , i+1 );
        printf("le nom du module : %s \n" , etud->modules[i].module_name) ;
        printf("la note du module : %f \n" , etud->modules[i].module_note) ;
        printf("-------------------------------------------------------------------------------------------\n");
    }
}

void add_module(etudiant_info* etud){
    char tmp[50];
    if(etud->num_of_modules == 7){
        printf("vous ne pouvez pas ajouter un nouveau module. \n");
    }
    else{
        etud->num_of_modules++;
        printf("Veuillez saisir le nom du module: %d \n " , etud->num_of_modules);
        scanf("%s",tmp);
        strncpy(etud->modules[etud->num_of_modules - 1].module_name, tmp, 50);
        do{
            printf(" Veuillez saisir la note du module: %d \n ",etud->num_of_modules);
            scanf("%f",&etud->modules[etud->num_of_modules - 1].module_note);
            getchar() ;
        }while(etud->modules[etud->num_of_modules - 1].module_note <0 || etud->modules[etud->num_of_modules - 1].module_note >20);
        printf("module ajoute avec succes\n");
    }
}

void edit_module(etudiant_info* etud){
    int module_id;
    char tmp[50];
    do{
        printf("veuillez entrer l'id du module : \n");
        scanf("%d",&module_id);
    }while(module_id < 1 || module_id > etud->num_of_modules);

    printf(" Veuillez saisir le nouveau nom du module:\n ");
    scanf("%s",tmp);
    strncpy(etud->modules[module_id - 1].module_name, tmp, 50);
    do{
        printf(" Veuillez saisir la note du module: \n ");
        scanf("%f",&etud->modules[module_id - 1].module_note);
    }while(etud->modules[module_id - 1].module_note <0 || etud->modules[module_id - 1].module_note >20);
    printf("Module modifie avec succes\n");
}

void delete_module(etudiant_info* etud){
    int module_id;
    do{
        printf("Veuillez entrer l'id du module : \n");
        scanf("%d",&module_id);
    }while(module_id < 1 || module_id > etud->num_of_modules);

    for(int i=module_id-1 ; i<etud->num_of_modules ; i++){
        etud->modules[i] = etud->modules[i+1];
    }
    etud->num_of_modules--;
}

void  modifier_modules_info(etudiant_info* etud){
    e_module choix;
    printf("Est ce que vous vouler : \n");
    printf("supprimer un module = 1 , ajouter un module = 2 , modifier un module = 3 ");
    scanf("%d",(int *)&choix);
    switch (choix){
    case 1 : delete_module(etud);
        break;
    case 2 : add_module(etud);
        break;
    case 3 : edit_module(etud);
        break;
    default : printf("error : choix invalide \n ");
        break;
    }
}

void modifier_etudiant(etudiant_info *etud){
    int rep;
    printf("\n<!> La modificatin de l'email et l'apogee n'est pas autorisee ! \n");
    printf("Est que vous voulez modifier le nom : oui = 1 , non = 0 \n");
    scanf("%d",&rep);
    if(rep == 1){
        printf(" Veuillez saisir le nouveau nom de l'etudiant : \n ");
        scanf("%s", etud->nom);
    }

    printf("Est que vous voulez modifier le prenom : oui = 1 , non = 0 \n");
    scanf("%d",&rep);
    if(rep == 1){
        printf("Veuillez saisir le  nouveau prenom de l'etudiant : \n ");
        scanf("%s", etud->prenom);
    }

    printf("Est que vous voulez modifier le genre : oui = 1 , non = 0 \n");
    scanf("%d",&rep);
    if(rep == 1){
        if(etud->genre == 1){
            etud->genre=2;
        }
        else{
            etud->genre=1;
        }
        printf("le genre a ete modifie\n") ;
    }

    printf("Est que vous voulez modifier la filiere : oui = 1 , non = 0 \n");
    scanf("%d",&rep);
    if(rep == 1){
            etud->filiere = filselect();
    }

    printf("Est que vous voulez modifier la date d'inscription : oui = 1 , non = 0 \n");
    scanf("%d",&rep);
    if(rep == 1){
        printf("Veuillez saisir la nouvelle date : \n ");
        etud->date_inscription=saisir_date();
        etud->graduation_date=etud->date_inscription;
        etud->graduation_date.annee = etud->date_inscription.annee + 3 ;
    }

    printf("Vous avez ajoute %d modules \n",etud->num_of_modules);
    printf("Est que vous voulez modifier les informations de ces modules : oui = 1 , non = 0 \n\n");
    scanf("%d",&rep);

    while(rep == 1){
        show_modules_info(etud);
        modifier_modules_info(etud);
        printf("Est que vous voulez encore modifier les informations de ces modules : oui = 1 , non = 0 \n\n");
        scanf("%d",&rep);
    }
}

etudiant *modifier_etud_info(etudiant* debut , int apog){
    etudiant *temp = searchoneByApo(debut, apog);
    etudiant *p=debut;

    if(temp == NULL){
        printf(" \n Il n'existe pas d'etudiant correspondant à ce numero d'apogee \n");
    }
    else{
        while(p != temp){
            p=p->suiv ;
        }
        modifier_etudiant(&p->etud_info);
    }
    
    return debut;
}

void free_list(etudiant **tofree){
    etudiant *node = *tofree;
    etudiant *tmp;

    do{
        tmp = node;
        node = node->suiv;
        free(tmp);
        tmp = NULL;
    } while(node != NULL);
}
