#include "Database.h"
#include "sqlite3.h"
#include <iostream>
#include <string>

Database::Database(const std::string& filename)
{
     if (sqlite3_open(filename.c_str(), &db) != SQLITE_OK) {
            throw std::runtime_error("Impossible d'ouvrir la BDD");
        }
}

Database::~Database()
{
    sqlite3_close(db);
}

sqlite3* Database::getDatabase() const
{
    return db;
};
