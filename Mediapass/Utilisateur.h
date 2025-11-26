//
// Created by LOAN on 19/11/2025.
//

#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <string>


class Utilisateur {
private:
    int id;                     // Identifiant unique
    std::string nomUtilisateur; // Nom d'utilisateur
    std::string password;       // Mot de passe
    std::string email;          // Adresse email
    std::string role;           // Rôle (Médecin, Infirmier, Patient, etc.)
    bool accesDossier;          // Droit d'accès au dossier médical

public:
    //Constructeur
    Utilisateur();
    Utilisateur(int id,
                const std::string& nom,
                const std::string& pass,
                const std::string& mail,
                const std::string& role,
                bool acces);
    Utilisateur(Utilisateur const& copie);

    //Méthodes
    void seConnecter();
    void seDeconnecter();

    //Accesseurs
    int getId() const;
    std::string getNomUtilisateur() const;
    std::string getEmail() const;
    std::string getRole() const;
    bool getAccesDossier() const;

    //Mutateurs
    void setPassword(const std::string& newPass);
    void setEmail(const std::string& newEmail);
    void setRole(const std::string& newRole);
    void setAccesDossier(bool acces);

};

#endif //UTILISATEUR_H
