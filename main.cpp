#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <conio.h>
#include "Entitee/Anime.h"
#include "lib/sqlite3.h"
#include "database/DBManager.h"

using namespace std;

vector<Anime> animeList;
DBManager DBManager;

void listAnime();
void addAnime();
void updateAnime();
void deleteAnime();

string to_string(Anime anime)
{
    ostringstream ss;
    ss << anime;
    return ss.str();
}

int main(int argc, char *argv[]) {
    /*Anime firstAnime(1, "Mahou Tsukai no Yome",  10, "12/11/2017", "01/04/2018", 24, 18, "Watching");
    Anime firstAnime2(2, "Fate/Stay Night : Unlimited Blade Works",  9, "12/11/2017", "01/04/2018", 24, 18, "Watching");
    Anime firstAnime3(3, "Citrus",  8, "12/11/2017", "01/04/2018", 24, 18, "Watching");
    animeList.push_back(firstAnime);
    animeList.push_back(firstAnime2);
    animeList.push_back(firstAnime3);
    animeList.erase(animeList.begin()+1);*/

    int input = 0;

    do {
        printf("%s \n %s \n %s \n %s \n %s \n %s \n %s", "-----------MYANIMELIST------------", "1- Lister les animes", "2- Ajouter un anime", "3- Modifier un anime", "4- Supprimer un anime", "5- Quitter", ">");
        cin  >>input;
        switch (input) {
            case 1:
                listAnime();
                break;
            case 2:
                addAnime();
                break;
            case 3:
                updateAnime();
                break;
            case 4:
                deleteAnime();
                break;
            default:
                break;
        }
    } while (input != 5);

    /**/
    /*ofstream file(R"(../test.txt)", ios::app);
    ifstream file2(R"(../test.txt)");
    string line;

    for (const auto &i : animeList) {
        file << to_string(i);
    }
    
    while(getline(file2,line))
    {
        cout << line << endl;
    }

    file.close();
    file2.close();*/

    return 0;
}

void listAnime() {
    vector<vector<string>> result = DBManager.query(const_cast<char *>("SELECT * FROM ANIME"));
    for(auto it = result.begin(); it < result.end(); ++it)
    {
        vector<string> row = *it;
        printf("%d- %s, note : %d, début : %s ; fin : %s, épisodes : %d/%d. Status : %s", row.at(0), row.at(1), row.at(2), row.at(3), row.at(4), row.at(5), row.at(6), row.at(7));
    }
    printf("\n %s", "Press any key to quit...");
    getch();
}

void addAnime() {

}

void updateAnime() {

}

void deleteAnime() {

}

