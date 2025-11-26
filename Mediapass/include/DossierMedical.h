#ifndef DOSSIERMEDICAL_H
#define DOSSIERMEDICAL_H
#include <string>
#include <vector>
#include "Consultation.h"
#include "Antecedents.h"
#include "sqlite3.h"


class DossierMedical
{
    public:
        DossierMedical(int idPatient);
        ~DossierMedical();

        int GetidDossier();
        void SetidDossier(int val);
        int GetidPatient() ;
        void SetidPatient(int val) ;
        std::vector<Consultation> getConsultations();
        void setConsultation(std::vector<Consultation> val);
        std::vector<Antecedents> getAntecedents();
        void setAntecedent(std::vector<Antecedents> val);
        bool sauvegarder(sqlite3* bd);
        static DossierMedical read(sqlite3* bd , int id);
        bool update(sqlite3* bd);
        bool removee(sqlite3* bd);


    protected:

    private:
        int idDossier;
        int idPatient;
        std::vector<Consultation> consultations;
        std::vector<Antecedents> antecedents;
};

#endif // DOSSIERMEDICAL_H
