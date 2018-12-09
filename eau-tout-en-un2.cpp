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
	int moisMax = t[indiceMax(m)][0];
	cout << "Somme = " << volTotal << endl;
	cout << "Moyenne = " << moy << endl;
	cout << "Le mois max est " << moisMax << " avec " << t[indiceMax(m)][1] << endl;	
}
