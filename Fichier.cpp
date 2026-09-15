#include "Fichier.h"
#include "Etudiant.h"
#include "Enseignant.h"

#include <fstream>
#include <sstream>

using namespace std;



void sauvegarderLivres(const vector<Livre>& livres)
{
    ofstream fichier("livres.txt");

    if (!fichier)
    {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return;
    }

    for (const Livre& livre : livres)
    {
        fichier << livre.getId() << ";"
                << livre.getTitre() << ";"
                << livre.getAuteur() << ";"
                << livre.getCategorie() << ";"
                << livre.estDisponible()
                << endl;
    }

    fichier.close();

    cout << "Livres sauvegardes avec succes !" << endl;
}



void chargerLivres(vector<Livre>& livres)
{
    ifstream fichier("livres.txt");

    if (!fichier)
    {
        cout << "Aucun fichier de livres trouve." << endl;
        return;
    }

    livres.clear();

    string ligne;

    while (getline(fichier, ligne))
    {
        stringstream ss(ligne);

        string idStr;
        string titre;
        string auteur;
        string categorie;
        string disponibleStr;

        getline(ss, idStr, ';');
        getline(ss, titre, ';');
        getline(ss, auteur, ';');
        getline(ss, categorie, ';');
        getline(ss, disponibleStr, ';');

        int id = stoi(idStr);
        bool disponible = stoi(disponibleStr);

        Livre livre(id, titre, auteur, categorie);

        if (!disponible)
        {
            livre.emprunter();
        }

        livres.push_back(livre);
    }

    fichier.close();

    cout << "Livres charges avec succes !" << endl;
}



void sauvegarderUtilisateurs(
    const vector<Utilisateur*>& utilisateurs)
{
    ofstream fichier("utilisateurs.txt");

    if (!fichier)
    {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return;
    }

    for (Utilisateur* utilisateur : utilisateurs)
    {
        Etudiant* etudiant =
            dynamic_cast<Etudiant*>(utilisateur);

        Enseignant* enseignant =
            dynamic_cast<Enseignant*>(utilisateur);


        
        if (etudiant != nullptr)
        {
            fichier << "ETUDIANT" << ";"
                    << etudiant->getId() << ";"
                    << etudiant->getNom() << ";"
                    << etudiant->getPrenom() << ";"
                    << etudiant->getEtablissement() << ";"
                    << etudiant->getFiliere() << ";"
                    << etudiant->getAnnee()
                    << endl;
        }


        
        else if (enseignant != nullptr)
        {
            fichier << "ENSEIGNANT" << ";"
                    << enseignant->getId() << ";"
                    << enseignant->getNom() << ";"
                    << enseignant->getPrenom() << ";"
                    << enseignant->getEtablissement() << ";"
                    << enseignant->getSpecialite()
                    << endl;
        }
    }

    fichier.close();

    cout << "Utilisateurs sauvegardes avec succes !" << endl;
}




void chargerUtilisateurs(
    vector<Utilisateur*>& utilisateurs)
{
    ifstream fichier("utilisateurs.txt");

    if (!fichier)
    {
        cout << "Aucun fichier d'utilisateurs trouve." << endl;
        return;
    }

   
    for (Utilisateur* utilisateur : utilisateurs)
    {
        delete utilisateur;
    }

    utilisateurs.clear();

    string ligne;

    while (getline(fichier, ligne))
    {
        stringstream ss(ligne);

        string type;
        string idStr;
        string nom;
        string prenom;
        string etablissement;

        getline(ss, type, ';');
        getline(ss, idStr, ';');
        getline(ss, nom, ';');
        getline(ss, prenom, ';');
        getline(ss, etablissement, ';');

        int id = stoi(idStr);


        // ---------- ETUDIANT ----------
        if (type == "ETUDIANT")
        {
            string filiere;
            string anneeStr;

            getline(ss, filiere, ';');
            getline(ss, anneeStr, ';');

            int annee = stoi(anneeStr);

            Etudiant* etudiant =
                new Etudiant(
                    id,
                    nom,
                    prenom,
                    etablissement,
                    filiere,
                    annee
                );

            utilisateurs.push_back(etudiant);
        }


      
        else if (type == "ENSEIGNANT")
        {
            string specialite;

            getline(ss, specialite, ';');

            Enseignant* enseignant =
                new Enseignant(
                    id,
                    nom,
                    prenom,
                    etablissement,
                    specialite
                );

            utilisateurs.push_back(enseignant);
        }
    }

    fichier.close();

    cout << "Utilisateurs charges avec succes !" << endl;
}
void sauvegarderEmprunts(const vector<Emprunt>& emprunts)
{
    ofstream fichier("emprunts.txt");

    if (!fichier)
    {
        cout << "Erreur lors de l'ouverture du fichier." << endl;
        return;
    }

    for (const Emprunt& emprunt : emprunts)
    {
        fichier << emprunt.getIdLivre() << ";"
                << emprunt.getIdUtilisateur() << ";"
                << emprunt.estEnCours()
                << endl;
    }

    fichier.close();

    cout << "Emprunts sauvegardes avec succes !" << endl;
}


void chargerEmprunts(vector<Emprunt>& emprunts)
{
    ifstream fichier("emprunts.txt");

    if (!fichier)
    {
        cout << "Aucun fichier d'emprunts trouve." << endl;
        return;
    }

    emprunts.clear();

    string ligne;

    while (getline(fichier, ligne))
    {
        stringstream ss(ligne);

        string idLivreStr;
        string idUtilisateurStr;
        string enCoursStr;

        getline(ss, idLivreStr, ';');
        getline(ss, idUtilisateurStr, ';');
        getline(ss, enCoursStr, ';');

        int idLivre = stoi(idLivreStr);
        int idUtilisateur = stoi(idUtilisateurStr);
        bool enCours = stoi(enCoursStr);

        Emprunt emprunt(idLivre, idUtilisateur);

        if (!enCours)
        {
            emprunt.terminer();
        }

        emprunts.push_back(emprunt);
    }

    fichier.close();

    cout << "Emprunts charges avec succes !" << endl;
}
