#include "Antecedents.h"
#include "Patient.h"
#include "sqlite3.h"
#include <iostream>

Antecedents::Antecedents(int idDossier_ ,std::string type_ , std::string description_  , std::string datedebut_  ,std::string datefin_ )
{
    idDossier = idDossier_;
    type = type_;
    description = description_;
    datedebut = datedebut_;
    datefin = datefin_;
};

Antecedents::Antecedents(const Antecedents& original)
{
    idDossier = original.idDossier;
    type = original.type;
    description = original.description;
    datedebut = original.datedebut;
    datefin = original.datefin;
}
Antecedents::~Antecedents()
{
    //dtor
};

int Antecedents::getidAntecedent()
{
    return idAntecedent;
};
void Antecedents::setidAntecedent(int val)
{
    idAntecedent = val ;
};
int Antecedents::getidDossier()
{
    return idDossier;
};
void Antecedents::setidDossier(int val)
{
    idDossier = val;
};


std::string Antecedents::Gettype() {
     return type;
      };
void Antecedents::Settype(std::string val)
 {
     type = val;
     };
std::string Antecedents::Getdescription()
{
    return description;
     };

void Antecedents::Setdescription(std::string val)
{
    description = val;
     };
std::string Antecedents::Getdatedebut()
{
    return datedebut;
     };
void Antecedents::Setdatedebut(std::string val)
{
    datedebut = val;
     };
std::string Antecedents::Getdatefin()
{
    return datefin;
     };
void Antecedents::Setdatefin(std::string val)
{
    datefin = val;
     };

bool Antecedents::sauvegarder(sqlite3* bd)
{
     sqlite3_stmt* stmt = nullptr;
    const char* sql = "INSERT INTO Antecedents (dossier_id ,type,description, datedebut, datefin ) VALUES (?, ? , ? ,?,? );";

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur de requete : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }

    sqlite3_bind_int(stmt, 1, idDossier);
    sqlite3_bind_text(stmt, 2, type.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, datedebut.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, datefin.c_str(), -1, SQLITE_TRANSIENT);


    int rc = sqlite3_step(stmt); // execution


    sqlite3_finalize(stmt); // libération


    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur détectée : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }
    //Mise a jour de l'id antécedent
    setidAntecedent(sqlite3_last_insert_rowid(bd));
    std::cout << "L'Antecedent a bien été sauvegardé"<<std::endl;
    return true;
};

Antecedents Antecedents::read(sqlite3* bd , int id)
{
    const char* sql = "SELECT dossier_id , type , description , date_debut , date_fin "" FROM Antecedents WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt , 1 , id );

    Antecedents a(0 , "","","","");

    if (sqlite3_step(stmt)==SQLITE_ROW)
    {
        a.setidAntecedent(id);
        a.setidDossier(sqlite3_column_int(stmt ,0));
        a.Settype(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 1)));
        a.Setdescription(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 2)));
        a.Setdatedebut(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 3)));
        a.Setdatefin(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 4)));
    };
    sqlite3_finalize(stmt);
    return a;

};

bool Antecedents::update(sqlite3* bd)
{
    const char* sql = "UPDATE Antecedents SET type = ? , description = ? , date_debut =? , date_fin =? " " WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);



    sqlite3_bind_text(stmt, 1, type.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, description.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, datedebut.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, datefin.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, idAntecedent);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;
};
bool Antecedents::removee(sqlite3* bd)
{
    const char* sql = "DELETE FROM Antecedents WHERE id =?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idAntecedent);


    bool success = sqlite3_step(stmt) == SQLITE_DONE;

    sqlite3_finalize(stmt);
    return success;
};

