#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.h"
#include "tableau-donnees-csv.h"
using namespace std;
int indiceMin(vector<int> t){
	int valeurMin = t[0];
	int rangMin = 0;
	if(t.size() == 0){
		return -1;
	}
	for(int i = 0; i < t.size() ; i++){
		if (t[i] < valeurMin){
			valeurMin = t[i];
			rangMin= i;
		}	
	}
	return rangMin;
}


int main() {
	vector<vector<string>> tab;
	tab = litTableauCSV("donnees/arbresremarquablesparis2011.csv");
	vector<string> hauteur_str = colonne(tab, 6);
	hauteur_str[0] = "0";
	vector<int> hauteur =	conversionInt(hauteur_str);
	int hauteurMax = hauteur[indiceMax(hauteur)];
	cout << "La hauteur maximal atteinte par un arbre à Paris est de: " << hauteurMax << " m." << endl;
	cout << "Son genre est " << tab[indiceMax(hauteur)][2] << " et son espèce est " << tab[indiceMax(hauteur)][3] << endl;
	//Quel est l'arbre le plus vieux
	vector<string> age_str = colonne(tab, 5);
	vector<int> datePlantation = conversionInt(age_str);
	int ageMax = 2018- datePlantation[indiceMin(datePlantation)];
	cout << "L'arbre le plus vieux a : " << ageMax << " ans, il a donc été planté en " << -ageMax+2018 << endl;
	cout << "Son genre est " << tab[indiceMin(datePlantation)][2] << " et son espèce est " << tab[indiceMin(datePlantation)][3] << endl;
	return 0;
}
