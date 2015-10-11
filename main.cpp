#include <iostream>
#include "BoolContainer.h"
#include "errorCode.h"

using namespace std;

int main() {
    BoolContainer tab1(50);
    int n=0;
    for(int i=0 ; i<50 ; i++)
    {
        tab1.Ajouter(i%2);
        n++;
    }
    cout << n<< endl;

    tab1.Afficher();

    n=0;
    for (int i = 49; i > 0; i-=2) {
        if(tab1.Retirer(i) == ERROR_OUT_OF_BOUNDARY)
        {
            cout << "error on i=" <<i<<endl;
        }
        n++;
    }
    cout << n <<endl;
    tab1.Afficher();
}