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
#include "tui.h"

date saisir_date(void){
    int days[]={31,29,31,30,31,30,31,31,30,31,30,31};
    date temp;
    scanf("%u/%d/%u", &temp.jour, (int *) &temp.mois, &temp.annee);
    //LEAP YEAR
    if(temp.annee % 4) days[1] = 28;
    else days[1] = 29;
    while (temp.jour > days[temp.mois -1]){
        printf("ERREUR ! Date invalide\n");

    }
    return temp;
}

int generate_apogee(int an){
    int temp = (an % 100) * 51340 ;
    srand(time(NULL));

    temp += (rand() % (10) )*10000 + (rand() % (10))*1000 + (rand() % (10))*100 + (rand() % (10))*10 + rand() % (10) ;
    return temp ;
}

void generate_academic_email(etudiant_info * etud){
    char email[2048] = "";
    char temp1[3];
    temp1[0]= etud->prenom[0];
    temp1[1]='.';
    strcat(email ,temp1);
    strcat(email , etud->nom);
    int temp = etud->apogee % 1000 ;
    char temp_string[5] ;
    snprintf(temp_string, 10, "%d", temp);
    strcat(email , temp_string);
    strcat(email ,"@eduman.edu");
    strcat(etud->academic_email , email);
}

void calc_moy(etudiant_info *etud){
    int n = etud->num_of_modules ;
    float som = 0 ;
    for(int i=0 ; i<n ; i++){
        som+=etud->modules[i].module_note;
    }
    etud->moy = som/n ;
}

void ajout_etudiant_info(etudiant_info *etud){
    etudiant_info *p = etud;
    int isValid=0 ;
    printf("Veuillez saisir le nom et prenom : \n ");
    scanf("%s %s",etud->nom, etud->prenom);
    while(isValid == 0){
        printf("Veuillez saisir le genre :  1 = Femme , 2 = Homme : \n ");
        scanf("%d",(int *)&etud->genre);
        switch(etud->genre){
        case F : isValid = 1 ;
        break;
        case H : isValid = 1 ;
        break;
        default  : printf("Error: invalide : \n");
                isValid = 0 ;

        }
    }

    isValid = 0 ;
    while(isValid == 0){
        etud->filiere = filselect();
        switch(etud->filiere){
        case SMI : isValid = 1 ;
        break;
        case SMA : isValid = 1 ;
        break;
        case SMP : isValid = 1 ;
        break;
        case SMC : isValid = 1 ;
        break;
        case SVI : isValid = 1 ;
        break;
        case STU : isValid = 1 ;
        break;
        default  : printf("Error: invalide : \n");
        isValid = 0  ;
    }
    }
    printf("Veuillez saisir la date d'inscription (format DD/MM/YYYY): \n ");
    etud->date_inscription=saisir_date();
    etud->graduation_date=etud->date_inscription;
    etud->graduation_date.annee = etud->date_inscription.annee + 3 ;
    etud->apogee = generate_apogee(etud->date_inscription.annee) ;
    generate_academic_email(p);

    isValid = 0 ;
    while(isValid == 0 ){
        printf("Veuillez entrer le nombre de modules : \n  ");
        scanf("%d",&etud->num_of_modules);
        
        if(etud->num_of_modules<= 0 || etud->num_of_modules > 7){
            printf("Error: le nombre de modules par semestre ne doit pas depasser 7\n");
            isValid = 0;
        }
        else{
            isValid = 1;
        }
    }

    printf("Veuillez entrer les informations de chaque module : \n");
    for(int i=0 ; i<etud->num_of_modules ; i++){
        printf("Veuillez saisir le nom du module %d: \n " ,i+1);
        scanf("%s",etud->modules[i].module_name);
        

        isValid = 0;
        while(isValid == 0){
            printf("Veuillez saisir la note du module %s : \n ", etud->modules[i].module_name);
            scanf("%f",&etud->modules[i].module_note);
            
            if(etud->modules[i].module_note <0 || etud->modules[i].module_note >20){
                printf("ERREUR : 0 <= NOTE VALIDE <= 20\n ");
                isValid = 0;
            }
            else{
                isValid = 1 ;
            }
        }
        isValid = 0;
    }
    for(int i=etud->num_of_modules; i<7; i++){
        strcpy(etud->modules[i].module_name, "---");
        etud->modules[i].module_note = 0.0;
    }

    calc_moy(etud);
    printf("\nEtudiant ajoute avec succes. \n ");

}

//ajout
void ajout(etudiant **debut){
    etudiant *new_etudiant = (etudiant *)malloc(sizeof(etudiant));
    if (new_etudiant == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    ajout_etudiant_info(&new_etudiant->etud_info);
    new_etudiant->suiv = NULL;

    if (*debut == NULL) {
        *debut = new_etudiant;
    }
    else{    
        etudiant *p = *debut;
        while (p->suiv != NULL) {
            p = p->suiv;
        }
        p->suiv = new_etudiant;
    }
}

void ajout_fin(etudiant **debut){
    etudiant *new_etudiant = (etudiant *)malloc(sizeof(etudiant));
    if (new_etudiant == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    ajout_etudiant_info(&new_etudiant->etud_info);
    new_etudiant->suiv = NULL;
    etudiant *head = *debut;
    
    if(*debut == NULL){
        *debut = new_etudiant;

    } else {
        while(head->suiv != NULL){
            head=head->suiv;
        }
        head->suiv=new_etudiant;
    }
}