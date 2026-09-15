#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include <iostream>
#include <string>

using namespace std;

class Utilisateur
{
protected:
    int id;
    string nom;
    string prenom;
    string etablissement;
    
public:
    Utilisateur();
    Utilisateur(int id, string nom, string prenom, string etablissement);

    virtual void afficher() const;

    int getId() const;
    string getNom() const;
    string getPrenom() const;
    string getEtablissement() const;

    void setNom(string nouveauNom);
    void setPrenom(string nouveauPrenom);
    void setEtablissement(string nouvelEtablissement);

    virtual ~Utilisateur();
};

#endif