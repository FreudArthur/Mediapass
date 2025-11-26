#ifndef EXAMENS_H
#define EXAMENS_H
#include <string>
#include "sqlite3.h"


class Examens
{
    public:
        Examens(int idConsultation ,std::string type , std::string dateExamen , std::string resultat = "RAS");
        Examens(const  Examens& original);
        ~Examens();


        int getidExamen();
        void setidExamen(int val);
        int getidConsultation();
        void setidConsultation(int val);
        std::string Gettypeexamen();
        void Settypeexamen(std::string val);
        std::string GetdateExamen() ;
        void SetdateExamen(std::string val);
        std::string Getresultat() ;
        void Setresultat(std::string val) ;
        bool sauvegarder(sqlite3* bd);
        static Examens read(sqlite3* bd , int id);
        bool update(sqlite3* bd);
        bool removee(sqlite3* bd);


    protected:

    private:
        int idExamen;
        int idConsultation;
        std::string typeexamen;
        std::string dateExamen;
        std::string resultat;

};

#endif // EXAMENS_H
