#ifndef EMPRUNT_H
#define EMPRUNT_H

class Emprunt
{
private:
    int idLivre;
    int idUtilisateur;
    bool enCours;

public:
    Emprunt();
    Emprunt(int idLivre, int idUtilisateur);

    int getIdLivre() const;
    int getIdUtilisateur() const;
    bool estEnCours() const;

    void terminer();
    void afficher() const;
};

#endif