#include "Livre.h"

Livre::Livre()
{
    id = 0;
    titre = "";
    auteur = "";
    categorie = "";
    disponible = true;
}

Livre::Livre(int id, string titre, string auteur, string categorie)
{
    this->id = id;
    this->titre = titre;
    this->auteur = auteur;
    this->categorie = categorie;
    disponible = true;
}

void Livre::afficher() const
{
    cout << "\n----- LIVRE -----" << endl;
    cout << "ID : " << id << endl;
    cout << "Titre : " << titre << endl;
    cout << "Auteur : " << auteur << endl;
    cout << "Categorie : " << categorie << endl;

    if (disponible)
        cout << "Statut : Disponible" << endl;
    else
        cout << "Statut : Emprunte" << endl;
}

int Livre::getId() const
{
    return id;
}

string Livre::getTitre() const
{
    return titre;
}

string Livre::getAuteur() const
{
    return auteur;
}

string Livre::getCategorie() const
{
    return categorie;
}

bool Livre::estDisponible() const
{
    return disponible;
}

void Livre::setTitre(string nouveauTitre)
{
    titre = nouveauTitre;
}

void Livre::setAuteur(string nouvelAuteur)
{
    auteur = nouvelAuteur;
}

void Livre::setCategorie(string nouvelleCategorie)
{
    categorie = nouvelleCategorie;
}

void Livre::emprunter()
{
    if (disponible)
    {
        disponible = false;
        cout << "Le livre a ete emprunte." << endl;
    }
    else
    {
        cout << "Le livre est deja emprunte." << endl;
    }
}

void Livre::retourner()
{
    if (!disponible)
    {
        disponible = true;
        cout << "Le livre a ete retourne." << endl;
    }
    else
    {
        cout << "Le livre est deja disponible." << endl;
    }
}
