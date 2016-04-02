#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "list.h"
#include "dlist.h"
#include "clist.h"
#include "frames.h"

#define NB                   5
#define BORNE_SUP           10

void destroy(void *data){
    free(data);
}

void listeChaine() {
	printf("Liste chaine ! \n\n");

	// Création de la liste 
	List *lc = (List *)malloc(sizeof(*lc));
	list_init(lc, destroy);
	// printf("List cree avec succes.\n");


	// Insertion d'éléments dans la liste
	int *data,
		i;
	for (i = 0; i < NB; i++) {
		data = (int *)malloc(sizeof(*data));
		*data = rand() % BORNE_SUP;
		list_ins_next(lc, NULL, (void *)data);
	}
	printf("Insertion termine.\n");

	// Affichage 
	printf("\nListe des elements : \n");
	ListElmt *element = list_head(lc);
	for (i = 0; i < list_size(lc); i++) {
		data = list_data(element);
		printf("val [%d] = %d\n", i, (int)*data);
		element = list_next(element);
	}


	list_destroy(lc);

}

void listeDoubleChaine() {
	//Création de la liste
	DList *lc = (DList *)malloc(sizeof(*lc));
	dlist_init(lc, destroy);
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

	clist_init(lc, destroy);

	CListElmt *el;
	clist_data(el);
	
	clist_destroy(lc);

	return;
}

int main(int argc, char *argv[]){
    printf("\tAlgorithm Programm!\n");

    srand(time(NULL));

	listeChaine();
	// listeDoubleChaine();

    return EXIT_SUCCESS;
}
