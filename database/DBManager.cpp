//
// Created by Restauration on 13/02/2018.
//

#include "DBManager.h"
#include <iostream>

DBManager::DBManager()
{
    database = nullptr;
}

DBManager::~DBManager()
{

}

bool DBManager::open(char* filename)
{
    return sqlite3_open(filename, &database) == SQLITE_OK;
}

vector<vector<string> > DBManager::query(char* query)
{
    open(const_cast<char *>("MyAnimeList.db"));
    sqlite3_stmt *statement;
    vector<vector<string> > results;

    if(sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK)
    {
        int cols = sqlite3_column_count(statement);
        int result = 0;
        while(true)
        {
            result = sqlite3_step(statement);

            if(result == SQLITE_ROW)
            {
                vector<string> values;
                for(int col = 0; col < cols; col++)
                {
                    values.emplace_back((char*)sqlite3_column_text(statement, col));
                }
                results.push_back(values);
            }
            else
            {
                break;
            }
        }

        sqlite3_finalize(statement);
    }

    string error = sqlite3_errmsg(database);
    if(error != "not an error") cout << query << " " << error << endl;

    close();
    return results;
}

void DBManager::close()
{
    sqlite3_close(database);
}