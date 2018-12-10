#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;
/** Calcule et affiche le volume d'eau total distribué à Paris en 2011 **/
int main() {
ifstream volume;
volume.open("donnees/volumes_d_eau_distribues.txt");
	int mois;
	int quantite;
	int total = 0;
	while(volume >> mois && volume >> quantite){
		total = total + quantite;
	}
	cout << "Le volume total d'eau distribué dans l'année est de : " << total << " L" << endl;
	volume.close();
}
