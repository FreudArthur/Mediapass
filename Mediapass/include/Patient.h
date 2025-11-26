#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <iostream>

#include "sqlite3.h"


class Patient
{
    public:

        Patient();
        Patient(std::string nomPatient, int age,int numeroPatient, bool isHomme, float taille, float poids, std::string groupeSanguin,
                 std::string DocteurEncharge, std::string accompagnateur = "", int numAccompagnateur = 0 , std::string dateArrivee = ""
                 );
        Patient(Patient const& original);



        ~Patient();

        int GetidPatient();
        void SetidPatient(int val);
        std::string GetnomPatient();
        void SetnomPatient(std::string val);
        int GetnumeroPatient();
        void SetnumeroPatient(int val);
        int Getage();
        void Setage(int val);
        bool GetisHomme() ;
        void SetisHomme(bool val);
        float Gettaille() ;
        void Settaille(float val) ;
        std::string Getaccompagnateur()  ;
        void Setaccompagnateur(std::string val);
        int GetnumAccompagnateur() ;
        void SetnumAccompagnateur(int val) ;
        float Getpoids() ;
        void Setpoids(float val) ;
        std::string GetgroupeSanguin() ;
        void SetgroupeSanguin(std::string val) ;
        std::string GetDocteurEnCharge() ;
        void SetDocteurEnCharge(std::string val) ;
        //Consultation GetconsultationEnDate() { return consultationEnDate; }
        //void SetconsultationEnDate(Consultation val) { consultationEnDate = val; }
        //Dossier_Medical GetdossierPatient() { return dossierPatient; }
        //void SetdossierPatient(Dossier_Medical val) { dossierPatient = val; }
        std::string GetdateArrivee();
        // Vérification de dates
        std::string getCurrentDate();
        bool isValidDateFormat(const std::string& s);
        bool isRealDate(const std::string& s);
        bool isFutureDate(const std::string& s);
        std::string validateDate(const std::string& input);
        void SetdateArrivee(std::string val) ;
        std::string timePointToString(const std::chrono::system_clock::time_point& tp);
        bool sauvegarder(sqlite3* bd);
        static Patient read(sqlite3* bd , int id);
        bool update(sqlite3* bd);
        bool removee(sqlite3* bd);

    protected:

    private:

        int idPatient;
        std::string nomPatient;
        int numeroPatient;
        int age;
        bool isHomme; //True == Homme False == Femme
        float taille;
        std::string accompagnateur;
        int numAccompagnateur;
        float poids;
        std::string groupeSanguin;
        std::string DocteurEnCharge;
        //Consultation consultationEnDate;
        //Dossier_Medical dossierPatient;
        std::string dateArrivee;
};

#endif // PATIENT_H
