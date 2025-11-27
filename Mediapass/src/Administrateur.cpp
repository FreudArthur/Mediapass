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
    std::cout << "=== Gestion du compte utilisateur ===" << std::endl;
    std::cout << "ID : " << user.getId() << std::endl;
    std::cout << "Nom d'utilisateur : " << user.getNomUtilisateur() << std::endl;
    std::cout << "Email : " << user.getEmail() << std::endl;
    std::cout << "Rôle : " << user.getRole() << std::endl;
    std::cout << "Accès au dossier : " << (user.getAccesDossier() ? "Autorisé" : "Refusé") << std::endl;

    // Exemple d’action possible : désactiver le compte
    std::string reponse;
    std::cout << "Souhaitez-vous désactiver ce compte ? (oui/non) : ";
    std::cin >> reponse;
    if (reponse == "oui") {
        user.setAccesDossier(false);
        std::cout << "Le compte de " << user.getNomUtilisateur() << " a été désactivé." << std::endl;
    }

    std::cout << "=== Fin de la gestion du compte ===" << std::endl;

}

void Administrateur::gestionDroitsAcces(Utilisateur& user, bool acces) {
    std::cout << "=== Gestion des droits d'accès ===" << std::endl;
    std::cout << "Utilisateur : " << user.getNomUtilisateur() << std::endl;
    std::cout << "Rôle actuel : " << user.getRole() << std::endl;
    std::cout << "Accès actuel : " << (user.getAccesDossier() ? "Autorisé" : "Refusé") << std::endl;

    // Vérification du rôle
    if (user.getRole() == "Médecin" || user.getRole() == "Infirmier") {
        user.setAccesDossier(acces);
        std::cout << "Accès aux dossiers médicaux "
                  << (acces ? "autorisé" : "refusé")
                  << " pour " << user.getNomUtilisateur() << "." << std::endl;
    } else {
        std::cout << "Action refusée : le rôle '" << user.getRole()
                  << "' ne peut pas avoir accès aux dossiers médicaux." << std::endl;
    }

    std::cout << "=== Fin de la gestion des droits ===" << std::endl;
}


//Accessseur
Statistiques Administrateur::getStats() const {
    std::cout << "=== Consultation des statistiques ===" << std::endl;
    std::cout << "Nombre de patients par semaine : " << stats.getNbrePatientParSemaine() << std::endl;
    std::cout << "Nombre de plaintes : " << stats.getNbreDePlaintes() << std::endl;

    // Affichage des patients par spécialité
    std::cout << "Nombre par spécialité :" << std::endl;
    for (const auto& pair : stats.getNbreParSpecialite()) {
        std::cout << "  - " << pair.first << " : " << pair.second << std::endl;
    }

    // Affichage des chefs par spécialité
    std::cout << "Chef par spécialité :" << std::endl;
    for (const auto& pair : stats.getChefParSpecialite()) {
        std::cout << "  - " << pair.first << " : " << pair.second << std::endl;
    }

    // Affichage des consultations par période
    std::cout << "Consultations par période :" << std::endl;
    for (const auto& pair : stats.getConsultationParPeriode()) {
        std::cout << "  - " << pair.first << " : " << pair.second << std::endl;
    }

    std::cout << "=== Fin des statistiques ===" << std::endl;
    return stats;
}


//Mutateur
void Administrateur::setStats(const Statistiques& newstats) {
    std::cout << "=== Mise à jour des statistiques ===" << std::endl;

    // Comparaison simple des valeurs numériques
    if (newstats.getNbrePatientParSemaine() != stats.getNbrePatientParSemaine()) {
        std::cout << "Patients par semaine : "
                  << stats.getNbrePatientParSemaine() << " -> "
                  << newstats.getNbrePatientParSemaine() << std::endl;
    }

    if (newstats.getNbreDePlaintes() != stats.getNbreDePlaintes()) {
        std::cout << "Plaintes : "
                  << stats.getNbreDePlaintes() << " -> "
                  << newstats.getNbreDePlaintes() << std::endl;
    }

    // Comparaison des maps
    std::cout << "Mise à jour des spécialités :" << std::endl;
    for (const auto& pair : newstats.getNbreParSpecialite()) {
        int ancien = stats.getNbreParSpecialite().count(pair.first) ? stats.getNbreParSpecialite().at(pair.first) : -1;
        if (ancien != pair.second) {
            std::cout << "  - " << pair.first << " : " << ancien << " -> " << pair.second << std::endl;
        }
    }

    std::cout << "Mise à jour des chefs par spécialité :" << std::endl;
    for (const auto& pair : newstats.getChefParSpecialite()) {
        std::string ancien = stats.getChefParSpecialite().count(pair.first) ? stats.getChefParSpecialite().at(pair.first) : "Aucun";
        if (ancien != pair.second) {
            std::cout << "  - " << pair.first << " : " << ancien << " -> " << pair.second << std::endl;
        }
    }

    std::cout << "Mise à jour des consultations par période :" << std::endl;
    for (const auto& pair : newstats.getConsultationParPeriode()) {
        int ancien = stats.getConsultationParPeriode().count(pair.first) ? stats.getConsultationParPeriode().at(pair.first) : -1;
        if (ancien != pair.second) {
            std::cout << "  - " << pair.first << " : " << ancien << " -> " << pair.second << std::endl;
        }
    }

    // Mise à jour effective
    stats = newstats;
    std::cout << "Statistiques mises à jour par l'administrateur." << std::endl;
}