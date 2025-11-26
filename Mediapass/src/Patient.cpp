#include "Patient.h"
#include <string>
#include <iostream>
#include "sqlite3.h"
#include <chrono>



Patient::Patient(
       std::string nom_pat, int age_,int numeroPatient_, bool is_homme, float taille_, float poids_, std::string groupe_sanguin,
                 std::string docteur_en_charge, std::string accompagnateur_ , int num_accompagnateur ,
        //Professionel DocteurEnCharge,
        //Consultation consultationEnDate,
        //Dossier_Medical dossierPatient,
        std::string dateArrivee_
        )
{

nomPatient = nom_pat;
age = age_;
numeroPatient = numeroPatient_;
isHomme = is_homme;
taille = taille_;
poids = poids_;
groupeSanguin = groupe_sanguin;
DocteurEnCharge = docteur_en_charge;
accompagnateur =  accompagnateur_ ;
numAccompagnateur = num_accompagnateur;
dateArrivee = validateDate(dateArrivee_);
}

Patient::Patient(Patient const& original)
    {

nomPatient = original.nomPatient;
isHomme = original.isHomme;
numeroPatient = original.numeroPatient;
taille = original.taille;
poids = original.poids;
groupeSanguin = original.groupeSanguin;
DocteurEnCharge = original.DocteurEnCharge;
accompagnateur =  original.accompagnateur ;
numAccompagnateur = original.numAccompagnateur;
    };

Patient::~Patient()
{
    //dtor
};



// Getteurs et setteurs

int Patient::GetidPatient()
{
    return idPatient;
    };

void Patient::SetidPatient(int val)
{
    idPatient = val;
    }

std::string Patient::GetnomPatient()
{
    return nomPatient;
    };

void Patient::SetnomPatient(std::string val)
{
    nomPatient = val;
    };

int Patient::GetnumeroPatient()
{
    return numeroPatient;
    };

void Patient::SetnumeroPatient(int val)
{
    numeroPatient = val;
    };
int Patient::Getage()
{
    return age;
};
void Patient::Setage(int val)
{
     age = val;
     }
bool Patient::GetisHomme() {
     return isHomme;
      };
void Patient::SetisHomme(bool val)
{
    isHomme = val;
     };
float Patient::Gettaille()
{
    return taille;
    };
void Patient::Settaille(float val)
{
    taille = val;
     };
std::string Patient::Getaccompagnateur()
{
    return accompagnateur;
     };
void Patient::Setaccompagnateur(std::string val)
{
    accompagnateur = val;
     };

int Patient::GetnumAccompagnateur()
{
    return numAccompagnateur;
    };
void Patient::SetnumAccompagnateur(int val)
{
    numAccompagnateur = val;
    };
float Patient::Getpoids()
{
    return poids;
     };
void Patient::Setpoids(float val)
{
    poids = val;
     };
std::string Patient::GetgroupeSanguin()
{
    return groupeSanguin;
     };
void Patient::SetgroupeSanguin(std::string val)
{
    groupeSanguin = val;
     };

std::string Patient::GetDocteurEnCharge()
{
    return DocteurEnCharge;
     };
void Patient::SetDocteurEnCharge(std::string val)
{
    DocteurEnCharge = val;
     };
        //Consultation GetconsultationEnDate() { return consultationEnDate; }
        //void SetconsultationEnDate(Consultation val) { consultationEnDate = val; }
        //Dossier_Medical GetdossierPatient() { return dossierPatient; }
        //void SetdossierPatient(Dossier_Medical val) { dossierPatient = val; }
std::string Patient::GetdateArrivee()
{
    return dateArrivee;
     };
void Patient::SetdateArrivee(std::string val)
{
    dateArrivee = validateDate(val);
    };


        // Verification des dates
//  format YYYY-MM-DD
std::string Patient::getCurrentDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    char buffer[11]; // YYYY-MM-DD + \0
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    return std::string(buffer);
};

// Vérifie que la chaîne est au format "YYYY-MM-DD" ou "YYYY/MM/DD"
bool Patient::isValidDateFormat(const std::string& s) {
    if (s.size() != 10) return false;
    if (!((s[4] == '-' && s[7] == '-') || (s[4] == '/' && s[7] == '/'))) return false;

    for (size_t i = 0; i < s.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(s[i])) return false;
    }
    return true;
};

// Vérifie que la date existe réellement
bool Patient::isRealDate(const std::string& s) {
    int y = std::stoi(s.substr(0,4));
    int m = std::stoi(s.substr(5,2));
    int d = std::stoi(s.substr(8,2));

    if (m < 1 || m > 12) return false;

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Vérification année bissextile
    bool leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (leap && m == 2) return d >= 1 && d <= 29;

    return d >= 1 && d <= daysInMonth[m - 1];
};

bool Patient::isFutureDate(const std::string& s) {
    std::tm tm = {};
    std::istringstream ss(s);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) return false; // pas une date valide, fallback

    auto user_time = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    auto now = std::chrono::system_clock::now();

    return user_time > now;
};

