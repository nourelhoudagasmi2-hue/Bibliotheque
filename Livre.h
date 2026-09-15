#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include <string>

using namespace std;

class Livre
{
private:
    int id;
    string titre;
    string auteur;
    string categorie;
    bool disponible;

public:
   
    Livre();

   
    Livre(int id, string titre, string auteur, string categorie);

   
    void afficher() const;

    
    int getId() const;
    string getTitre() const;
    string getAuteur() const;
    string getCategorie() const;
    bool estDisponible() const;

   
    void setTitre(string nouveauTitre);
    void setAuteur(string nouvelAuteur);
    void setCategorie(string nouvelleCategorie);

    void emprunter();
    void retourner();
};

#endif