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
	string mois_str;
	string mois_strMax;
	string volume_str;
	int volume;
	int volumeMax = 0;
	while(fichier){
	getline(fichier, mois_str, ';');
	getline(fichier, volume_str);
	//if ( volume_str.size() > 0 and volume_str[volume_str.length()-1] == '\r')
        //		volume_str.resize(volume_str.length() - 1);
	istringstream(volume_str) >> volume;
	if(volume > volumeMax){
		volumeMax = volume;
		mois_strMax = mois_str;
	}
	}
	cout << "Le volume maximal d'eau distribué est de " << volumeMax << " L"  << " en " << mois_strMax << endl;
}
