#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "eduStruct.h"

date saisir_date(void){
    date temp;
    int isValid = 0 ;
        printf(" Veuillez saisir le jour : \n ");
        scanf("%d",&temp.jour);
        getchar() ;
        while(isValid == 0){
            printf(" Veuillez saisir le numero du mois : jan=1 ,feb=2 ,mar=3 ,apr=4 ,may=5 ,jun=6 ,jul=7 ,aug=8 ,sep=9 ,oct=10 ,nov=11 ,dec=12 \n ");
            scanf("%d",&temp.mois);
            getchar() ;
            switch(temp.mois){
            case jan : isValid = 1 ;
            break;
            case feb : isValid = 1 ;
            break;
            case mar : isValid = 1 ;
            break;
            case apr : isValid = 1 ;
            break;
            case may : isValid = 1 ;
            break;
            case jun : isValid = 1 ;
            break;
            case jul : isValid = 1 ;
            break;
            case aug : isValid = 1 ;
            break;
            case sep : isValid = 1 ;
            break;
            case oct : isValid = 1 ;
            break;
            case nov : isValid = 1 ;
            break;
            case dec : isValid = 1 ;
            break;
            default  : printf(" Error: invalide : \n"); 
                    isValid = 0;

            }
        }
        printf(" Veuillez saisir l'annee : \n ");
        scanf("%d",&temp.annee);
        getchar() ;
        return temp;
}

int generate_apogee(int an){
    int temp = (an % 100) * 100000 ;
    srand(time(NULL)); 
    
    temp += (rand() % (10) )*10000 + (rand() % (10))*1000 + (rand() % (10))*100 + (rand() % (10))*10 + rand() % (10) ;
    return temp ;
}

void generate_academic_email(etudiant * etud){
    char email[100] = "";
    char temp1[3];
    temp1[0]= etud->prenom[0];
    temp1[1]='.';
    strcat(email ,temp1);
    strcat(email , etud->nom);
    int temp = etud->apogee % 1000 ;
    char temp_string[5] ;
    itoa(temp , temp_string ,10);
    strcat(email , temp_string);
    strcat(email ,"@eduman.edu");
    strcat(etud->academic_email , email);
}

void ajout_etudiant(etudiant *etud){
    etudiant * p=etud;
    int isValid=0 ;
    printf(" Veuillez saisir le nom de l'etudiant : \n ");
    scanf(" %[^\n]s",&etud->nom);
    getchar() ;
    printf(" Veuillez saisir le prenom de l'etudiant : \n ");
    scanf(" %[^\n]s",&etud->prenom);
    getchar() ;
    while(isValid == 0){
        printf(" Veuillez saisir le genre :  1 = femme , 2 = homme : \n ");
        scanf("%d",&etud->genre);
        switch(etud->genre){
        case F : isValid = 1 ;
        break;
        case H : isValid = 1 ;
        break;
        default  : printf(" Error: invalide : \n");
                isValid == 0 ;

        }
    }
    
    isValid = 0 ;
    while(isValid == 0){
        printf(" Veuillez saisir la filiere : SMI=1 / SMA=2 / SMC=3 / SMP=4 / SVI=5 / STU=6 \n ");
        scanf("%d",&etud->filiere);
        getchar() ;
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
        default  : printf(" Error: invalide : \n"); 
        isValid == 0  ;
    }
    }
    printf(" Veuillez saisir la date d'inscription  : \n ");
    etud->date_inscription=saisir_date();
    etud->graduation_date=etud->date_inscription;
    etud->graduation_date.annee = etud->date_inscription.annee + 3 ;
    etud->apogee = generate_apogee(etud->date_inscription.annee) ;
    generate_academic_email(p);

    isValid = 0 ;
    while(isValid == 0 ){
        printf(" Veuillez enter le nombre de modules : \n  ");
        scanf("%d",&etud->num_of_modules);
        getchar() ;
        if(etud->num_of_modules<= 0 || etud->num_of_modules > 7){
            printf(" Error: le nombre de modules par semestre ne doit pas depasser 7\n");
            isValid == 0;
        }
        else{
            isValid = 1;
        }
    }

    printf("Veuillez enter les informations de chaque module : \n");
    for(int i=0 ; i<etud->num_of_modules ; i++){
        printf(" Veuillez saisir le nom du module: %d \n " ,i+1);
        scanf(" %[^\n]s",&etud->modules[i].module_name);
        getchar() ;

        isValid = 0;
        while(isValid == 0){
            printf(" Veuillez saisir la note du module: %d \n ",i+1);
            scanf("%f",&etud->modules[i].module_note);
            getchar() ;
            if(etud->modules[i].module_note <0 || etud->modules[i].module_note >20){
                printf(" error : la note doit etre >=0 et <= 20 \n ");
                isValid = 0;
            }
            else{
                isValid = 1 ;
            }
        } 
        isValid = 0;
    }
    
    printf(" \n etudiant ajoute avec succes. \n ");
}





int main(){
    etudiant etud , *p=&etud;
    ajout_etudiant(p);
    return 0;
}

