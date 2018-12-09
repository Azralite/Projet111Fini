#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Construction d'un tableau d'entiers lu depuis un fichier
 * On suppose que le fichier contient sur chaque ligne un numéro de mois
 * suivi d'une donnée correspondant au mois.
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers de taille 12 tel que dans chaque
 * case d'indice i, on trouve la donnée du mois i
 **/
vector<int> litTableauMois(string nom_fichier) {
	ifstream fichier(nom_fichier);
	vector<int> tab;
	tab =vector<int> (12);
	for(int i=0; i <12; i++){
		tab[i]=0;
	}	
	int mois;
	int quantite;
	while(fichier >> mois && fichier >> quantite){
		tab[mois-1] = quantite;
	}
	return tab;
}

/** Test de la fonction litTableauMois **/
void testLitTableauMois() {
    vector<int> t = litTableauMois("donnees/volumes_d_eau_distribues.txt");
    ASSERT(t[0] == 16231200); // Le volume pour janvier
    ASSERT(t[11] == 15530100); // Le volume pour décembre
    ASSERT(t[4] == 17711200); //Le volume pour mai
}



/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs
 **/
int somme(vector<int> t) {
	int total = 0;
    for(int i=0;i< t.size(); i++){
		total = total + t[i];
	}
	return total;
}

/** Test de la fonction somme **/
void testSomme() {
    ASSERT(somme({1,2,3}) == 6);
    ASSERT(somme({}) == 0);
    ASSERT(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 **/
int moyenne(vector<int> t) {
    int moyenne = 0;
    for(int i=0;i< t.size(); i++){
		moyenne = moyenne + t[i];
	}
	moyenne = moyenne / t.size();
	return moyenne;
}

/** Test de la fonction moyenne **/
void testMoyenne() {
    ASSERT(moyenne({1,2,3}) == 2);
    ASSERT(moyenne({1}) == 1);
    ASSERT(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
int indiceMax(vector<int> t) {
    int valeurMax = 0;
	int rangMax = 0;
	if(t.size() == 0){
		return -1;
	}
	for(int i = 0; i < t.size() ; i++){
		if (t[i] > valeurMax){
			valeurMax = t[i];
			rangMax= i;
		}	
	}
	return rangMax;
}

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
    ASSERT(indiceMax({}) == -1);
    ASSERT(indiceMax({1,2,3}) == 2);
    ASSERT(indiceMax({1,3,2}) == 1);
    ASSERT(indiceMax({1}) == 0);
    ASSERT(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le volume d'eau total sur l'année
 * - la moyenne par mois
 * - le mois avec le plus gros volume d'eau et son volume
 **/
int main() {
	testLitTableauMois();
	testSomme();
	testMoyenne();
	testIndiceMax();

	int Somme;
	int Moyenne;
	int moisMax;
	string mois;
	vector<int> tab;
	tab = litTableauMois("donnees/volumes_d_eau_distribues.txt");
	Somme = somme(tab);
	Moyenne = moyenne(tab);
	moisMax = indiceMax(tab);
	switch (moisMax){
		case 0: mois = "Janvier";
		break;
		case 1: mois = "Fevrier";
		break;
		case 2: mois = "Mars";
		break;
		case 3: mois = "Avril";
		break;
		case 4: mois = "Mai";
		break;
		case 5: mois = "Juin";
		break;
		case 6: mois = "Juillet";
		break;
		case 7: mois = "Aout";
		break;
		case 8: mois = "Septembre";
		break;
		case 9: mois = "Octobre";
		break;
		case 10: mois = "Novembre";
		break;
		case 11: mois = "Décembre";
		break; 
		default : mois = "Erreur";
	}
	cout << "Le volume total d'eau distribué dans l'année est de :" << Somme << "L" << endl;
	cout << "Le volume moyen par mois d'eau distribué dans l'année est de :" << Moyenne << "L" << endl;
	cout << "Le mois où l'on a distribué le plus d'eau est " << mois << " avec un volume de " << tab[moisMax] <<"L" << endl;

}
