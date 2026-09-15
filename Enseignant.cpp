#include "Enseignant.h"

Enseignant::Enseignant()
{
    specialite = "";
}

Enseignant::Enseignant(int id, string nom, string prenom, string etablissement,
                       string specialite)
    : Utilisateur(id, nom, prenom, etablissement)
{
    this->specialite = specialite;
}

void Enseignant::afficher() const
{
    cout << "\n----- ENSEIGNANT -----" << endl;
    cout << "ID : " << id << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prenom : " << prenom << endl;
    cout << "Etablissement : " << etablissement << endl;
    cout << "Specialite : " << specialite << endl;
}

string Enseignant::getSpecialite() const
{
    return specialite;
}

void Enseignant::setSpecialite(string nouvelleSpecialite)
{
    specialite = nouvelleSpecialite;
}