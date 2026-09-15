#include "Etudiant.h"

Etudiant::Etudiant()
{
    filiere = "";
    annee = 0;
}

Etudiant::Etudiant(int id, string nom, string prenom,string etablissement,
                   string filiere, int annee)
    : Utilisateur(id, nom, prenom, etablissement)
{
    this->filiere = filiere;
    this->annee = annee;
}

void Etudiant::afficher() const
{
    cout << "\n----- ETUDIANT -----" << endl;
    cout << "ID : " << id << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prenom : " << prenom << endl;
    cout << "Etablissement : " << etablissement << endl;
    cout << "Filiere : " << filiere << endl;
    cout << "Annee : " << annee << endl;
}

string Etudiant::getFiliere() const
{
    return filiere;
}

int Etudiant::getAnnee() const
{
    return annee;
}

void Etudiant::setFiliere(string nouvelleFiliere)
{
    filiere = nouvelleFiliere;
}

void Etudiant::setAnnee(int nouvelleAnnee)
{
    annee = nouvelleAnnee;
}