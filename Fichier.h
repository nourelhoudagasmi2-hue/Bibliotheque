#ifndef FICHIER_H
#define FICHIER_H

#include "Livre.h"
#include "Utilisateur.h"
#include "Emprunt.h"
#include <vector>

using namespace std;


void sauvegarderLivres(const vector<Livre>& livres);
void chargerLivres(vector<Livre>& livres);


void sauvegarderUtilisateurs(const vector<Utilisateur*>& utilisateurs);
void chargerUtilisateurs(vector<Utilisateur*>& utilisateurs);

void sauvegarderEmprunts(const vector<Emprunt>& emprunts);
void chargerEmprunts(vector<Emprunt>& emprunts);

#endif
