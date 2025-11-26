#ifndef ANTECEDENTS_H
#define ANTECEDENTS_H
#include "sqlite3.h"
#include <string>


class Antecedents
{
    public:
        Antecedents(int idDossier ,std::string type , std::string description = "" , std::string datedebut = "" ,std::string datefin = "" );
        Antecedents(const Antecedents& original);
        ~Antecedents();


        int getidAntecedent();
        void setidAntecedent(int val);
        int getidDossier();
        void setidDossier(int val);
        std::string Gettype();
        void Settype(std::string val);
        std::string Getdescription() ;
        void Setdescription(std::string val) ;
        std::string Getdatedebut() ;
        void Setdatedebut(std::string val) ;
        std::string Getdatefin() ;
        void Setdatefin(std::string val) ;
        bool sauvegarder(sqlite3* bd);
        static Antecedents read(sqlite3* bd , int id);
        bool update(sqlite3* bd);
        bool removee(sqlite3* bd);


    protected:

    private:
        int idAntecedent;
        int idDossier;
        std::string type;
        std::string description;
        std::string datedebut;
        std::string datefin;

};

#endif // ANTECEDENTS_H
