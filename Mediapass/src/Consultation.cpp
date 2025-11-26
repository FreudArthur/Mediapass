#include "Consultation.h"
#include "Prescriptions.h"
#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <string>

Consultation::Consultation(int idDossier_ , std::string dateConsultation_ ,std::string motif_, std::string medecin_, std::string diagnostic_)
{
    idDossier = idDossier_ ;
    dateConsultation = dateConsultation_;
    motif = motif_;
    medecin =medecin_;
    diagnostic=diagnostic_;
};
Consultation::Consultation(const Consultation& original)
{
    idDossier = original.idDossier ;
    dateConsultation = original.dateConsultation;
    motif = original.motif;
    medecin = original.medecin;
    diagnostic=original.diagnostic;
}

Consultation::~Consultation()
{
    //dtor
};
int Consultation::getidConsultation()
{
    return idConsultation;
};
void Consultation::setidConsultation(int val)
{
    idConsultation = val;
};

int Consultation::getidDossier()
{
    return idDossier;
};
void Consultation::setidDossier(int val)
{
    idDossier = val;
};



std::string Consultation::GetdateConsultation()
{
    return dateConsultation;
     };
void Consultation::SetdateConsultation(std::string val)
 {
     dateConsultation = val;
      };
std::string Consultation::Getmotif()
{
    return motif;
     };
void Consultation::Setmotif(std::string val)
{
    motif = val;
     };
std::string Consultation::Getmedecin()
{
    return medecin;
     };

void Consultation::Setmedecin(std::string val)
{
    medecin = val;
     };

std::string Consultation::Getdiagnostic()
 {
     return diagnostic;
      };
void Consultation::Setdiagnostic(std::string val)
{
    diagnostic = val;
     };
std::vector<Examens> Consultation::Getexamen()
{
    return examen;
     };
void Consultation::Setexamen(std::vector<Examens> val)
{
    examen = val;
     };
std::vector<Prescriptions> Consultation::Getprescripitons()
{
    return prescripitons;
     };

void Consultation::Setprescripitons(std::vector<Prescriptions> val)
{
    prescripitons = val;
     };

bool Consultation::sauvegarder(sqlite3* bd)
{
    sqlite3_stmt* stmt = nullptr;
    const char* sql = "INSERT INTO Consultations (dossier_id ,date, medecin, motif , diagnostic) VALUES (?, ? , ? ,? , ?);";

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur de requete : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idDossier);
    sqlite3_bind_text(stmt, 2, dateConsultation.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, medecin.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, motif.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, diagnostic.c_str(), -1, SQLITE_TRANSIENT);


    int rc = sqlite3_step(stmt); // execution


    sqlite3_finalize(stmt); // libération


    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur détectée : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    };
    //Mise a jour de l'id consultation
    setidConsultation(sqlite3_last_insert_rowid(bd));
    std::cout << "La consultation a bien été sauvegardé"<<std::endl;

    return true;
};

Consultation Consultation::read(sqlite3* bd , int id)
{
    const char* sql = "SELECT dossier_id , date , medecin , motif , diagnostic "" FROM Consultations WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt , 1 , id );

    Consultation c(0 , "","","","");

    if (sqlite3_step(stmt)==SQLITE_ROW)
    {
        c.setidConsultation(id);
        c.setidDossier(sqlite3_column_int(stmt ,0));
        c.SetdateConsultation(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 1)));
        c.Setmedecin(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 2)));
        c.Setmotif(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 3)));
        c.Setdiagnostic(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 4)));
    };
    sqlite3_finalize(stmt);
    return c;


};

bool Consultation::update(sqlite3* bd)
{
    const char* sql = "UPDATE Consultations SET date = ? , medecin = ? , motif =? , diagnostic =? " " WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);



    sqlite3_bind_text(stmt, 1, dateConsultation.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, medecin.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, motif.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, diagnostic.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, idConsultation);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;
}

bool Consultation::removee(sqlite3* bd)
{
    const char* sql = "DELETE FROM Consultations WHERE id =?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idConsultation);


    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;

};





