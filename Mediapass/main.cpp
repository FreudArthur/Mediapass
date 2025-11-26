#include <iostream>
#include "Utilisateur.h"
#include "Administrateur.h"
#include "Statistiques.h"

int main() {
    std::cout << "Programme principal lancé." << std::endl;

    // Création d'objets basiques pour montrer que les classes sont reconnues
    Utilisateur user;          // objet Utilisateur
    Administrateur admin;      // objet Administrateur
    Statistiques stats;        // objet Statistiques

    // Affichage minimal pour vérifier la compilation
    std::cout << "Classes initialisées correctement." << std::endl;

    return 0;
}