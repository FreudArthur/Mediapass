#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"
#include <iostream>


class Database
{
    public:
        Database(const std::string& filename);
        ~Database();
        sqlite3*  getDatabase() const;

    protected:

    private:
        sqlite3* db;
};

#endif // DATABASE_H
