#include "Bibliotheque.h"
#include "Etudiant.h"
#include "Enseignant.h"
#include "Fichier.h"

int main()
{
    Bibliotheque biblio;

    int choix;

    do
    {
        cout << "\n=================================" << endl;
        cout << "          BIBLIOTHEQUE" << endl;
        cout << "=================================" << endl;

        cout << "1. Ajouter un livre" << endl;
        cout << "2. Afficher les livres" << endl;
        cout << "3. Rechercher un livre" << endl;
        cout << "4. Modifier un livre" << endl;
        cout << "5. Supprimer un livre" << endl;
        cout << "6. Trier les livres par titre" << endl;

        cout << "7. Ajouter un utilisateur" << endl;
        cout << "8. Afficher les utilisateurs" << endl;
        cout << "9. Rechercher un utilisateur" << endl;

        cout << "10. Emprunter un livre" << endl;
        cout << "11. Retourner un livre" << endl;
        cout << "12. Afficher les emprunts" << endl;
        cout << "13. Sauvegarder les livres" << endl;
        cout << "14. Charger les livres" << endl;
        cout << "15. Sauvegarder les utilisateurs" << endl;
        cout << "16. Charger les utilisateurs" << endl;
        cout << "17. Sauvegarder les emprunts" << endl;
        cout << "18. Charger les emprunts" << endl;

        cout << "0. Quitter" << endl;
        cout << "=================================" << endl;

        cout << "Votre choix : ";
        cin >> choix;

        switch (choix)
        {
            // =====================================
            // 1. AJOUTER UN LIVRE
            // =====================================
            case 1:
                biblio.ajouterLivre();
                break;


            // =====================================
            // 2. AFFICHER LES LIVRES
            // =====================================
            case 2:
                biblio.afficherLivres();
                break;


            // =====================================
            // 3. RECHERCHER UN LIVRE
            // =====================================
            case 3:
            {
                int id;

                cout << "ID du livre : ";
                cin >> id;

                Livre* livre = biblio.rechercherLivre(id);

                if (livre != nullptr)
                {
                    livre->afficher();
                }
                else
                {
                    cout << "Livre introuvable." << endl;
                }

                break;
            }


            // =====================================
            // 4. MODIFIER UN LIVRE
            // =====================================
            case 4:
            {
                int id;

                cout << "ID du livre : ";
                cin >> id;

                biblio.modifierLivre(id);

                break;
            }


            // =====================================
            // 5. SUPPRIMER UN LIVRE
            // =====================================
            case 5:
            {
                int id;

                cout << "ID du livre : ";
                cin >> id;

                biblio.supprimerLivre(id);

                break;
            }


            // =====================================
            // 6. TRIER LES LIVRES
            // =====================================
            case 6:
                biblio.trierParTitre();
                break;


            // =====================================
            // 7. AJOUTER UN UTILISATEUR
            // =====================================
            case 7:
            {
                int type;
                int id;

                string nom;
                string prenom;
                string etablissement;

                cout << "\n===== AJOUTER UTILISATEUR =====" << endl;

                cout << "1. Etudiant" << endl;
                cout << "2. Enseignant" << endl;

                cout << "Type : ";
                cin >> type;

                cout << "ID : ";
                cin >> id;

                cin.ignore();

                cout << "Nom : ";
                getline(cin, nom);

                cout << "Prenom : ";
                getline(cin, prenom);

                cout << "Etablissement : ";
                getline(cin, etablissement);


                // ---------- ETUDIANT ----------
                if (type == 1)
                {
                    string filiere;
                    int annee;

                    cout << "Filiere : ";
                    getline(cin, filiere);

                    cout << "Annee : ";
                    cin >> annee;

                    Etudiant* e = new Etudiant(
                        id,
                        nom,
                        prenom,
                        etablissement,
                        filiere,
                        annee
                    );

                    biblio.ajouterUtilisateur(e);
                }


                // ---------- ENSEIGNANT ----------
                else if (type == 2)
                {
                    string specialite;

                    cout << "Specialite : ";
                    getline(cin, specialite);

                    Enseignant* p = new Enseignant(
                        id,
                        nom,
                        prenom,
                        etablissement,
                        specialite
                    );

                    biblio.ajouterUtilisateur(p);
                }


                else
                {
                    cout << "Type invalide !" << endl;
                }

                break;
            }


            // =====================================
            // 8. AFFICHER LES UTILISATEURS
            // =====================================
            case 8:
                biblio.afficherUtilisateurs();
                break;


            // =====================================
            // 9. RECHERCHER UN UTILISATEUR
            // =====================================
            case 9:
            {
                int id;

                cout << "ID de l'utilisateur : ";
                cin >> id;

                Utilisateur* utilisateur =
                    biblio.rechercherUtilisateur(id);

                if (utilisateur != nullptr)
                {
                    utilisateur->afficher();
                }
                else
                {
                    cout << "Utilisateur introuvable." << endl;
                }

                break;
            }


            // =====================================
            // 10. EMPRUNTER UN LIVRE
            // =====================================
            case 10:
            {
                int idLivre;
                int idUtilisateur;

                cout << "ID du livre : ";
                cin >> idLivre;

                cout << "ID de l'utilisateur : ";
                cin >> idUtilisateur;

                biblio.emprunterLivre(
                    idLivre,
                    idUtilisateur
                );

                break;
            }


            // =====================================
            // 11. RETOURNER UN LIVRE
            // =====================================
            case 11:
            {
                int idLivre;

                cout << "ID du livre : ";
                cin >> idLivre;

                biblio.retournerLivre(idLivre);

                break;
            }


            // =====================================
            // 12. AFFICHER LES EMPRUNTS
            // =====================================
            case 12:
                biblio.afficherEmprunts();
                break;

            // =====================================
            // 13. SAUVEGARDER LES LIVRES
            // =====================================
            case 13:
                sauvegarderLivres(biblio.getLivres());
                break;

            // =====================================
            // 14. CHARGER LES LIVRES
            // =====================================
            case 14:
                chargerLivres(biblio.getLivres());
                break;
            // =====================================
            // 15. SAUVEGARDER LES UTILISATEURS
            // =====================================
            case 15:
                sauvegarderUtilisateurs(biblio.getUtilisateurs());
                break;

            // =====================================
            // 16. CHARGER LES UTILISATEURS
            // =====================================
            case 16:
                chargerUtilisateurs(biblio.getUtilisateurs());
                break;
            
            // =====================================
            // 17. SAUVEGARDER LES EMPRUNTS
            // =====================================
            case 17:
                sauvegarderEmprunts(biblio.getEmprunts());
                break;

            // =====================================
            // 18. CHARGER LES EMPRUNTS
            // =====================================
            case 18:
                chargerEmprunts(biblio.getEmprunts());
                break;


            // 0. QUITTER
            // =====================================
            case 0:
                cout << "\nAu revoir !" << endl;
                break;


            // =====================================
            // CHOIX INVALIDE
            // =====================================
            default:
                cout << "\nChoix invalide !" << endl;
        }

    } while (choix != 0);


    return 0;
}