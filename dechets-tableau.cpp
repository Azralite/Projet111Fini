#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl


/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {
    ifstream document(nom_fichier);
    vector<vector<int>> t;
	t = vector<vector<int>>(20);
	for(int i = 0; i < 20; i++){
		t[i] = vector<int>(nb_colonnes);
	}
    int chiffre;
    int compteur = 0;
    while(document >> chiffre){
		t[compteur/nb_colonnes][compteur%nb_colonnes] = chiffre;
		compteur++;
	}
	return t;

}

/** Test de la fonction litTableauInt **/
void testLitTableauInt() {
    vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);
    ASSERT(t[0][0] == 75007);
    ASSERT(t[3][5] == 876);
    ASSERT(t[19][12] == 235);
}

/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param j un numéro de colonne
 * @return la colonne j, représentée par un vecteur d'entiers
 **/
vector<int> colonne(vector<vector<int>> t, int j) {
    vector<int>m;
	m = vector<int>(t.size());
	for (int i = 0; i < t.size(); i++) { 
        m[i] = t[i][j];
	}  
	return m;
}

/** Test de la fonction colonne **/
void testColonne() {
    vector<vector<int>> t = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    ASSERT( colonne(t,0) == vector<int>({1,4,7,10}));
    ASSERT( colonne(t,1) == vector<int>({2,5,8,11}));
    ASSERT( colonne(t,2) == vector<int>({3,6,9,12}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
	int total = 0;
	for(int i=0;i< t.size(); i++){
		total = total + t[i];
	}
	return total;
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    int moyenne = 0;
    for(int i=0;i< t.size(); i++){
		moyenne = moyenne + t[i];
	}
	moyenne = moyenne / t.size();
	return moyenne;
}

/** copier la fonction indiceMax déjà écrite **/
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

/** Lance les tests de litTableauInt et colonne
 * puis demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 **/
int main() {
	int mois;
	vector<vector<int>> t;
   	testLitTableauInt();
	testColonne();
	cout << "Quel mois choisissez vous? (entre 1 et 12)" << endl;
	cin >> mois;
	if(mois < 1 || mois > 12){
		throw invalid_argument("Le mois doit être compris entre 1 et 12!  🤐 ");
	}
	t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt",13);
	vector<int> m;
	m = colonne(t,mois);
	string Mois;
switch (mois){
		case 1: Mois = "janvier";
		break;
		case 2: Mois = "fevrier";
		break;
		case 3: Mois = "mars";
		break;
		case 4: Mois = "avril";
		break;
		case 5: Mois = "mai";
		break;
		case 6: Mois = "juin";
		break;
		case 7: Mois = "juillet";
		break;
		case 8: Mois = "aout";
		break;
		case 9: Mois = "septembre";
		break;
		case 10: Mois = "octobre";
		break;
		case 11: Mois = "novembre";
		break;
		case 12: Mois = "décembre";
		break; 
		default : Mois = "ERREUR";
	}
	int Somme = somme(m);
	float Moyenne = moyenne(m);
	int arMax = t[indiceMax(m)][0] - 75000;
	cout << "La somme de déchets en "<< Mois << " est de : " << Somme << " tonnes." << endl;
	cout << "La moyenne par arrondissement de déchets en " << Mois << " est de : " << Moyenne << " tonnes."<< endl;
	cout << "L'arrondissement le plus polluant est le " << arMax <<"ème arrondissement avec " << t[indiceMax(m)][mois] <<" tonnes de déchets." << endl; 
	


}

