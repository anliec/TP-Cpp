/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    debut                : 05/10/2015
    copyright            : (C) 2015 par Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Realisation de la classe <BoolContainer> (fichier BoolContainer.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "BoolContainer.h"
#include "errorCode.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
int BoolContainer::Afficher() const
// Algorithme :
// Affiche les tailles utilisees et disponibles
// Affiche une a une les valeurs du tableau
{
    cout << "la taille utilisee est de: " << tailleUtilisee << " sur " << tailleDispo << " disponible" << endl << endl;
    for(int i=0 ; i<tailleUtilisee ; i++)
    {
        cout << " -valeur ne" << i << ": " << tab[i] << endl;
    }
    return 0;
} //----- Fin de Methode

int BoolContainer::Ajouter(bool b)
// Algorithme :
// Ajustement de la taille du tableau si elle n'est pas suffisante
// Mise a jour des variables
{
    if(tailleDispo == tailleUtilisee)
    {
        if(Ajuster(tailleDispo+1) != 0)
        {
            return ERROR_RESIZE_FAILED; //code erreur: echec du redimentionnement du tableau
        }
    }
    tab[tailleUtilisee]=b;
    tailleUtilisee++;
    return 0;
} //----- Fin de Methode

int BoolContainer::Retirer(unsigned int debut,unsigned int longueur)
// Algorithme :
// utilisation d'un pointeur pointant vers le nouveau tableau
// copie un a un des elements de l'ancien vers le nouveau tableau sauf celles a eliminer
// destruction de l'ancien tableau
{
    if(debut+longueur > tailleUtilisee){
        return ERROR_OUT_OF_BOUNDARY; //code erreur: l'utilisateur demande de supprimer des elements en dehors de la collection
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
} //----- Fin de Methode

int BoolContainer::Ajuster(unsigned int nouvelletaille)
// Algorithme :
// utilisation d'un pointeur tampon qui permet de conserver le tableau d'origine
// copie une a une des valeurs du tableau vers un nouveau tableau de taille ajustee
// destruction du tableau d'origine via le pointeur tampon
{
    if(nouvelletaille <= tailleUtilisee)
    {
        return ERROR_NON_INTUITIVE_ADJUSTMENT; //code erreur: ajustement impossible a cette taille de maniere intuitive
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
} //----- Fin de Methode

int BoolContainer::Reunir(const BoolContainer & boolContainerBis)
// Algorithme :
// Appel a la fonction d'ajustement de taille
// copie valeur par valeur des variables du tableau du BoolContainer passe en parametre vers tab
{
    if(Ajuster(tailleUtilisee+boolContainerBis.tailleUtilisee) != 0)
    {
        return ERROR_RESIZE_FAILED; //code erreur: echec du redimentionnement du tableau
    }
    for(int i=0; i<boolContainerBis.tailleUtilisee; i++)
    {
        //tab[tailleUtilisee+i] = boolContainerBis.tab[i];
        Ajouter(boolContainerBis.tab[i]);
    }
    return 0;
} //----- Fin de Methode

/*
//------------------------------------------------- Surcharge d'operateurs
BoolContainer & BoolContainer::operator = ( const BoolContainer & unBoolContainer )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur

BoolContainer::BoolContainer (unsigned int nouvelleTaille) : tailleDispo(nouvelleTaille)
// Algorithme :
//
{
    #ifdef MAP
    cout << "Appel au constructeur par defaut de <BoolContainer>" << endl;
    #endif
    tailleUtilisee = 0;
    tab = new bool[tailleDispo];
} //----- Fin de BoolContainer

BoolContainer::BoolContainer (bool newTab[],unsigned int newTaille) : tailleDispo(newTaille), tailleUtilisee(newTaille)
// Algorithme :
// copie valeur par valeur du tableau passe en parametre vers tab
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
{
    #ifdef MAP
    cout << "Appel au destructeur de <BoolContainer>" << endl;
    #endif
    delete [] tab;
} //----- Fin de ~BoolContainer
