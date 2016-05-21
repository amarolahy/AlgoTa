#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "list.h"
#include "dlist.h"
#include "clist.h"
#include "frames.h"
#include	"set.h"

#define NB                   5
#define BORNE_SUP           100

void listeChaine() {
	printf("Liste chaine ! \n\n");

	// Création de la liste 
	List *lc = (List *)malloc(sizeof(*lc));
	list_init(lc, free);
	// printf("List cree avec succes.\n");


	// Insertion d'éléments dans la liste
	int *data,
		i;
	for (i = 0; i < NB; i++) {
		data = (int *)malloc(sizeof(*data));
		*data = rand() % BORNE_SUP;
		list_ins_next(lc, NULL, data);
	}
	printf("Insertion termine.\n");

	// Affichage 
	printf("\nListe des elements : \n");
	ListElmt *element = list_head(lc);
	for (i = 0; i < list_size(lc); i++) {
		data = (int *)list_data(element);
		printf("val [%d] = %d\n", i, *data);
		element = list_next(element);
	}


	list_destroy(lc);

}

void listeDoubleChaine() {
	//Création de la liste
	DList *lc = (DList *)malloc(sizeof(*lc));
	dlist_init(lc, free);
	printf("Double_List crée avec succés.\n");


	// Insertion des données dans la liste
	int     *data,	// Tsy maintsy ao anaty pointeur ilay données atsofoka ao am liste
		i; // Compteur

	for (i = 0; i<NB; i++) {
		data = (int *)malloc(sizeof(*data)); // Allocation mémoire pour la donnée
		*data = rand() % BORNE_SUP;	// Génération nombre aléatoire entre 0 et BORNE_SUP
		dlist_ins_next(lc, dlist_tail(lc), (void *)data); // Insertion proprement dit
	}

	printf("Insertion terminé.\n");

	//affichage
	printf("\nListe des elements :\n");

	DListElmt *element = dlist_head(lc);
	for (i = 0; i<dlist_size(lc); i++) {
		//if(list_rem_next(lc, NULL, &data) == -1) continue;
		//printf("get data.\n");
		data = dlist_data(element);

		printf("val [%d] = %d\n", i + 1, (int)*data);
		//printf("get next.\n");
		element = dlist_next(element);
		//free(data);
	}

	printf("\n\nLa taille de la liste est : %d\n", dlist_size(lc));

	dlist_destroy(lc);
}

void listeCirculaire() {
	CList *lc = (CList *)malloc(sizeof(*lc));

	clist_init(lc, free);

	CListElmt *el;
	clist_data(el);
	
	clist_destroy(lc);

	return;
}

int matchInt(const int *a, const int *b) {
	return *a == *b;
}

void setTest() {
	srand(time(NULL));
	
	Set *set = (Set *)malloc(sizeof(Set));
	set_init(set, matchInt, free);

	int *value = (int *)malloc(sizeof(*value));
	
	int i = 10,
		tour = 10;

	for (i = 0; i < tour; i++) {
		value = (int *)malloc(sizeof(*value));
		*value = rand() % BORNE_SUP;
		set_insert(set, value);
	}

	ListElmt *elt = list_head(set);
	int *data;
	for (elt = list_head(set); elt != NULL; elt = list_next(elt)) {
		data = (int*)list_data(elt);
		printf("%d - ", *data);
	}

	getchar();

	set_destroy(set);
}

int main(int argc, char *argv[]){
    printf("\tAlgorithm Programm!\n");

    srand(time(NULL));

	listeChaine();
	// listeDoubleChaine();
	setTest();

	getchar();

    return EXIT_SUCCESS;
}
