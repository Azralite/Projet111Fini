/** @file **/
#include <vector>
#include <string>
using namespace std;

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<string>> litTableauCSV(string fichier, int nb_colonnes);

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<string>> litTableauCSV(string fichier);

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau);

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/
void afficheTableau(vector<vector<string>> tableau);

/** Extraction d'une colonne d'un tableau 2D de chaînes de caractères
 * @param t un tableau 2D de chaînes de caractères
 * @param i un numéro de colonne
 * @return la colonne i, représentée par un vecteur
 **/
vector<string> colonne(vector<vector<string>> t, int i);

/** Conversion d'un vecteur de chaînes de caractères en vecteur d'entiers
 * @param t un vecteur de chaînes de caractères
 * @return le vecteur, converti en vecteur d'entiers
 **/
vector<int> conversionInt(vector<string> t);

/** Conversion d'un vecteur de chaînes de caractères en vecteur de doubles
 * @param t un vecteur de chaînes de caractères
 * @return le vecteur, converti en vecteur de doubles
 **/
vector<double> conversionDouble(vector<string> t);

/** Conversion en vecteur de valeurs de type T
 * @param t un vecteur de chaînes de caractères
 * @return le vecteur, converti en vecteur de T
 **/
template<class T>
vector<T> conversion(vector<string> t);
