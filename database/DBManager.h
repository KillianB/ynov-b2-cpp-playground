//
// Created by Restauration on 13/02/2018.
//

#ifndef LEARNING_DBMANAGER_H
#define LEARNING_DBMANAGER_H

#include <vector>
#include "../Entitee/Anime.h"
#include "../lib/sqlite3.h"

class DBManager {
public:
    DBManager();
    virtual ~DBManager();

    bool open(char* filename);
    vector<vector<string> > query(char* query);
    void close();

private:
    sqlite3 *database;
};

#endif
