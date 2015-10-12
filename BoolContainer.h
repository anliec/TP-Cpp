/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    debut                : 05/10/2015
    copyright            : (C) 2015 par Edern Haumont & Nicolas Six
*************************************************************************/

//---------- Interface de la classe <BoolContainer> (fichier ${file_name}) ------
#if ! defined ( BOOLCONTAINER_H )
#define BOOLCONTAINER_H

//------------------------------------------------------------- Constantes

const int DEFAULT_CONTAINER_SIZE = 10;

//------------------------------------------------------------------------ 
// La classe BoolContainer permet de definir des objet dont le but est de contenir des booleens
// La capacit� d'un BoolContainer est dynamique
// La classe supporte les modifications sur son contenu via des methodes dediees
//------------------------------------------------------------------------ 

class BoolContainer
{
//----------------------------------------------------------------- PUBLIC

public:

    //----------------------------------------------------- Methodes publiques
    int Afficher(bool afficherCarateristique = true, bool afficherContenue = true) const;
    // Mode d'emploi :
    // Affiche la capacit� utilis�e et disponible ainsi que le contenu du BoolContainer
    // Contrat :
    //

    int Ajouter(bool b);
    // Mode d'emploi :
    // entrer en parametre le booleen qui sera ajoute e la fin de la liste
    // Contrat :
    //

    int Retirer(unsigned int debut, unsigned int longueur = 1);
    // Mode d'emploi :
    // entrer l'index e partir duquel la suppression aura lieu
    // parametre optionnel, la longueur de l'intervalle d'index sur leque les suppressions auront lieu
    // Contrat :
    //

    int Ajuster(unsigned int nouvelletaille);
    // Mode d'emploi :
    // entrer en parametre la taille de collection desiree (superieure e la taille utilisee actuellement)
    // Contrat :
    //

    int Reunir(const BoolContainer & boolContainerBis);
    // Mode d'emploi :
    // entrer en parametre une autre collection de booleens qui sera ajoutee e la fin de la collection courante
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
    // entrer en parametre optionnel la taille de la nouvelle collection
    // Contrat :
    //

    BoolContainer(bool nouveauTab[],unsigned int nouvelleTaille);
    // Mode d'emploi :
    // entrer en parametre un tableau statique de booleens qui sera copie et sa taille
    // Contrat :
    // nouveauTab est de taille superieur ou égale à nouvelleTaille (si sa taille est supérieure
    // à nouvelle taille seuls les élléments des case entre 0 et nouvelleTaille exclue seront
    // copie dans le tableau)

virtual ~BoolContainer ( );

//------------------------------------------------------------------ PRIVE 

private:

    unsigned int tailleUtilisee;
    unsigned int tailleDispo;
    bool *tab;
//------------------------------------------------------- Attributs prives
}; // class BoolContainer

#endif // BOOLCONTAINER_H
