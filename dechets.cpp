#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include "tableau-donnees.h"
using namespace std;

/** Calcule et affiche l'arrondissement ayant le plus de déchets sur l'année
 * ainsi que son tonnage annuel **/
int main() {
	ifstream dechet("donnees/tonnages_des_dechets_bacs_jaunes.txt");
	vector<vector<int>> tableau;
	
	tableau = vector<vector<int>>(20);
	for(int i = 0; i <20; i++){
		tableau[i]=vector<int>(13);
	}

	vector<vector<int>> total;
	
	total = vector<vector<int>>(20);
	for(int i = 0; i <20; i++){
		total[i]=vector<int>(2);
	}
	
//	int arrondissement;
	int quantiteParAr=0;
	int quantite;
	int i =0;
	while(dechet >> quantite){
		tableau[i/13][i%13] = quantite;
		i++;
	}
	for(int i=0; i < 20; i++){
		for(int j =0; j < 13; j++){
		if ( j == 0){
			total[i][0]=tableau[i][0];
		}
		else{
			quantiteParAr = quantiteParAr + tableau[i][j];

		}
		}
	total[i][1] = quantiteParAr;
	quantiteParAr = 0;
	}
	
	int max = 0;
	int arMax;

	for(int i=0; i < 20; i++){
		if (total[i][1] > max){
			max = total[i][1];
			arMax = total[i][0];
		}
	}
	arMax = arMax -75000;
	cout << "Le " << arMax << "ème arrondissement a été le plus pollueur";
	cout << " avec un total de " << max << " Kg de déchets!" << endl;
	return 0;
			
}
