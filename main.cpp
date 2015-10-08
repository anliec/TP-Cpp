#include <iostream>
#include "BoolContainer.h"

using namespace std;

int main() {
    BoolContainer tab1(2);
    for(int i=0 ; i<10 ; i++)
    {
        tab1.Ajouter(i%2);
    }

    /*for (int i = 49; i > 0; i-=2) {
        tab1.Retirer(i);
    }*/
    tab1.Afficher();
    tab1.Retirer(0,5);
    tab1.Afficher();
}