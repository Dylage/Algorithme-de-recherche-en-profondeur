#include <stdio.h>
#include <stdbool.h>

#define ORDRE 6

//	Liste des sommets explorées, au départ, aucun ne l'est
static int sommetExplore[ORDRE] ={false,false,false,false,false,false};

//////////////////////////////////////////////////////////////////////////
//	Procédure pour explorer  en profondeur un graphe ; et afficher les
//	sommets dans l'ordre d'exploration
//
//	Entrée : entier : ordre du graphe, tableau booléen : graphe
//		entier : sommet de départ
//
//	Sortie : Rien ; uniquement de l'affichage
//////////////////////////////////////////////////////////////////////////
void explorer(int ordre, bool tab[ordre][ordre], int sommet){

	//	Affichage du sommet exploré, puis indication de l'exploration
	printf("%d -> ", sommet +1);
	sommetExplore[sommet]=true;

	for (int i=0;i<ORDRE;i++){
		if(tab[sommet][i] && !sommetExplore[i]){
			explorer(ORDRE,tab,i);

		}
	}
}


int main(void) {
	//	Graphe fourni
	bool tab[ORDRE][ORDRE]={
		{false,true,true,true,false,false},
		{false,false,false,false,false,false},
		{false,false,false,false,true,false},
		{true,false,false,false,false,false},
		{false,true,false,false,false,true},
		{false,false,false,false,false,false}};


	printf("Voici les sommets dans l'ordre d'exploration :\n");
	explorer(ORDRE,tab,0);

	//	On efface la derniere flèche
	printf("\b\b\b   \n");

	return 0;
}
