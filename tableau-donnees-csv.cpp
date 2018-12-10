#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-donnees-csv.h"

/**Affiche un tableau de string à deux dimensions
* @param un tableau de string à deux dimensions
* Affiche le tableau 
**/ 

void afficheTableau(vector<vector<string>> tableau) {    
	for(int i = 0; i < tableau.size(); i ++){
	for(int j =0 ; j < tableau[0].size(); j++){
		cout << tableau[i][j] << " ";
	}
	cout << endl;
	}
	
}

/** Construction d’un tableau 2D de cha^ınes lu depuis un fichier CSV
* @param fichier le nom d’un fichier contenant un nombre fixe
* d’entiers par lignes, séparés par des espaces
* @param nb_colonnes le nombre de colonnes du fichier
* @return un tableau d’entiers à deux dimensions
**/

vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
	//ifstream fichier(nom_fichier);
	//char chara;
	//vector<vector<string>> tab;
	//string mot;
	//vector<string> t(nb_colonnes);
	//string entete;
	//getline(fichier, entete);
	//while(fichier >> chara ){
	//	for(int i = 0; i < nb_colonnes; i++){
	//	getline(fichier, mot, ';');
	//	t[i] = mot;
	//	}
	//tab.push_back(t);
	//}
	//return tab;
	ifstream fichier(nom_fichier); // Auteurs: les profs!
    vector<vector<string>> tableau;
    string ligne;
    // Lecture de l'entête
    getline(fichier, ligne);
    while (fichier) {
        vector<string> ligne_tableau;
        string v;

        // Lecture des valeurs de la ligne sauf la dernière
        for ( int i = 0; i < nb_colonnes-1; i++ ) {
            getline(fichier, v, ';');
            ligne_tableau.push_back(v);
        }

        // Lecture de la dernière valeur
        getline(fichier, v);
        // Gestion des fichier Windows sous Linux
        if ( v.size() > 0 and v[v.length()-1] == '\r' )
            v.resize(v.length() - 1);
        ligne_tableau.push_back(v);

        if ( fichier )
            tableau.push_back(ligne_tableau);
    }
    return tableau;
}

/** Construction d’un tableau 2D de chaînes lu depuis un fichier CSV
* @param fichier le nom d’un fichier contenant un nombre fixe
* d’entiers par lignes, séparés par des espaces
* @return un tableau d’entiers à deux dimensions
**/

vector<vector<string>> litTableauCSV(string nom_fichier) {//auteurs: les profs!
	ifstream fichier(nom_fichier);
	vector<vector<string>> tableau;
	string ligne;
	// Lecture de l'entête
	getline(fichier, ligne);
	while ( getline(fichier,ligne) ) {
        istringstream sl(ligne);
        vector<string> ligne_tableau;
        string v;
        while ( getline(sl, v, ';' )) {
            // Gestion des fichier Windows sous Linux
            if ( v.size() > 0 and v[v.length()-1] == '\r' )
                v.resize(v.length() - 1);
            ligne_tableau.push_back(v);
        }
        tableau.push_back(ligne_tableau);
    }
    return tableau;
}

/** Extraction d’une colonne d’un tableau 2D de cha^ınes de caract`eres
* @param t un tableau 2D de chaînes de caractères
* @param i un numéro de colonne
* @return la colonne i, représentée par un vecteur
**/

vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> tab (t.size());
	for(int j = 0; j < t.size(); j ++){
		tab[j] = t[j][i];
	}
	return tab;
}

/** Conversion d’un vecteur de chaînes de caractères en vecteur d’entiers
* @param t un vecteur de chaînes de caractères
* @return le vecteur, converti en vecteur d’entiers
**/

vector<int> conversionInt(vector<string> t) {
    vector<int> tab;
	tab = vector<int> (t.size());
	int val;
	for(int i = 0; i < t.size(); i ++){
	istringstream(t[i]) >> val;
	tab[i] = val;
	}
	return tab;
}

/** Conversion d’un vecteur de chaînes de caractères en vecteur de doubles
* @param t un vecteur de chaînes de caractères
* @return le vecteur, converti en vecteur de doubles
**/

vector<double> conversionDouble(vector<string> t) {
    vector<double> tab;
	tab = vector<double> (t.size());
	double val;
	for(int i = 0; i < t.size(); i ++){
	istringstream(t[i]) >> val;
	tab[i] = val;
	}
	return tab;
}
//Ne fonctionne pas 
template<class T>
vector<T> conversion(vector<string> t) {
	vector<T> tab;
	tab = vector<T> (t.size());
	T val;
  for(int i =0; i < t.size(); i ++){
	istringstream(t[i]) >> val;
	tab[i] = val;
	}
	return tab;
}

//Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
