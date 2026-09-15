#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "Utilisateur.h"

class Enseignant : public Utilisateur
{
private:
    string specialite;

public:
    Enseignant();
    Enseignant(int id, string nom, string prenom, string etablissement, string specialite);

    void afficher() const override;

    string getSpecialite() const;

    void setSpecialite(string nouvelleSpecialite);
};

#endif