#include "Utilisateur.h"

Utilisateur::Utilisateur()
{
    id = -1;
    nom = "";
    prenom = "";
    etablissement = "";
}

Utilisateur::Utilisateur(int id, string nom, string prenom, string etablissement)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->etablissement = etablissement;
}

void Utilisateur::afficher() const
{
    cout << "\n----- UTILISATEUR -----" << endl;
    cout << "ID : " << id << endl;
    cout << "Nom : " << nom << endl;
    cout << "Prenom : " << prenom << endl;
    cout << "Etablissement : " << etablissement << endl;
}

int Utilisateur::getId() const
{
    return id;
}

string Utilisateur::getNom() const
{
    return nom;
}

string Utilisateur::getPrenom() const
{
    return prenom;
}

string Utilisateur::getEtablissement() const
{
    return etablissement;
}

void Utilisateur::setNom(string nouveauNom)
{
    nom = nouveauNom;
}

void Utilisateur::setPrenom(string nouveauPrenom)
{
    prenom = nouveauPrenom;
}

void Utilisateur::setEtablissement(string nouvelEtablissement)
{
    etablissement = nouvelEtablissement;
}

Utilisateur::~Utilisateur()
{
}