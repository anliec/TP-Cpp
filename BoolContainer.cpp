/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    d�but                : 05/10/2015
    copyright            : (C) 2015 par Edern Haumont & Nicolas Six
*************************************************************************/

//---------- R�alisation de la classe <BoolContainer> (fichier BoolContainer.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "BoolContainer.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
int BoolContainer::Afficher() const
// Algorithme :
// Affiche les tailles utilis�es et disponibles
// Affiche une � une les valeurs du tableau
{
    cout << "la taille utilis�e est de: " << tailleUtilisee << " sur " << tailleDispo << " disponible" << endl << endl;
    for(int i=0 ; i<tailleUtilisee ; i++)
    {
        cout << " -valeur n�" << i << ": " << tab[i] << endl;
    }
    return 0;
} //----- Fin de M�thode

int BoolContainer::Ajouter(bool b)
// Algorithme :
// Ajustement de la taille du tableau si elle n'est pas suffisante
// Mise � jour des variables
{
    if(tailleDispo == tailleUtilisee)
    {
        if(Ajuster(tailleDispo+1) != 0)
        {
            return 101; //code erreur: �chec du redimentionnement du tableau
        }
    }
    tab[tailleUtilisee]=b;
    tailleUtilisee++;
    return 0;
} //----- Fin de M�thode

int BoolContainer::Retirer(unsigned int debut,unsigned int longueur)
// Algorithme :
// utilisation d'un pointeur pointant vers le nouveau tableau
// copie un � un des �lements de l'ancien vers le nouveau tableau sauf celles � �liminer
// destruction de l'ancien tableau
{
    if(debut+longueur >= tailleUtilisee){
        return 102; //code erreur: l'utilisateur demande de supprimer des �l�ments en dehors de la collection
    }
    bool * nouveauTableau = new bool[tailleUtilisee-longueur];
    int positionCourante = 0;
    for(int i=0 ; i<tailleUtilisee ; i++)
    {
        if(i<debut || i>=debut+longueur)
        {
            nouveauTableau[positionCourante] = tab[i];
            positionCourante++;
        }
    }
    delete [] tab;
    tab = nouveauTableau;
    tailleUtilisee -= longueur;
    tailleDispo = tailleUtilisee;
    return 0;
} //----- Fin de M�thode

int BoolContainer::Ajuster(unsigned int nouvelletaille)
// Algorithme :
// utilisation d'un pointeur tampon qui permet de conserver le tableau d'origine
// copie une � une des valeurs du tableau vers un nouveau tableau de taille ajust�e
// destruction du tableau d'origine via le pointeur tampon
{
    if(nouvelletaille <= tailleUtilisee)
    {
        return 100; //code erreur: ajustement impossible � cette taille de mani�re intuitive
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
} //----- Fin de M�thode

int BoolContainer::Reunir(const BoolContainer & boolContainerBis)
// Algorithme :
// Appel � la fonction d'ajustement de taille
// copie valeur par aleur des variables du tableau du BoolContainer pass� en param�tre vers tab
{
    if(Ajuster(tailleUtilisee+boolContainerBis.tailleUtilisee) != 0)
    {
        return 101; //code erreur: �chec du redimentionnement du tableau
    }
    for(int i=0; i<boolContainerBis.tailleUtilisee; i++)
    {
        //tab[tailleUtilisee+i] = boolContainerBis.tab[i];
        Ajouter(boolContainerBis.tab[i]);
    }
    return 0;
} //----- Fin de M�thode

/*
//------------------------------------------------- Surcharge d'op�rateurs
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
    cout << "Appel au constructeur par d�faut de <BoolContainer>" << endl;
    #endif
    tailleUtilisee = 0;
    tab = new bool[tailleDispo];
} //----- Fin de BoolContainer

BoolContainer::BoolContainer (bool newTab[],unsigned int newTaille) : tailleDispo(newTaille), tailleUtilisee(newTaille)
// Algorithme :
// copie valeur par valeur du tableau pass� en param�tre vers tab
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
    delete [] tab;
} //----- Fin de ~BoolContainer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es

