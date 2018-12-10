#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
#include "tableau-donnees-csv.h"
using namespace std;

int main(){
	vector<vector<string>> tab = litTableauCSV("donnees/tonnages_des_dechets_bacs_jaunes.csv", 14);
	afficheTableau(tab);	
// Pour la ligne tout paris il y a un probleme avec les milliers et les centaines
	vector<double> totalAr;
	for(int j =0; j < tab.size(); j++){
		vector<string> ligne_str;
		for(int i =1; i < tab[0].size()-1; i++){
			ligne_str.push_back(tab[j][i]);
		}
		vector<double> ligne = conversionDouble(ligne_str);
		totalAr.push_back(sommeDouble(ligne));
	}
	for(int i =0; i < totalAr.size(); i++){
		cout << totalAr[i] << " ";
	}
	cout << endl; 
	return 0;
}
