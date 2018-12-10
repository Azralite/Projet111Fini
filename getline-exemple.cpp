#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream fichier("donnees/volumes_d_eau_distribues.csv");
    string entete;
    getline(fichier, entete);
    cout << "Entête: " << entete << endl;

    string mois;
    string volume_str;
    int volume;
    getline(fichier, mois, ';');
    getline(fichier, volume_str);

    // Sous windows, les fichiers texte utilisent deux
    // caractères pour chaque fin de ligne:
    // - '\r': retour au début de la ligne
    // - '\n': saut de ligne
    //
    // Apparemment le fichier de donnée a été créé par/pour Windows.
    // Si on l'utilise sous Linux, il faut supprimer le '\r' qui n'est pas
    // géré automatiquement par getline.
    if ( volume_str.size() > 0 and volume_str[volume_str.length()-1] == '\r' )
        volume_str.resize(volume_str.length() - 1);
    // Conversion du volume en entier
        istringstream(volume_str) >> volume;

    cout << "Mois: «" << mois << "»" << endl;
    cout << "Volume: «" << volume_str << "»" << endl;
    cout << "Volume (en entier): " << volume << endl;

    fichier.close();
    return 0;
}
