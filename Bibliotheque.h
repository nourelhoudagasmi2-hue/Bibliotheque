#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "Livre.h"
#include "Utilisateur.h"
#include "Emprunt.h"
#include <vector>

using namespace std;

class Bibliotheque
{
private:
    vector<Livre> livres;
    vector<Utilisateur*> utilisateurs;
    vector<Emprunt> emprunts;

public:
 ~Bibliotheque();
 
    void ajouterLivre(const Livre& livre);
    void afficherLivres() const;

    void ajouterLivre();

    Livre* rechercherLivre(int id);
    void modifierLivre(int id);
    void supprimerLivre(int id);

    void trierParTitre();
    
    void ajouterUtilisateur(Utilisateur* utilisateur);
    void afficherUtilisateurs() const;
    Utilisateur* rechercherUtilisateur(int id);

    void emprunterLivre(int idLivre, int idUtilisateur);
    void retournerLivre(int idLivre);
    void afficherEmprunts() const;
    
    const vector<Livre>& getLivres() const;
    vector<Livre>& getLivres();

    const vector<Utilisateur*>& getUtilisateurs() const;
    vector<Utilisateur*>& getUtilisateurs();

    const vector<Emprunt>& getEmprunts() const;
    vector<Emprunt>& getEmprunts();

};

#endif
