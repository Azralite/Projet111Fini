#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Renvoie le tableau des dechets annuels par arrondissement
 * @param t un double tableau contenant sur chaque ligne l'arrondissement
 * suivi du tonnage des déchets par mois
 * @return un tableau ou chaque case i contient les déchets annuels
 * de l'arrondissement correspondant dans t
 **/
vector<int> dechetsAnnuels(vector<vector<int>> t) {
    vector<int> r;
    for(int i=0; i<t.size(); i++) {
        r.push_back(sommePartielle(t[i],1));
    }
    return r;
}


/**
 * Demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 * Puis, affiche pour l'année :
 * - la somme totale des dechets annuels
 * - la moyenne par arrondissement pour l'année
 * - l'arrondissement avec le plus de déchets pour l'année (et son tonnage annuel)
 **/
int main() {
    int mois;
	vector<vector<int>> t;
	cout << "Quel mois choisissez vous? (entre 1 et 12)" << endl;
	cin >> mois;
	t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt",13);
	vector<int> m;
	m = colonne(t,mois);
	int Somme = somme(m);
	float Moyenne = moyenne(m);
	int arMax = t[indiceMax(m)][0] - 75000;
	cout << "La somme de déchets pour ce mois est de : " << Somme << " tonnes." << endl;
	cout << "La moyenne par arrondissement de déchets pour ce mois est de : " << Moyenne << " tonnes."<< endl;
	cout << "L'arrondissement le plus polluant est le " << arMax <<"ème arrondissement avec " << t[indiceMax(m)][mois] <<" tonnes de déchets." << endl;
	vector<int> annuel = dechetsAnnuels(t);
	int sommeAnnee = somme(annuel);
	float moyenneAnnee = moyenne(annuel);	
	int arMaxAnnee = t[indiceMax(annuel)][0]-75000;
	cout << "La somme de déchets pour cette année est de : " << sommeAnnee << " tonnes." << endl;
	cout << "La moyenne par arrondissement de déchets pour cette année est de : " << moyenneAnnee << " tonnes."<< endl;
	cout << "L'arrondissement le plus polluant est le " << arMaxAnnee <<"ème arrondissement avec " << annuel[indiceMax(annuel)] <<" tonnes de déchets." << endl;
}
