# Bibliothèque - C++ POO

Projet de gestion d'une bibliothèque réalisé en C++.

Ce projet a été développé pour pratiquer les concepts de la programmation orientée objet (POO).

## Objectif

Le programme permet de gérer :

- Les livres
- Les utilisateurs
- Les étudiants
- Les enseignants
- Les emprunts
- Les retours
- La sauvegarde des données
- Le chargement des données

## Fonctionnalités

### Livres

- Ajouter un livre
- Afficher les livres
- Rechercher un livre
- Modifier un livre
- Supprimer un livre
- Trier les livres par titre

### Utilisateurs

- Ajouter un étudiant
- Ajouter un enseignant
- Afficher les utilisateurs
- Rechercher un utilisateur

### Emprunts

- Emprunter un livre
- Retourner un livre
- Afficher les emprunts

### Fichiers

- Sauvegarder les livres
- Charger les livres
- Sauvegarder les utilisateurs
- Charger les utilisateurs
- Sauvegarder les emprunts
- Charger les emprunts

## Concepts POO utilisés

Le projet utilise notamment :

- Classes et objets
- Encapsulation
- Constructeurs
- Destructeurs
- Héritage
- Polymorphisme
- `virtual`
- `override`
- `dynamic_cast`
- Pointeurs
- Références
- `const`
- `vector`
- STL
- Gestion dynamique de la mémoire
- Fichiers

## Structure du projet

```text
Bibliotheque/
│
├── main.cpp
│
├── Livre.h
├── Livre.cpp
│
├── Bibliotheque.h
├── Bibliotheque.cpp
│
├── Utilisateur.h
├── Utilisateur.cpp
│
├── Etudiant.h
├── Etudiant.cpp
│
├── Enseignant.h
├── Enseignant.cpp
│
├── Emprunt.h
├── Emprunt.cpp
│
├── Fichier.h
├── Fichier.cpp
│
├── livres.txt
├── utilisateurs.txt
└── emprunts.txt