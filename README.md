# ![EDUcationMANager](/assets/images/edumanlogo.png)

## Application TUI pour gestion des etudiants, mini-projet module Programmation 2

### Install/Usage

clone repository, make and run with :

```bash
git clone https://github.com/MerGr/eduman.git
cd eduman/
make
cd bin/
./eduman
```
### Contenu du code source

8 fichiers .h (C header files)
     ajoutfuncs.h
        Prototypes des fonctions d'ajouts et creation
     delfuncs.h
        Prototypes de fonction du suppression d'un etudiant
     eduStruct.h
        Prototypes des structures de donnees du programme
     filemanip.h
        Prototypes des fonctions de manipulation des fichiers
     modfuncs.h
        Prototypes des fonctions de modifications des fichiers
     sortfuncs.h
        Prototypes des fonctions de tri
     srchfuncs.h
        Prototypes des fonctions de recherche
     tui.h
        Prototypes de l'interface utilisateur textuel
9 fichiers .c (C source files)

     main.c
        Programme principale du EDUMAN
     ajout.c
        Fonctions d'ajouts et creation
     deledu.c
        Fonction de suppression
     edumantui.c
        Fonctions de l'interface utilisateur textuel
     edusearch.c
        Fonctions de recherche
     fxport.c
        Fonctions de manipulation des fichiers
     modedu.c
        Fonctions de modification
     searchone.c
        Fonction recherche un etudiant
     sortedu.c
        Fonctions de tri
