/*************************************************************************
                           BoolContainer  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <BoolContainer> (fichier ${file_name}) ------
#if ! defined ( XXX_H )
#define XXX_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// R�le de la classe <BoolContainer>
//
//
//------------------------------------------------------------------------ 

class BoolContainer
{
//----------------------------------------------------------------- PUBLIC

public:

    //----------------------------------------------------- M�thodes publiques
    int Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int Ajouter(bool b);
    // Mode d'emploi :
    // entrer en param�tre le bool�en qui sera ajout� � la fin de la liste
    // Contrat :
    //

    int Retirer(unsigned int debut, unsigned int longueur = 1);
    // Mode d'emploi :
    // entrer l'index � partir duquel la suppression aura lieu
    // param�tre optionnel, la longueur de l'intervalle d'index sur leque les suppressions auront lieu
    // Contrat :
    //

    int Ajuster(unsigned int nouvelletaille);
    // Mode d'emploi :
    // entrer en param�tre la taille de collection d�sir�e (sup�rieure � la taille utilis�e actuellement)
    // Contrat :
    //

    int Reunir(const BoolContainer & boolContainerBis);
    // Mode d'emploi :
    // entrer en param�tre une autre collection de bool�ens qui sera ajout�e � la fin de la collection courante
    // Contrat :
    //




    //------------------------------------------------- Surcharge d'op�rateurs
    BoolContainer & operator = ( const BoolContainer & unBoolContainer );
    // Mode d'emploi :
    // Non impl�ment�
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    BoolContainer ( const BoolContainer & unBoolContainer );
    // Mode d'emploi (constructeur de copie) :
    // Non impl�ment�
    // Contrat :
    //

    BoolContainer(unsigned int nouvelleTaille = 10);
    // Mode d'emploi :
    // entrer en param�tre optionnel la taille de la nouvelle collection
    // Contrat :
    //

    BoolContainer(bool newTab[],unsigned int newTaille);
    // Mode d'emploi :
    // entrer en param�tre un tableau statique de bool�ens qui sera copi� et sa taille
    // Contrat :
    //

virtual ~BoolContainer ( );
// Mode d'emploi :
//
// Contrat :
//

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:

    unsigned int tailleUtilisee;
    unsigned int tailleDispo;
    bool *tab;
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <BoolContainer>

#endif // XXX_H
