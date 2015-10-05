/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    début                : 05/10/2015
    copyright            : (C) 2015 par Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Réalisation de la classe <BoolContainer> (fichier BoolContainer.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "BoolContainer.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
int BoolContainer::Afficher()
// Algorithme :
//
{
    cout << "la taille utilisée est de: " << tailleUtilisee << " sur " << tailleDispo << " disponible" << endl << endl;
    for(int i=0 ; i<tailleUtilisee ; i++)
    {
        cout << " -valeur n°" << i << ": " << tab[i] << endl;
    }
    return 0;
} //----- Fin de Méthode

int BoolContainer::Ajouter(bool b)
// Algorithme :
//
{
    if(tailleDispo == tailleUtilisee)
    {
        if(Ajuster(tailleDispo+1) != 0)
        {
            return 101; //code erreur: échec du redimentionnement du tableau
        }
    }
    tab[tailleUtilisee]=b;
    tailleUtilisee++;
    return 0;
} //----- Fin de Méthode

int BoolContainer::Retirer(unsigned int debut,unsigned int longueur)
// Algorithme :
//
{
    if(debut+longueur >= tailleUtilisee){
        return 102; //code erreur: l'utilisateur demande de supprimer des éléments en dehors de la collection
    }
    bool * nouveauTableau = new bool[tailleUtilisee-longueur];
    int positionCourante = 0;
    for(int i=0 ; i<tailleUtilisee ; i++)
    {
        if(i<debut || i>debut+longueur)
        {
            nouveauTableau[positionCourante] = tab[i];
            positionCourante++;
        }
    }
    delete [] tab;
    tab = nouveauTableau;
    return 0;
} //----- Fin de Méthode

int BoolContainer::Ajuster(unsigned int nouvelletaille)
// Algorithme :
//
{
    if(nouvelletaille <= tailleUtilisee)
    {
        return 100; //code erreur: ajustement impossible à cette taille de manière intuitive
    }
    bool * ansTab = tab;
    tab = new bool[nouvelletaille];
    tailleDispo = nouvelletaille;
    for(int i=0 ; i<tailleUtilisee ; i++)
    {
        tab[i] = ansTab[i];
    }
    delete [] ansTab;
    return 0;
} //----- Fin de Méthode

int BoolContainer::Reunir(BoolContainer boolContainerBis)
// Algorithme :
//
{
    if(Ajuster(tailleDispo+1) != 0)
    {
        return 101; //code erreur: échec du redimentionnement du tableau
    }
    for(int i=0; i<boolContainerBis.tailleUtilisee; i++)
    {
        tab[tailleUtilisee+i] = boolContainerBis.tab[i];
    }
    return 0;
} //----- Fin de Méthode

/*
//------------------------------------------------- Surcharge d'opérateurs
BoolContainer & BoolContainer::operator = ( const BoolContainer & unBoolContainer )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
BoolContainer::BoolContainer ( const BoolContainer & unBoolContainer )
// Algorithme :
//
{
#ifdef MAP
cout << "Appel au constructeur de copie de <BoolContainer>" << endl;
#endif
} //----- Fin de BoolContainer (constructeur de copie)
*/

BoolContainer::BoolContainer (unsigned int nouvelleTaille) : tailleDispo(nouvelleTaille)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur par défaut de <BoolContainer>" << endl;
    #endif
    tailleUtilisee = 0;
    tab = new bool[tailleDispo];
} //----- Fin de BoolContainer

BoolContainer::BoolContainer (bool newTab[],unsigned int newTaille) : tailleDispo(newTaille), tailleUtilisee(newTaille)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <BoolContainer>" << endl;
#endif
    tab = new bool[tailleDispo];
    for(int i=0; i<tailleDispo; i++)
    {
        tab[i]=newTab[i];
    }
} //----- Fin de BoolContainer


BoolContainer::~BoolContainer ( )
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au destructeur de <BoolContainer>" << endl;
    #endif
    delete tab;
} //----- Fin de ~BoolContainer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

