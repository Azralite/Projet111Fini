#include <stdexcept>
/** @file **/
#include <fstream>
#include "tableau-donnees.h"


/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 **/

int moyenne(vector<int> t) {
    int moyenne = 0;
    for(int i=0;i< t.size(); i++){
		moyenne = moyenne + t[i];
	}
	moyenne = moyenne / t.size();
	return moyenne;
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs
 **/

int somme(vector<int> t) {
	int total = 0;
	for(int i=0;i< t.size(); i++){
		total = total + t[i];
	}
	return total;
}

/** Somme partielle d'un tableau
 * @param t un tableau d'entiers
 * @result la somme des entiers à partir de l'indice i
 **/

int sommePartielle(vector<int> t, int i) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction sommePartielle non implanté ligne 18");
}

/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/

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

/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/

vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction litTableauInt non implanté ligne 29");
}


/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param j un numéro de colonne
 * @return la colonne j, représentée par un vecteur d'entiers
 **/

vector<int> colonne(vector<vector<int>> t, int i) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction colonne non implanté ligne 34");
}
