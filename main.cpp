#include <iostream>
#include "BoolContainer.h"

#define TEST_ERROR_MESSAGE "\e[1;31m[Failed]\e[0m"
#define TEST_SUCESS_MESSAGE "\e[1;32m[OK]\e[0m"

using namespace std;

void selfTesting();
void containerSizeTest(unsigned int containerSize, bool testOverflow =false);
void containerAjusterTest(unsigned int containerSize);

void manualTesting();
void manualAjouterTest(unsigned int containerSize);
void manualRetirerTest(unsigned int containerSize);
void manualReunirTest(unsigned int containerSize);
void manualConstructorTest(unsigned int containerSize);

int main()
{
    manualTesting();
    selfTesting();
}

void selfTesting()
{
    /*cout << "Test de taille: ";
    containerSizeTest(200);*/
    cout << "Test d'overflow: ";
    containerSizeTest(200, true);
    cout << "Test de Ajuster: ";
    containerAjusterTest(200);
}

/* 4 - */void containerSizeTest(unsigned int containerSize, bool testOverflow)
{
    unsigned usedSize = 1;
    if(!testOverflow)
    {
        usedSize = containerSize;
    }
    for(unsigned n=0 ; n< usedSize; n++)
    {
        BoolContainer booleanTab(usedSize);
        //remplie le tableau de vrais pour les n première case puis de faux
        for(unsigned i=0 ; i< usedSize; i++)
        {
            if(booleanTab.Ajouter(i<n) != 0)
            {
                cout << TEST_ERROR_MESSAGE << endl;
                return;
            }
        }
        //vérifie que les donnée retirer corespondent au données envoyer
        for(unsigned i=0 ; i< usedSize; i++)
        {
            if(booleanTab.Retirer(0) != 0)
            {
                cout << TEST_ERROR_MESSAGE << endl;
                return;
            }
        }
    }
    BoolContainer booleanTab(usedSize);
    //test en alternance:
    for(int i=0 ; i< usedSize; i++)
    {
        booleanTab.Ajouter(i%2);
    }
    for(unsigned i=0 ; i< usedSize; i++)
    {
        if(booleanTab.Retirer(0) != 0)
        {
            cout << TEST_ERROR_MESSAGE << endl;
            return;
        }
    }
    cout << TEST_SUCESS_MESSAGE << endl;
}


/* 6 -*/void containerAjusterTest(unsigned int containerSize)
{
    bool tab[containerSize];
    BoolContainer booleanTab(tab,containerSize);
    for (unsigned i = 0; i < 2*containerSize; ++i) {
        if( (booleanTab.Ajuster(i) == 0 && i<containerSize) || (booleanTab.Ajuster(i) != 0 && i>=containerSize))
        {
            cout << TEST_ERROR_MESSAGE << i << " " << booleanTab.Ajuster(i) << endl;
            return;
        }
    }
    cout << TEST_SUCESS_MESSAGE << endl;
}

/// Manual test fonctions:

