#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H


class Administrateur {
    private:
        Statistiques stats; // données de statistiques détenues par l'administrateur

public:
    // Constructeurs
    Administrateur();
    Administrateur(const Administrateur& copie);

    // Méthodes
    void gererCompte(Utilisateur& user);                     // gérer un compte utilisateur
    void gestionDroitsAcces(Utilisateur& user, bool acces);              // modifier les droits d'accès aux dossiers

    //Accesseur
    Statistiques getStats() const;          // récupérer les statistiques

    //Mutateur
    void setStats(const Statistiques& newstats); // mettre à jour les statistiques

};


#endif // ADMINISTRATEUR_H