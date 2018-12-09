#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<int> c = { 1, 5, 3, 5, 1 };
vector<vector<int>> t = { {1, 2}, {2,4}, {3,1}, {0,0} };

void testMoyenne() {
    ASSERT( moyenne(c) == 3 );
}

void testSomme() {
    ASSERT( somme({}) == 0 );
    ASSERT( somme(c)  == 15 );
}

void testSommePartielle() {
    ASSERT( sommePartielle(c,0) == 15);
    ASSERT( sommePartielle(c,1) == 14);
    ASSERT( sommePartielle(c,2) == 9);
    ASSERT( sommePartielle(c,5) == 0);
}


void testIndiceMax() {
    ASSERT( indiceMax(c) == 1 );
	ASSERT( indiceMax({}) == -1);
}

void testLitTableauInt() {
    ASSERT( litTableauInt("donnees/volumes_d_eau_distribues.txt", 2) ==
            vector<vector<int>>({
                    {  4, 15688700 },
                    {  7, 16049700 },
                    {  3, 16260600 },
                    {  6, 17028600 },
                    {  9, 16858200 },
                    { 12, 15530100 },
                    {  2, 14019000 },
                    {  8, 13959600 },
                    {  1, 16231200 },
                    { 10, 16592900 },
                    { 11, 15672000 },
                    {  5, 17711200 },
            }) );
}

void testColonne() {
    ASSERT( colonne(t, 1) == vector<int>({2,4,1,0}));
    ASSERT( colonne(t, 0) == vector<int>({1,2,3,0}));
}

int main() {
    cout << "Lancement des tests de moyenne:" << endl;
    testMoyenne();
    cout << "Lancement des tests de somme:" << endl;
    testSomme();
    cout << "Lancement des tests de indiceMax:" << endl;
    testIndiceMax();
    cout << "Lancement des tests de litTableauInt:" << endl;
    testLitTableauInt();
    cout << "Lancement des tests de colonne:" << endl;
    testColonne();
}
