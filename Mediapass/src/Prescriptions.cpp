#include "Prescriptions.h"
#include "sqlite3.h"
#include <iostream>
#include <string>

Prescriptions::Prescriptions(int idConsultation_ ,std::string medicament_ , std::string dosage_ , std::string frequence_ , std::string duree_)
{
    idConsultation = idConsultation_;
    medicament = medicament_;
    dosage = dosage_;
    frequence = frequence_;
    duree = duree_;
};
Prescriptions::Prescriptions(const Prescriptions& p)
{
    idConsultation = p.idConsultation;
    medicament = p.medicament;
    dosage = p.dosage;
    frequence = p.frequence;
    duree = p.duree;
};

Prescriptions::~Prescriptions()
{
    //dtor
};

int Prescriptions::getidPrescription()
{
    return idPrescription;
};

void Prescriptions::setidPrescription(int val)
{
    idPrescription = val;
};
int Prescriptions::getidConsultation()
{
    return idConsultation;
};
void Prescriptions::setidConsultation(int val)
{
    idConsultation = val;
};

std::string Prescriptions::Getmedicament()
{
    return medicament;
     };
void Prescriptions::Setmedicament(std::string val)
{
    medicament = val;
     };
std::string Prescriptions::Getdosage()
{
    return dosage;
     };
void Prescriptions::Setdosage(std::string val)
{
    dosage = val;
     };
std::string Prescriptions::Getfrequence()
{
    return frequence;
     };
void Prescriptions::Setfrequence(std::string val)
{
     frequence = val;
      };
std::string Prescriptions::Getduree()
{
    return duree;
     };
void Prescriptions::Setduree(std::string val)
{
    duree = val;
    };

bool Prescriptions::sauvegarder(sqlite3* bd)
{
     sqlite3_stmt* stmt = nullptr;
    const char* sql = "INSERT INTO Prescriptions (consultation_id ,medicament, frequence, dosage, duree ) VALUES (?, ? , ? ,? , ?);";

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur de requete : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idConsultation);
    sqlite3_bind_text(stmt, 2, medicament.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, frequence.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, dosage.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, duree.c_str(), -1, SQLITE_TRANSIENT);


    int rc = sqlite3_step(stmt); // execution


    sqlite3_finalize(stmt); // libération


    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur détectée : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    };
    //Mise a jour de l'id prescription
    setidPrescription(sqlite3_last_insert_rowid(bd));
    std::cout << "La prescription a bien été sauvegardé"<<std::endl;
    return true;
};

Prescriptions Prescriptions::read(sqlite3* bd , int id)
{
    const char* sql = "SELECT consultation_id ,medicament, frequence, dosage, duree  "" FROM Prescriptions WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt , 1 , id);

    Prescriptions p(0 , "","","","");

    if (sqlite3_step(stmt)==SQLITE_ROW)
    {
        p.setidPrescription(id);
        p.setidConsultation(sqlite3_column_int(stmt ,0));
        p.Setmedicament(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 1)));
        p.Setfrequence(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 2)));
        p.Setdosage(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 3)));
        p.Setduree(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 4)));


    };
    sqlite3_finalize(stmt);
    return p;


};

bool Prescriptions::update(sqlite3* bd)
{
    const char* sql = "UPDATE Prescriptions SET medicament = ? , frequence = ? , dosage =?, duree=?  " " WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);



    sqlite3_bind_text(stmt, 1, medicament.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, frequence.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, dosage.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, duree.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, idPrescription);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;
}

bool Prescriptions::removee(sqlite3* bd)
{
    const char* sql = "DELETE FROM Prescriptions WHERE id =?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idPrescription);


    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;

};

