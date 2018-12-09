#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	ifstream fichier("donnees/volumes_d_eau_distribues.csv");
	string entete;
	getline(fichier, entete);
	char mots;
	string mois_str;
	string volume_str;
	int volume;
	int volumeTotal = 0;
	while(fichier >> mots){
	getline(fichier, mois_str, ';');
	getline(fichier, volume_str);
	if ( volume_str.size() > 0)
        		volume_str.resize(volume_str.length() - 1);
	istringstream(volume_str) >> volume;
	volumeTotal = volumeTotal + volume;
	}
	cout << "Le volume total d'eau distribué est de " << volumeTotal << " L"  << endl;
	
}
