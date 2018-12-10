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

vector<string> colonne(vector<vector<string>> t, int i) {
    vector<string> tab (t.size());
	for(int j = 0; j < t.size(); j ++){
		tab[j] = t[j][i];
	}
	return tab;
}

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
