#include <iostream>
#include "Utilisateur.h"
#include "Administrateur.h"
#include "Statistiques.h"
#include <chrono>
#include <iostream>
#include <ctime>
#include "sqlite3.h"
#include "Database.h"
#include "Patient.h"
using namespace std;



int main()
{

    std::cout << "Programme principal lancé." << std::endl;
    /*
    cout << "Hello world!" << endl;
    chrono::system_clock::time_point now = chrono::system_clock::now() ;
    auto t = chrono::system_clock::to_time_t(now);
    cout << ctime(&t) <<endl;



    sqlite3* db;
    int rc = sqlite3_open("hopital.sqlite", &db);

    if (rc) {
        std::cerr << "Erreur ouverture : " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    std::cout << "DB ouverte avec succ�s !" << std::endl;

    sqlite3_close(db); */
    Database db("hopital.sqlite");
   /* Patient john("john" , 17, 90909090 , true , 160.5 , 50.2 , "A+", 0 );
    john.sauvegarder(db.getDatabase());*/

    Patient p("Freud",19 , 50505077 , 1 , 180 , 48.9 , "0+","Alice");

    p.sauvegarder(db.getDatabase());
    //std::cout << p.GetidPatient();
    p.removee(db.getDatabase());

    Patient a = Patient::read(db.getDatabase() , 10);
    std::cout << a.GetnomPatient();



    

    // Création d'objets basiques pour montrer que les classes sont reconnues
    Utilisateur user;          // objet Utilisateur
    Administrateur admin;      // objet Administrateur
    Statistiques stats;        // objet Statistiques

    // Affichage minimal pour vérifier la compilation
    std::cout << "Classes initialisées correctement." << std::endl;


    return 0;
}