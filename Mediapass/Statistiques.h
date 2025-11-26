#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <map>
#include <string>
#include <iostream>

class Statistiques {
private:
    int nbrePatientParSemaine;                       // nombre de patients par semaine
    std::map<std::string, int> nbreParSpecialite;    // nombre par spécialité
    std::map<std::string, std::string> chefParSpecialite; // chef par spécialité (clé = spécialité, valeur = nom du chef)
    std::map<std::string, int> consultationParPeriode;    // consultations par période
    int nbreDePlaintes;                              // nombre de plaintes

public:
    // Constructeurs
    Statistiques();
    Statistiques(const Statistiques& copie);

    // Méthodes
    void afficher() const;

    // Mutateurs
    void setNbrePatientParSemaine(int nbre);
    void setNbreDePlaintes(int nbre);
    void ajouterSpecialite(const std::string& specialite, int nbre);
    void setChefParSpecialite(const std::string& specialite, const std::string& chef);
    void ajouterConsultation(const std::string& periode, int nbre);

    // Accesseurs
    int getNbrePatientParSemaine() const;
    int getNbreDePlaintes() const;
    std::map<std::string, int> getNbreParSpecialite() const;
    std::map<std::string, std::string> getChefParSpecialite() const;
    std::map<std::string, int> getConsultationParPeriode() const;
};

#endif // STATISTIQUES_H