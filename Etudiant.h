#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Utilisateur.h"

class Etudiant : public Utilisateur
{
private:
    string filiere;
    int annee;

public:
    Etudiant();
    Etudiant(int id, string nom, string prenom,string etablissement, string filiere, int annee);

    void afficher() const override;

    string getFiliere() const;
    int getAnnee() const;

    void setFiliere(string nouvelleFiliere);
    void setAnnee(int nouvelleAnnee);
};

#endif
