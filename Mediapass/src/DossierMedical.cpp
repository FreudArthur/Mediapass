#include "DossierMedical.h"
#include "sqlite3.h"
#include <iostream>

DossierMedical::DossierMedical(int idPatient_)
{
    idPatient = idPatient;
}

DossierMedical::~DossierMedical()
{
    //dtor
}

int DossierMedical::GetidDossier()
{
    return idDossier;
     };
void DossierMedical::SetidDossier(int val)
{
    idDossier = val;
    };
int DossierMedical::GetidPatient()
{
    return idPatient;
     };
void DossierMedical::SetidPatient(int val)
{
    idPatient = val;
    };
std::vector<Consultation> DossierMedical::getConsultations()
{
    return consultations;
};
void DossierMedical::setConsultation(std::vector<Consultation> val)
{
    consultations= val;
};
std::vector<Antecedents> DossierMedical::getAntecedents()
{
    return antecedents;
};
void  DossierMedical::setAntecedent(std::vector<Antecedents> val)
{
    antecedents = val;
};

bool DossierMedical::sauvegarder(sqlite3* bd)
{
     sqlite3_stmt* stmt = nullptr;
    const char* sql = "INSERT INTO DossierMedical (patient_id ) VALUES (?);";

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur de requete : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idPatient);



    int rc = sqlite3_step(stmt); // execution


    sqlite3_finalize(stmt); // libération


    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur détectée : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }
    // mise a jour de l'id
    SetidDossier(sqlite3_last_insert_rowid(bd));
    std::cout << "Le dossier medical a bien été cree"<<std::endl;
    return true;
};

DossierMedical DossierMedical::read(sqlite3* bd , int id)
{
    const char* sql = "SELECT patient_id "" FROM DossierMedical WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt , 1 , id );

    DossierMedical d(0);

    if (sqlite3_step(stmt)==SQLITE_ROW)
    {
        d.SetidDossier(id);
        d.SetidPatient(sqlite3_column_int(stmt ,0));


    };
    sqlite3_finalize(stmt);
    return d;


};



bool DossierMedical::removee(sqlite3* bd)
{
    const char* sql = "DELETE FROM DossierMedical WHERE id =?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idDossier);


    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;

};
