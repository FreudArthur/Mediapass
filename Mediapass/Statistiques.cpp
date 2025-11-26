#include "Statistiques.h"
#include <iostream>

// Constructeurs
Statistiques::Statistiques()
    : nbrePatientParSemaine(0),
      nbreDePlaintes(0) {
    // Les maps sont automatiquement initialisées vides
    std::cout << "Statistiques créées (par défaut)." << std::endl;
}

Statistiques::Statistiques(const Statistiques& copie)
    : nbrePatientParSemaine(copie.nbrePatientParSemaine),
      nbreParSpecialite(copie.nbreParSpecialite),
      chefParSpecialite(copie.chefParSpecialite),
      consultationParPeriode(copie.consultationParPeriode),
      nbreDePlaintes(copie.nbreDePlaintes) {
    std::cout << "Statistiques copiées." << std::endl;
}


//Mutateurs

void Statistiques::setNbrePatientParSemaine(int nbre) {
    nbrePatientParSemaine = nbre;
}

void Statistiques::setNbreDePlaintes(int nbre) {
    nbreDePlaintes = nbre;
}

void Statistiques::ajouterSpecialite(const std::string& specialite, int nbre) {
    // ajoute ou met à jour le nombre pour une spécialité
    nbreParSpecialite[specialite] = nbre;
}

void Statistiques::setChefParSpecialite(const std::string& specialite, const std::string& chef) {
    // associe un chef à une spécialité
    chefParSpecialite[specialite] = chef;
}

void Statistiques::ajouterConsultation(const std::string& periode, int nbre) {
    // ajoute ou met à jour le nombre de consultations pour une période donnée
    consultationParPeriode[periode] = nbre;
}


//Accesseurs
int Statistiques::getNbrePatientParSemaine() const {
    return nbrePatientParSemaine;
}

int Statistiques::getNbreDePlaintes() const {
    return nbreDePlaintes;
}

std::map<std::string, int> Statistiques::getNbreParSpecialite() const {
    return nbreParSpecialite;
}

std::map<std::string, std::string> Statistiques::getChefParSpecialite() const {
    return chefParSpecialite;
}

std::map<std::string, int> Statistiques::getConsultationParPeriode() const {
    return consultationParPeriode;
}


/*
void Statistiques::afficher() const {
    std::cout << "Nombre de patients par semaine : " << nbrePatientParSemaine << std::endl;
    std::cout << "Nombre de plaintes : " << nbreDePlaintes << std::endl;

    std::cout << "Nombre par spécialité :" << std::endl;
    for (const auto& pair : nbreParSpecialite) {
        std::cout << "  - " << pair.first << " : " << pair.second << std::endl;
    }

    std::cout << "Chef par spécialité :" << std::endl;
    for (const auto& pair : chefParSpecialite) {
        std::cout << "  - " << pair.first << " : " << pair.second << std::endl;
    }

    std::cout << "Consultations par période :" << std::endl;
    for (const auto& pair : consultationParPeriode) {
        std::cout << "  - " << pair.first << " : " << pair.second << std::endl;
    }
}
Cette méthode permet de visualiser toutes les statistiques d’un seul coup, ce qui est pratique

*/