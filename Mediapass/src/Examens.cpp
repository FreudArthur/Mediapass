#include "Examens.h"
#include "sqlite3.h"
#include <string>
#include<iostream>

Examens::Examens(int idConsultation_ ,std::string type_ , std::string dateExamen_ , std::string resultat_)
{
    idConsultation = idConsultation_;
    typeexamen = type_;
    dateExamen = dateExamen_;
    resultat = resultat_;
};

Examens::Examens(const Examens& e)
{
    idConsultation = e.idConsultation;
    typeexamen = e.typeexamen;
    dateExamen = e.dateExamen;
    resultat = e.resultat;
};
Examens::~Examens()
{
    //dtor
};

int Examens::getidExamen()
{
    return idExamen;
};
void Examens::setidExamen(int val)
{
    idExamen = val ;
};
int Examens::getidConsultation()
{
    return idConsultation;
};
void Examens::setidConsultation(int val)
{
    idConsultation = val;
};

std::string Examens::Gettypeexamen()
{
    return typeexamen;
     };

void Examens::Settypeexamen(std::string val)
{
    typeexamen = val;
     };

std::string Examens::GetdateExamen()
{
    return dateExamen;
     };

void Examens::SetdateExamen(std::string val)
{
    dateExamen = val;
     };
std::string Examens::Getresultat()
{
    return resultat;
     };

void Examens::Setresultat(std::string val)
{
    resultat = val;
     };
bool Examens::sauvegarder(sqlite3* bd)
{
    sqlite3_stmt* stmt = nullptr;
    const char* sql = "INSERT INTO Examens (consultation_id ,typeExamen, dateExamen, resultats ) VALUES (?, ? , ? ,? );";

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur de requete : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idConsultation);
    sqlite3_bind_text(stmt, 2, typeexamen.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, dateExamen.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, resultat.c_str(), -1, SQLITE_TRANSIENT);


    int rc = sqlite3_step(stmt); // execution


    sqlite3_finalize(stmt); // libération


    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur détectée : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    };
    //Mise a jour de l'id Examen
    setidExamen(sqlite3_last_insert_rowid(bd));
    std::cout << "L'Examen a bien été sauvegardé"<<std::endl;
    return true;
};

Examens Examens::read(sqlite3* bd , int id)
{
    const char* sql = "SELECT consultation_id ,typeExamen, dateExamen, resultats "" FROM Examens WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt , 1 , id);

    Examens e(0 , "","","");

    if (sqlite3_step(stmt)==SQLITE_ROW)
    {
        e.setidExamen(id);
        e.setidConsultation(sqlite3_column_int(stmt ,0));
        e.Settypeexamen(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 1)));
        e.SetdateExamen(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 2)));
        e.Setresultat(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 3)));

    };
    sqlite3_finalize(stmt);
    return e;


};

bool Examens::update(sqlite3* bd)
{
    const char* sql = "UPDATE Examens SET typeExamen = ? , dateExamen = ? , resultats =?  " " WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);



    sqlite3_bind_text(stmt, 1, typeexamen.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, dateExamen.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, resultat.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, idExamen);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;
}

bool Examens::removee(sqlite3* bd)
{
    const char* sql = "DELETE FROM Examens WHERE id =?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idExamen);


    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;

};
