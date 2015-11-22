/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    debut                : 05/10/2015
    copyright            : (C) 2015 par Edern Haumont & Nicolas Six
*************************************************************************/

//---- Interface de la classe BoolContainer (fichier Boolcontainer.h) ----
#if ! defined ( BOOLCONTAINER_H )
#define BOOLCONTAINER_H

//------------------------------------------------------------- Constantes

const int DEFAULT_CONTAINER_SIZE = 10;

//------------------------------------------------------------------------ 
// La classe BoolContainer permet de definir des objet dont le but est de
// contenir des booleens. La capacite d'un BoolContainer est dynamique.
// La classe supporte les modifications sur son contenu via des methodes
// dediees
//------------------------------------------------------------------------ 

class BoolContainer
{
//----------------------------------------------------------------- PUBLIC

public:

    //----------------------------------------------------- Methodes publiques
    int Afficher(bool afficherCarateristique=true,bool afficherContenue=true) const;
    // Mode d'emploi :
    // Peut afficher la capacite utilisée et disponible suivie du contenu
    // du BoolContainer. Si le premier argument est vrais alors il y aura
    // affichage d'une ligne avec les caracterisitiques du tableau. Si le
    // segond est vrais alors il y aura affichage du contenue du tableau.
    // par défaut: affiche les deux bloques.
    // Contrat :
    //

    int Ajouter(bool b);
    // Mode d'emploi :
    // Prend en parametre le booleen qui sera ajoute a la fin de la liste.
    // Contrat :
    //

    int Retirer(unsigned int debut, unsigned int longueur = 1);
    // Mode d'emploi :
    // Prend en parametre l'index e partir auquel la suppression aura lieu
    // et en parametre optionnel, la longueur de l'intervalle d'index sur
    // lequel les suppressions auront lieu.
    // Contrat :
    //

    int Ajuster(unsigned int nouvelletaille);
    // Mode d'emploi :
    // Prend en parametre la taille de collection desiree
    // (superieure e la taille utilisee actuellement).
    // Contrat :
    //

    int Reunir(const BoolContainer & boolContainerBis);
    // Mode d'emploi :
    // Prend en parametre une autre collection de booleens qui sera ajoutee à
    // la fin de la collection courante.
    // Contrat :
    //




    //------------------------------------------------- Surcharge d'operateurs
    BoolContainer & operator = ( const BoolContainer & unBoolContainer );
    // Mode d'emploi :
    // Non implemente
    // Contrat :
    // TODO verifier si elle n'est pas a implementer


    //-------------------------------------------- Constructeurs - destructeur
    BoolContainer ( const BoolContainer & unBoolContainer );
    // Mode d'emploi (constructeur de copie) :
    // Non implemente
    // Contrat :
    //

    BoolContainer(unsigned int nouvelleTaille = DEFAULT_CONTAINER_SIZE);
    // Mode d'emploi :
    // Prend en parametre optionnel la taille de la nouvelle collection
    // Contrat :
    //

    BoolContainer(bool nouveauTab[],unsigned int nouvelleTaille);
    // Mode d'emploi :
    // Prend en parametre un tableau statique de booleens qui sera copie
    // et sa taille
    // Contrat :
    // nouveauTab est de taille superieur ou égale à nouvelleTaille
    // (si sa taille est supérieure à nouvelle taille seuls les élléments
    // des case entre 0 et nouvelleTaille exclue seront copié dans
    // le tableau)

    virtual ~BoolContainer ( );

//------------------------------------------------------------------ PRIVE 

private:

    unsigned int tailleUtilisee;
    unsigned int tailleDispo;
    bool *tab;
//------------------------------------------------------- Attributs prives
}; // class BoolContainer

#endif // BOOLCONTAINER_H
