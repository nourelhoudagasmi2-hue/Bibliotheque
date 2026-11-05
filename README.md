# Bibliotheque — Library Management System

A library management system developed in C++ using Object-Oriented Programming (OOP) principles.

## Project Overview

Bibliotheque is a console-based application designed to manage a library, its books, users, and borrowing operations.

The project applies object-oriented programming concepts to organize the application into reusable and maintainable classes.

## Features

- Add, display, search, and manage books.
- Organize books by category.
- Manage library users.
- Support different user types: students and teachers.
- Manage book borrowing operations.
- Track borrowed and returned books.
- Save and load data using text files.
- Manage library and establishment information.

## Technologies Used

| Technology | Purpose |
|---|---|
| C++ | Application development |
| Object-Oriented Programming | Code organization |
| Classes and Objects | Modeling library entities |
| Inheritance | Managing different user types |
| Composition | Organizing relationships between objects |
| File Handling | Data persistence |
| VS Code | Development environment |
| Git & GitHub | Version control |

## Project Structure

```text
Bibliotheque/
│
├── main.cpp
├── Livre.h
├── Livre.cpp
├── Bibliotheque.h
├── Bibliotheque.cpp
├── Utilisateur.h
├── Utilisateur.cpp
├── Etudiant.h
├── Etudiant.cpp
├── Enseignant.h
├── Enseignant.cpp
├── Emprunt.h
├── Emprunt.cpp
├── Fichier.h
├── Fichier.cpp
│
└── Data Files
```

## Main OOP Concepts

This project demonstrates:

- **Encapsulation:** Protecting attributes and controlling access through methods.
- **Inheritance:** Creating specialized classes such as `Etudiant` and `Enseignant` from `Utilisateur`.
- **Polymorphism:** Supporting different behaviors through shared interfaces.
- **Composition:** Building complex objects using relationships between classes.
- **Constructors and Destructors:** Managing object initialization and destruction.
- **Const Methods:** Protecting objects from unintended modifications.

## How to Run

### Requirements

- C++ compiler (GCC or MinGW)
- Visual Studio Code (optional)

### Compilation

Compile the project using:

```bash
g++ main.cpp Livre.cpp Bibliotheque.cpp Utilisateur.cpp Etudiant.cpp Enseignant.cpp Emprunt.cpp Fichier.cpp -o bibliotheque
```

### Execution

On Windows:

```bash
bibliotheque.exe
```

## Learning Objectives

Through this project, I practiced:

- C++ programming.
- Object-Oriented Programming.
- Class design and relationships.
- Inheritance and polymorphism.
- File handling.
- Managing a multi-file C++ project.
- Writing modular and reusable code.

## Author

**GASMI NOURELHOUDA**

Computer Science Student
