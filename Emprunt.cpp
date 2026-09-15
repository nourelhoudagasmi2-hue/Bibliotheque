#include "Emprunt.h"
#include <iostream>

using namespace std;

Emprunt::Emprunt()
{
    idLivre = -1;
    idUtilisateur = -1;
    enCours = false;
}

Emprunt::Emprunt(int idLivre, int idUtilisateur)
{
    this->idLivre = idLivre;
    this->idUtilisateur = idUtilisateur;
    enCours = true;
}

int Emprunt::getIdLivre() const
{
    return idLivre;
}

int Emprunt::getIdUtilisateur() const
{
    return idUtilisateur;
}

bool Emprunt::estEnCours() const
{
    return enCours;
}

void Emprunt::terminer()
{
    enCours = false;
}

void Emprunt::afficher() const
{
    cout << "\n----- EMPRUNT -----" << endl;
    cout << "ID Livre : " << idLivre << endl;
    cout << "ID Utilisateur : " << idUtilisateur << endl;

    if (enCours)
        cout << "Statut : En cours" << endl;
    else
        cout << "Statut : Termine" << endl;
}
