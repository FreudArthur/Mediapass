#include "Administrateur.h"
#include"Utilisateur.h"
#include "Statistiques.h"
#include <iostream>

// Constructeurs
Administrateur::Administrateur() {
    std::cout << "Administrateur créé (par défaut)." << std::endl;
}

Administrateur::Administrateur(const Administrateur& copie) {
    std::cout << "Administrateur copié." << std::endl;
}

// Méthodes
void Administrateur::gererCompte(Utilisateur& user) {
    std::cout << "Gestion du compte de " << user.getNomUtilisateur() << std::endl;
    user.seConnecter(); // exemple d'action
}

void Administrateur::gestionDroitsAcces(Utilisateur& user, bool acces) {
    user.setAccesDossier(acces);
    std::cout << "Droits d'accès mis à jour pour " << user.getNomUtilisateur()
              << " : " << (acces ? "Autorisé" : "Refusé") << std::endl;
}


//Accessseur
Statistiques Administrateur::getStats() const {
    // Ici on retourne un objet Statistiques (vide pour l'instant)
    Statistiques stats;
    std::cout << "Récupération des statistiques..." << std::endl;
    return stats;
}

//Mutateur
void Administrateur::setStats(const Statistiques& newstats) {
    stats = newstats;
    std::cout << "Statistiques mises à jour par l'administrateur." << std::endl;
}