void manualTesting()
{
    cout << "\e[1;31m/!\\ lors des entré texte veulliez ne donnée qu'un seul caractère\e[0m" << endl <<endl;
    manualConstructorTest(20);
    manualAjouterTest(20);
    manualRetirerTest(20);
    manualReunirTest(20);
}
/* 1 - */void manualAjouterTest(unsigned int containerSize)
{
    BoolContainer boolContainer(0);
    cout << "Conteneur vide déclarer:" << endl;
    boolContainer.Afficher(false,true);
    cout << "remplisage du conteneur avec une alternance de 1 et 0 commancant par 0" << endl;
    for(unsigned i=0 ; i<containerSize ; i++)
    {
        boolContainer.Ajouter(i%2);
    }
    boolContainer.Afficher(false,true);
    cout << "le résultat correspond t'il à ce qui était attendue ? [o/N] ";
    char userAnswer = 'n';
    cin >> userAnswer;
    if(userAnswer != 'o' && userAnswer != 'O')
    {
        cout << "test d'ajout à vérification manuel: " << TEST_ERROR_MESSAGE << endl << endl;
    }
    else
    {
        cout << "test d'ajout à vérification manuel: " << TEST_SUCESS_MESSAGE << endl << endl;
    }
}
/* 2 - */void manualRetirerTest(unsigned int containerSize)
{
    BoolContainer boolContainer(0);
    cout << "remplisage du conteneur avec une alternance de 1 et 0 commancant par 0" << endl;
    for(unsigned i=0 ; i<containerSize ; i++)
    {
        boolContainer.Ajouter(i%2);
    }
    boolContainer.Afficher(false,true);
    cout << "supression de la première valeur:" << endl;
    boolContainer.Retirer(0);
    boolContainer.Afficher(false,true);
    cout << "supression de la dernière valeur:" << endl;
    boolContainer.Retirer(containerSize-2);
    boolContainer.Afficher(false,true);
    cout << "les résultats correspondent t'ils à ce qui était attendue ? [o/N] ";
    char userAnswer = 'n';
    cin >> userAnswer;
    if(userAnswer != 'o' && userAnswer != 'O')
    {
        cout << "test de retirer pour un élément avec vérification manuel: " << TEST_ERROR_MESSAGE << endl << endl;
        return;
    }
    else
    {
        cout << "test de retirer pour un élément avec vérification manuel: " << TEST_SUCESS_MESSAGE << endl << endl;
    }

    BoolContainer boolContainer2(0);
    for(unsigned i=0 ; i<containerSize ; i++)
    {
        boolContainer2.Ajouter(i<(containerSize/2));
    }
    cout << "creation du conteneure replie de 1 de 0 à " << ((containerSize/2)-1) << " et de 0 ensuite" << endl;
    boolContainer2.Afficher(false,true);
    cout << "suppression des valeurs de 0 à " << ((containerSize/2)-1) << ":" << endl;
    boolContainer2.Retirer(0,containerSize/2);
    boolContainer2.Afficher(false,true);
    cout << "les résultats correspondent t'ils à ce qui était attendue ? [o/N] ";
    userAnswer = 'n';
    cin >> userAnswer;
    if(userAnswer != 'o' && userAnswer != 'O')
    {
        cout << "test de retirer pour un élément avec vérification manuel: " << TEST_ERROR_MESSAGE << endl << endl;
        return;
    }
    else
    {
        cout << "test de retirer pour un élément avec vérification manuel: " << TEST_SUCESS_MESSAGE << endl << endl;
    }
}
/* 3 - */void manualReunirTest(unsigned int containerSize)
{
    BoolContainer boolContainer1(0);
    cout << "remplisage du conteneur n°1 de 1" << endl;
    for(unsigned i=0 ; i<containerSize/3 ; i++)
    {
        boolContainer1.Ajouter(1);
    }
    boolContainer1.Afficher(false,true);
    BoolContainer boolContainer2(0);
    cout << "remplisage du conteneur n°2 de 0" << endl;
    for(unsigned i=0 ; i<(containerSize*2)/3 ; i++)
    {
        boolContainer2.Ajouter(0);
    }
    boolContainer2.Afficher(false,true);
    cout << "reunion des deux conteneur, le n°2 étant à la fin du n°1" << endl;
    boolContainer1.Reunir(boolContainer2);
    boolContainer1.Afficher(false,true);
    cout << "le résultat correspond t'il à ce qui était attendue ? [o/N] ";
    char userAnswer = 'n';
    cin >> userAnswer;
    if(userAnswer != 'o' && userAnswer != 'O')
    {
        cout << "test de Reunir avec vérification manuel: " << TEST_ERROR_MESSAGE << endl << endl;
    }
    else
    {
        cout << "test de Reunir avec vérification manuel: " << TEST_SUCESS_MESSAGE << endl << endl;
    }
}

/* 5 - */void manualConstructorTest(unsigned int containerSize)
{
    bool baseBooleanTab[containerSize];
    cout << "construction d'un conteneur à l'aide du tableau:" << endl;
    for (int i = 0; i < containerSize; i++)
    {
        baseBooleanTab[i] = i%2;
        cout << baseBooleanTab[i] << " ";
    }
    cout << endl << "le conteneur optenue est:" <<endl;
    BoolContainer conteneur(baseBooleanTab,containerSize);
    conteneur.Afficher(false,true);
    cout << "le résultat correspond t'il à ce qui était attendue ? [o/N] ";
    char userAnswer = 'n';
    cin >> userAnswer;
    if(userAnswer != 'o' && userAnswer != 'O')
    {
        cout << "test du constructeur avec vérification manuel: " << TEST_ERROR_MESSAGE << endl << endl;
    }
    else
    {
        cout << "test du constructeur avec vérification manuel: " << TEST_SUCESS_MESSAGE << endl << endl;
    }
}















