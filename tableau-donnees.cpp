#include <stdexcept>
/** @file **/
#include <fstream>
#include "tableau-donnees.h"

int moyenne(vector<int> t) {
    int moyenne = 0;
    for(int i=0;i< t.size(); i++){
		moyenne = moyenne + t[i];
	}
	moyenne = moyenne / t.size();
	return moyenne;
}

int somme(vector<int> t) {
	int total = 0;
	for(int i=0;i< t.size(); i++){
		total = total + t[i];
	}
	return total;
}

int sommePartielle(vector<int> t, int i) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction sommePartielle non implanté ligne 18");
}


int indiceMax(vector<int> t) {
	int valeurMax = 0;
	int rangMax = 0;
	if(t.size() == 0){
		return -1;
	}
	for(int i = 0; i < t.size() ; i++){
		if (t[i] > valeurMax){
			valeurMax = t[i];
			rangMax= i;
		}	
	}
	return rangMax;
}

vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction litTableauInt non implanté ligne 29");
}

vector<int> colonne(vector<vector<int>> t, int i) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction colonne non implanté ligne 34");
}
