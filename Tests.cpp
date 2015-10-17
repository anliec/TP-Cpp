/* 3 - */void manualRetirerTest(unsigned int containerSize)
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

/* 5 - */void containerAjusterTest(unsigned int containerSize)
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

