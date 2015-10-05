/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <BoolContainer> (fichier ${file_name}) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <BoolContainer>
//
//
//------------------------------------------------------------------------ 

class BoolContainer
{
//----------------------------------------------------------------- PUBLIC

public:

    //----------------------------------------------------- Méthodes publiques
    int Afficher();
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Ajouter(bool b);
    // Mode d'emploi :
    // entrer en paramètre le booléen qui sera ajouté à la fin de la liste
    // Contrat :
    //

    int Retirer(unsigned int debut, unsigned int longueur = 1);
    // Mode d'emploi :
    // entrer l'index à partir duquel la suppression aura lieu
    // paramètre optionnel, la longueur de l'intervalle d'index sur leque les suppressions auront lieu
    // Contrat :
    //

    int Ajuster(unsigned int nouvelletaille);
    // Mode d'emploi :
    // entrer en paramètre la taille de collection désirée (supèrieure à la taille utilisée actuellement)
    // Contrat :
    //

    int Reunir(BoolContainer boolContainerBis);
    // Mode d'emploi :
    // entrer en paramètre une autre collection de booléens qui sera ajoutée à la fin de la collection courante
    // Contrat :
    //




    //------------------------------------------------- Surcharge d'opérateurs
    BoolContainer & operator = ( const BoolContainer & unBoolContainer );
    // Mode d'emploi :
    // Non implémenté
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    BoolContainer ( const BoolContainer & unBoolContainer );
    // Mode d'emploi (constructeur de copie) :
    // Non implémenté
    // Contrat :
    //

    BoolContainer(unsigned int nouvelleTaille = 10);
    // Mode d'emploi :
    // entrer en paramètre optionnel la taille de la nouvelle collection
    // Contrat :
    //

    BoolContainer(bool newTab[],unsigned int newTaille);
    // Mode d'emploi :
    // entrer en paramètre un tableau statique de booléens qui sera copié et sa taille
    // Contrat :
    //

virtual ~BoolContainer ( );
// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:

    unsigned int tailleUtilisee;
    unsigned int tailleDispo;
    bool *tab;
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <BoolContainer>

#endif // XXX_H
