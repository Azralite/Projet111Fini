#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees-csv.h"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> donnees = {
                    { "avr-11", "15688700" },
                    { "juil-11", "16049700" },
                    { "mars-11", "16260600" },
                    { "juin-11", "17028600" },
                    { "sept-11", "16858200" },
                    { "déc-11", "15530100" },
                    { "févr-11", "14019000" },
                    { "août-11", "13959600" },
                    { "janv-11", "16231200" },
                    { "oct-11", "16592900" },
                    { "nov-11", "15672000" },
                    { "mai-11", "17711200" },
};

vector<vector<string>> petites_donnees = { { "a0", "b0"}, { "a1", "b1" } };

vector<string> conv = {"50", "2013", "26"};

void litTableauCSVTest() {
    ASSERT( litTableauCSV("donnees/volumes_d_eau_distribues.csv", 2) == donnees );
    ASSERT( litTableauCSV("donnees/volumes_d_eau_distribues.csv") == donnees );
}

void colonneTest() {
	ASSERT( colonne(litTableauCSV("donnees/volumes_d_eau_distribues.csv"), 1) == colonne(donnees, 1)); 
	ASSERT( colonne(litTableauCSV("donnees/volumes_d_eau_distribues.csv"), 0) == colonne(donnees, 0));	
}

void conversionTest() {
    ASSERT( conversionInt(conv) == vector<int>({50, 2013, 26})); 
	ASSERT( conversionDouble(conv) == vector<double>({50.0, 2013.0, 26.0}));
	//vector<int> tabint;
	//tabint = conversion<int>(conv);
	//vector<double> tabdouble;
	//tabdouble = conversion<double>(conv);
    //ASSERT( conversion<int>(conv) == tabint); 
	//ASSERT( conversion<double>(conv) == tabdouble);
}	

int main() {
    //afficheTableau(litTableauCSV("donnees/volumes_d_eau_distribues.csv", 2));
    //afficheTableau(litTableauCSV("donnees/volumes_d_eau_distribues.csv"));
    cout << "Lancement des tests de litTableauCSV:" << endl;
    litTableauCSVTest();
	cout << "Lancement des tests de colonne:" << endl;
	colonneTest();
    cout << "Lancement des tests de conversion:" << endl;
    conversionTest();
}
