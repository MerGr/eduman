/******************************************
 *
 *						searchone
 *
 *		Recherche un etudiant par Apogee
 *
 * ****************************************/

#include "srchfuncs.h"

etudiant *searchoneByApo(etudiant *start, int targetApo){
	do{
		if(start->apogee == targetApo)
			return start;
		else{
			if(start->next != NULL) start = start->next;
		}
	} while(start->next != NULL);

	return start->next;
}
