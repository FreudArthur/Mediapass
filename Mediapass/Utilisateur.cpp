//
// Created by LOAN on 19/11/2025.
//

#include "Utilisateur.h"
#include <iostream>

//Constructeurs
Utilisateur::Utilisateur()
    : id(0), nomUtilisateur(""), password(""), email(""), role(""), accesDossier(false) {}

Utilisateur::Utilisateur(int id, const std::string& nom, const std::string& pass,
                         const std::string& mail, const std::string& role, bool acces)
    : id(id), nomUtilisateur(nom), password(pass), email(mail), role(role), accesDossier(acces) {}

Utilisateur::Utilisateur(const Utilisateur& copie)
    : id(copie.id),
      nomUtilisateur(copie.nomUtilisateur),
      password(copie.password),
      email(copie.email),
      role(copie.role),
      accesDossier(copie.accesDossier)
    {}

//Méthodes
void Utilisateur::seConnecter() {
    std::cout << nomUtilisateur << " est connecté." << std::endl;
}

void Utilisateur::seDeconnecter() {
    std::cout << nomUtilisateur << " est déconnecté." << std::endl;
}

//Accesseurs
int Utilisateur::getId() const {
    return id;
}
std::string Utilisateur::getNomUtilisateur() const {
    return nomUtilisateur;
}
std::string Utilisateur::getEmail() const {
    return email;
}
std::string Utilisateur::getRole() const {
    return role;
}
bool Utilisateur::getAccesDossier() const {
    return accesDossier;
}

//Mutateurs
void Utilisateur::setPassword(const std::string& newPass) {
    password = newPass;
}
void Utilisateur::setEmail(const std::string& newEmail) {
    email = newEmail;
}
void Utilisateur::setRole(const std::string& newRole) {
    role = newRole;
}
void Utilisateur::setAccesDossier(bool acces) {
    accesDossier = acces;
}