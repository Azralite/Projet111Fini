#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Affiche
 * - le volume d'eau total sur l'année
 * - la moyenne par mois
 * - le mois avec le plus gros volume d'eau et son volume
 **/
int main() {
    vector<vector<int>> t = litTableauInt("donnees/volumes_d_eau_distribues.txt", 2);
	vector<int> m = colonne(t, 1);
	int volTotal = somme(m);
	int moy = moyenne(m);
	string mois;
	int moisMax = t[indiceMax(m)][0];
	switch (moisMax){
		case 1: mois = "janvier";
		break;
		case 2: mois = "fevrier";
		break;
		case 3: mois = "mars";
		break;
		case 4: mois = "avril";
		break;
		case 5: mois = "mai";
		break;
		case 6: mois = "juin";
		break;
		case 7: mois = "juillet";
		break;
		case 8: mois = "aout";
		break;
		case 9: mois = "septembre";
		break;
		case 10: mois = "octobre";
		break;
		case 11: mois = "novembre";
		break;
		case 12: mois = "décembre";
		break; 
		default : mois = "erreur";
	}
	cout << "Le volume d'eau total distribué est de : " << volTotal << " L" << endl;
	cout << "Le volume moyen d'eau distribué est de : " << moy << " L" <<endl;
	cout << "Le mois où l'on a distribué le plus d'eau est " << mois << " avec " << t[indiceMax(m)][1] << " L" << endl;	
}
