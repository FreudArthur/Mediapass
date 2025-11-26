#ifndef CONSULTATION_H
#define CONSULTATION_H
#include <vector>
#include <string>
#include "Examens.h"
#include "Prescriptions.h"
#include "sqlite3.h"


class Consultation
{
    public:
        Consultation(int idDossier , std::string dateConsultation ,std::string motif, std::string medecin ="", std::string diagnostic="" );
        Consultation(const Consultation& original);
        ~Consultation();

        int getidConsultation();
        void setidConsultation(int val);
        int getidDossier();
        void setidDossier(int val);
        std::string GetdateConsultation();
        void SetdateConsultation(std::string val) ;
        std::string Getmotif() ;
        void Setmotif(std::string val) ;
        std::string Getmedecin() ;
        void Setmedecin(std::string val) ;
        std::string Getdiagnostic() ;
        void Setdiagnostic(std::string val);
        std::vector <Examens> Getexamen() ;
        void Setexamen(std::vector<Examens> val) ;
        std::vector<Prescriptions> Getprescripitons();
        void Setprescripitons(std::vector<Prescriptions> val) ;
        bool sauvegarder(sqlite3* bd);
        static Consultation read(sqlite3* bd , int id);
        bool update(sqlite3* bd);
        bool removee(sqlite3* bd);


    protected:

    private:
        int idConsultation ;
        int idDossier;
        std::string dateConsultation;
        std::string motif;
        std::string medecin;
        std::string diagnostic;
        std::vector<Examens> examen;
        std::vector<Prescriptions> prescripitons;
};

#endif // CONSULTATION_H
