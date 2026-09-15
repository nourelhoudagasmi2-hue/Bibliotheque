#include "Bibliotheque.h"
#include <algorithm>

void Bibliotheque::ajouterLivre(const Livre& livre)
{
    livres.push_back(livre);
}

void Bibliotheque::afficherLivres() const
{
    if (livres.empty())
    {
        cout << "La bibliotheque est vide." << endl;
        return;
    }

    for (const Livre& livre : livres)
    {
        livre.afficher();
    }
}

void Bibliotheque::ajouterLivre()
{
    int id;
    string titre;
    string auteur;
    string categorie;

    cout << "\n===== AJOUTER UN LIVRE =====" << endl;

    cout << "ID : ";
    cin >> id;
     if (rechercherLivre(id) != nullptr)
    {
        cout << "Erreur : cet ID existe deja." << endl;
        return;
    }

    cin.ignore();

    cout << "Titre : ";
    getline(cin, titre);

    cout << "Auteur : ";
    getline(cin, auteur);

    cout << "Categorie : ";
    getline(cin, categorie);

    Livre livre(id, titre, auteur, categorie);

    livres.push_back(livre);

    cout << "\nLivre ajoute avec succes !" << endl;
}

Livre* Bibliotheque::rechercherLivre(int id)
{
    for (Livre& livre : livres)
    {
        if (livre.getId() == id)
        {
            return &livre;
        }
    }

    return nullptr;
}
void Bibliotheque::modifierLivre(int id)
{
    Livre* livre = rechercherLivre(id);

    if (livre == nullptr)
    {
        cout << "Livre introuvable." << endl;
        return;
    }

    string nouveauTitre;
    string nouvelAuteur;
    string nouvelleCategorie;

    cin.ignore();

    cout << "Nouveau titre : ";
    getline(cin, nouveauTitre);

    cout << "Nouvel auteur : ";
    getline(cin, nouvelAuteur);

    cout << "Nouvelle categorie : ";
    getline(cin, nouvelleCategorie);

    livre->setTitre(nouveauTitre);
    livre->setAuteur(nouvelAuteur);
    livre->setCategorie(nouvelleCategorie);

    cout << "Livre modifie avec succes !" << endl;
}

void Bibliotheque::supprimerLivre(int id)
{
    for (auto it = livres.begin(); it != livres.end(); ++it)
    {
        if (it->getId() == id)
        {
            livres.erase(it);

            cout << "Livre supprime avec succes !" << endl;
            return;
        }
    }

    cout << "Livre introuvable." << endl;
}

void Bibliotheque::trierParTitre()
{
    sort(livres.begin(), livres.end(),
        [](const Livre& a, const Livre& b)
        {
            return a.getTitre() < b.getTitre();
        });

    cout << "Livres tries par titre !" << endl;
}

void Bibliotheque::ajouterUtilisateur(Utilisateur* utilisateur)
{
    if (rechercherUtilisateur(utilisateur->getId()) != nullptr)
    {
        cout << "Erreur : cet ID utilisateur existe deja." << endl;

        delete utilisateur;
        return;
    }

    utilisateurs.push_back(utilisateur);

    cout << "Utilisateur ajoute avec succes !" << endl;
}

void Bibliotheque::afficherUtilisateurs() const
{
    if (utilisateurs.empty())
    {
        cout << "Aucun utilisateur." << endl;
        return;
    }

    for (Utilisateur* utilisateur : utilisateurs)
    {
        utilisateur->afficher();
    }
}

Utilisateur* Bibliotheque::rechercherUtilisateur(int id)
{
    for (Utilisateur* utilisateur : utilisateurs)
    {
        if (utilisateur->getId() == id)
        {
            return utilisateur;
        }
    }

    return nullptr;
}

void Bibliotheque::emprunterLivre(int idLivre, int idUtilisateur)
{
    Livre* livre = rechercherLivre(idLivre);
    Utilisateur* utilisateur = rechercherUtilisateur(idUtilisateur);

    if (livre == nullptr)
    {
        cout << "Livre introuvable." << endl;
        return;
    }

    if (utilisateur == nullptr)
    {
        cout << "Utilisateur introuvable." << endl;
        return;
    }

    if (!livre->estDisponible())
    {
        cout << "Le livre est deja emprunte." << endl;
        return;
    }

    Emprunt nouvelEmprunt(idLivre, idUtilisateur);

    emprunts.push_back(nouvelEmprunt);

    livre->emprunter();

    cout << "Emprunt effectue avec succes !" << endl;
}

void Bibliotheque::retournerLivre(int idLivre)
{
    Livre* livre = rechercherLivre(idLivre);

    if (livre == nullptr)
    {
        cout << "Livre introuvable." << endl;
        return;
    }

    if (livre->estDisponible())
    {
        cout << "Le livre est deja disponible." << endl;
        return;
    }

    for (Emprunt& emprunt : emprunts)
    {
        if (emprunt.getIdLivre() == idLivre &&
            emprunt.estEnCours())
        {
            emprunt.terminer();
            livre->retourner();

            cout << "Livre retourne avec succes !" << endl;
            return;
        }
    }

    cout << "Aucun emprunt en cours pour ce livre." << endl;
}

void Bibliotheque::afficherEmprunts() const
{
    if (emprunts.empty())
    {
        cout << "Aucun emprunt." << endl;
        return;
    }

    for (const Emprunt& emprunt : emprunts)
    {
        emprunt.afficher();
    }
}
const vector<Livre>& Bibliotheque::getLivres() const
{
    return livres;
}

vector<Livre>& Bibliotheque::getLivres()
{
    return livres;
}
const vector<Utilisateur*>& Bibliotheque::getUtilisateurs() const
{
    return utilisateurs;
}

vector<Utilisateur*>& Bibliotheque::getUtilisateurs()
{
    return utilisateurs;
}

const vector<Emprunt>& Bibliotheque::getEmprunts() const
{
    return emprunts;
}

vector<Emprunt>& Bibliotheque::getEmprunts()
{
    return emprunts;
}

Bibliotheque::~Bibliotheque()
{
    for (Utilisateur* utilisateur : utilisateurs)
    {
        delete utilisateur;
    }
}