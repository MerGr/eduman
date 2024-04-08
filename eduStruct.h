#pragma once
#include <stdio.h>

typedef enum e_filiere { SMI=1 , SMA , SMP ,SMC , SVI ,STU} e_filiere ;
typedef enum Mois { jan = 1 ,feb ,mar ,apr ,may ,jun ,jul ,aug ,sep ,oct ,nov ,dec } Mois;
typedef enum e_genre { F =1 , H } e_genre;

typedef struct date {
    unsigned short int jour ;
    Mois mois;
    unsigned int annee ;

}date;

typedef struct module {
    char module_name[100] ;
    float  module_note ;

} module ;

typedef struct{
    int apogee  ;
    char nom[50] ;
    char prenom[50] ;
    e_genre genre;
    e_filiere filiere ;
    date date_inscription ; 
    date graduation_date;
    char academic_email[100];
    int num_of_modules;
    module modules[7] ;
    float moy;
}etudiant_info;


typedef struct etudiant{
    etudiant_info etud_info;
    struct etudiant * suiv ;

}etudiant;

typedef struct{
    etudiant * first;

}liste_etudiants;