std::string Patient::validateDate(const std::string& input) {
         std::string date = input.empty() ? getCurrentDate() : input;

    if (!isValidDateFormat(date) || !isRealDate(date)) {
        std::cerr << "Date invalide, utilisation de la date actuelle.\n";
        date = getCurrentDate();
    }

    if (isFutureDate(date)) {
        std::cerr << "Date dans le futur, utilisation de la date actuelle.\n";
        date = getCurrentDate();
    }

    return date;
    };


std::string Patient::timePointToString(const std::chrono::system_clock::time_point& tp) {
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::tm tm = *std::localtime(&t);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    return buffer;
};




bool Patient::sauvegarder(sqlite3* bd)
{
    sqlite3_stmt* stmt = nullptr;
    const char* sql = "INSERT INTO Patients (nom, numero ,age , poids , taille ,isHomme,groupeSanguin, accompagnateur , numAccompagnateur, docteurEnCharge , dateArrivee) VALUES (?, ? , ? ,? ,? ,? ,? ,? ,?,?,? );";

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erreur de requete : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    }


    sqlite3_bind_text(stmt, 1, nomPatient.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, numeroPatient);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_double(stmt, 4, poids);
    sqlite3_bind_double(stmt, 5, taille);
    sqlite3_bind_int(stmt, 6, isHomme);
    sqlite3_bind_text(stmt, 7, groupeSanguin.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, accompagnateur.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 9, numAccompagnateur);
    sqlite3_bind_text(stmt, 10, DocteurEnCharge.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 11, dateArrivee.c_str(), -1, SQLITE_TRANSIENT);


    int rc = sqlite3_step(stmt); // execution


    sqlite3_finalize(stmt); // libération


    if (rc != SQLITE_DONE) {
        std::cerr << "Erreur détectée : " << sqlite3_errmsg(bd) << std::endl;
        return false;
    };
    //Mise a jour de l'id patient
    SetidPatient(sqlite3_last_insert_rowid(bd));
    std::cout << "Patient " << nomPatient <<" a bien été sauvegardé"<<std::endl;
    return true;

};

Patient Patient::read(sqlite3* bd , int id)
{
    const char* sql = "SELECT nom, numero ,age , poids , taille ,isHomme,groupeSanguin, accompagnateur , numAccompagnateur, docteurEnCharge , dateArrivee "" FROM Patients WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);

    sqlite3_bind_int(stmt , 1 , id );

    Patient p("",0,0,1,0.0,0.0,"", "","",0,"");

    if (sqlite3_step(stmt)==SQLITE_ROW)
    {
        p.SetidPatient(id);
        p.SetnomPatient(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 0)));
        p.SetnumeroPatient(sqlite3_column_int(stmt ,1));
        p.Setage(sqlite3_column_int(stmt ,2));
        p.Setpoids(sqlite3_column_double(stmt ,3));
        p.Settaille(sqlite3_column_double(stmt ,4));
        p.SetisHomme(sqlite3_column_int(stmt ,5));
        p.SetgroupeSanguin(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 6)));
        p.Setaccompagnateur(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 7)));
        p.SetnumAccompagnateur(sqlite3_column_int(stmt ,8));
        p.SetDocteurEnCharge(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 9)));
        p.SetdateArrivee(reinterpret_cast<const char*>(sqlite3_column_text(stmt , 10)));

    };
    sqlite3_finalize(stmt);
    return p;


};

bool Patient::update(sqlite3* bd)
{
    const char* sql = "UPDATE Patients SET nom = ?, numero=? ,age =?, poids=? , taille =?,isHomme =? ,groupeSanguin =? , accompagnateur = ?, numAccompagnateur = ?, docteurEnCharge =?, dateArrivee = ?"
    " WHERE id = ?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);



    sqlite3_bind_text(stmt, 1, nomPatient.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, numeroPatient);
    sqlite3_bind_int(stmt, 3, age);
    sqlite3_bind_double(stmt, 4,poids);
    sqlite3_bind_double(stmt, 5,taille);
    sqlite3_bind_int(stmt, 6,isHomme);
    sqlite3_bind_text(stmt, 7, groupeSanguin.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, accompagnateur.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 9, numAccompagnateur);
    sqlite3_bind_text(stmt, 10, DocteurEnCharge.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 11, dateArrivee.c_str(), -1, SQLITE_TRANSIENT);

    bool success = sqlite3_step(stmt) == SQLITE_DONE;
        if(success)
            std::cout << "Patient "<< nomPatient << " a bien ete mis a jour"<<std::endl;

    sqlite3_finalize(stmt);

    return success;
}

bool Patient::removee(sqlite3* bd)
{
    const char* sql = "DELETE FROM Patients WHERE id =?";
    sqlite3_stmt* stmt = nullptr;
    sqlite3_prepare_v2(bd, sql, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, idPatient);


    bool success = sqlite3_step(stmt) == SQLITE_DONE;
    if(success)
            std::cout << "Patient "<< nomPatient << " a bien ete retire"<<std::endl;
    sqlite3_finalize(stmt);

    return success;

};


