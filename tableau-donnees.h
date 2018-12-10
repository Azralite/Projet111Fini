/** @file **/
#include <vector>
#include <string>
using namespace std;

/** Moyenne d'un tableau
 * @param t un tableau d'entiers
 * @result la moyenne de ces entiers
 **/
int moyenne(vector<int> t);

/** Somme d'un tableau
 * @param t un tableau d'entiers
 * @result la somme de ces entiers
 **/
int somme(vector<int> t);

/** Somme d'un tableau de doubles
 * @param y un tableau de doubles
 * @result le resultat de ces doubles
 **/
double sommeDouble(vector<double> t);

/** Somme partielle d'un tableau
 * @param t un tableau d'entiers
 * @result la somme des entiers à partir de l'indice i
 **/
int sommePartielle(vector<int> t, int i);

/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
int indiceMax(vector<int> t);

/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<int>> litTableauInt(string fichier, int nb_colonnes);

/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param i un numéro de colonne
 * @return la colonne i, représentée par un vecteur d'entiers
 **/
vector<int> colonne(vector<vector<int>> t, int i);
