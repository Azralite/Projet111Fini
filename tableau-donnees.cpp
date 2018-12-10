#include <stdexcept>
/** @file **/
#include <fstream>
#include<algorithm>
#include "tableau-donnees.h"

int moyenne(vector<int> t) {
    int Moyenne = 0;
    for(int i=0;i< t.size(); i++){
		Moyenne = Moyenne + t[i];
	}
	Moyenne = Moyenne / t.size();
	return Moyenne;
}

int somme(vector<int> t) {
	int total = 0;
	for(int i=0;i< t.size(); i++){
		total = total + t[i];
	}
	return total;
}

double sommeDouble(vector<double>t){
	double total= 0;
	for(int i = 0; i < t.size(); i++){
		total = total + t[i];
	}
	return total;
}

int sommePartielle(vector<int> t, int i) {
	int total = 0;
	for(int j=i;j< t.size(); j++){
		total = total + t[j];
	}
	return total;  
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
	ifstream document(nom_fichier);
    vector<vector<int>> t;
	int a;
	//Il faut remplacer 20 par le nombre de ligne du fichier
    vector<int> tab(nb_colonnes);
	while(document >> a){
tab[0]=a;
		for(int i = 1; i < nb_colonnes; i++){
				document >> a;
       		 tab[i] = a;
		}
	t.push_back(tab);
	}
return t;
}

vector<int> colonne(vector<vector<int>> t, int i) {
    vector<int> m;
	m = vector<int>(t.size());
	for(int j = 0; j < t.size(); j++){
		m[j] = t[j][i];
	}
	return m;
}
