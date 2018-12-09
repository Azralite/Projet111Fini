#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/** Calcule et affiche le mois et le voume où le volume d'eau
* distribué à Paris en 2011 a été maximal **/
int main() {
	ifstream volume ("donnees/volumes_d_eau_distribues.txt");
	int mois;
	int quantite;
	int pireMois = 0;
	int volMax = 0;
	vector<string> nomMois;
	nomMois = vector<string>(12);
	nomMois[0] = "Janvier";
	nomMois[1] = "Fevrier";
	nomMois[2] = "Mars";
	nomMois[3] = "Avril";
	nomMois[4] = "Mai";
	nomMois[5] = "Juin";
	nomMois[6] = "Juillet";
	nomMois[7] = "Aout";
	nomMois[8] = "Septembre";
	nomMois[9] = "Octobre";
	nomMois[10] = "Novembre";
	nomMois[11] = "Decembre";
	
	while(volume >> mois && volume >> quantite){
		if( quantite > volMax){
			volMax = quantite;
			pireMois = mois;
		}
	}
	cout << "Le mois où le plus grand volume d'eau a été distribué en 2011 est le mois de ";
	cout <<  nomMois[pireMois - 1] << " avec une consomation de " << volMax << " litres." << endl;
	
}
