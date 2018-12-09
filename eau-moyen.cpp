#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;

/** Calcule et affiche le volume d'eau moyen distribué par mois à Paris en 2011 **/
int main() {
	ifstream volume("donnees/volumes_d_eau_distribues.txt");
	int mois;
	int quantite;
	int nbTotalMois = 0;
	int volTotal = 0;
	int moyenne;
	
	while( volume >> mois && volume >> quantite){
		nbTotalMois ++;
		volTotal = volTotal + quantite;
	}
	
	moyenne = volTotal / nbTotalMois;
	cout << moyenne << endl;
	volume.close();
	
}
