#ifndef PRESCRIPTIONS_H
#define PRESCRIPTIONS_H
#include <string>
#include "sqlite3.h"


class Prescriptions
{
    public:
        Prescriptions(int idConsultation ,std::string medicament , std::string dosage , std::string frequence , std::string duree);
        Prescriptions(const Prescriptions &original);
        ~Prescriptions();

        int getidPrescription();
        void setidPrescription(int val);
        int getidConsultation();
        void setidConsultation(int val);
        std::string Getmedicament() ;
        void Setmedicament(std::string val);
        std::string Getdosage() ;
        void Setdosage(std::string val);
        std::string Getfrequence() ;
        void Setfrequence(std::string val);
        std::string Getduree() ;
        void Setduree(std::string val);
        bool sauvegarder(sqlite3* bd);
        static Prescriptions read(sqlite3* bd , int id);
        bool update(sqlite3* bd);
        bool removee(sqlite3* bd);

    protected:

    private:
        int idPrescription;
        int idConsultation;
        std::string medicament;
        std::string dosage;
        std::string frequence;
        std::string duree;
};

#endif // PRESCRIPTIONS_H
