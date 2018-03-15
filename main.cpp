#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include "Entitee/Anime.h"
#include "database/DBManager.h"

using namespace std;

vector<Anime> animeList;
DBManager DBManager;
ostringstream oss;

void listAnime();
void addAnime();
void updateAnime();
void deleteAnime();
void updateList();
bool update(string field, Anime anime, string toReplace, string type);
void writeLog(string message);

int main(int argc, char *argv[]) {
    updateList();
    int input = 0;

    do {
        printf("%s \n %s \n %s \n %s \n %s \n %s \n %s", "-----------MYANIMELIST------------", "1- Lister les animes", "2- Ajouter un anime", "3- Modifier un anime", "4- Supprimer un anime", "5- Quitter", ">");
        cin  >> input;
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

    return 0;
}

void listAnime() {
    updateList();
    for (Anime anime : animeList) {
        anime.describe();
    }
    printf("\n %s", "Press any key to quit...");
    getch();
}

void addAnime() {
    string name, startingDate, endingDate;
    int rating, episodeCompleted, nbrEpisodes;

    cout << "Entrez un nom :" << endl << "> ";
    cin >> name;
    cout << "Entrez une note :" << endl << "> ";
    cin >> rating;
    cout << "Entrez une date de debut (DD/MM/YYYY) :" << endl << "> ";
    cin >> startingDate;
    cout << "Entrez une date de fin (DD/MM/YYYY) :" << endl << "> ";
    cin >> endingDate;
    cout << "Entrez le nombre d'episodes que vous avez vu :" << endl << "> ";
    cin >> episodeCompleted;
    cout << "Entrez le nombre d'episodes total :" << endl << "> ";
    cin >> nbrEpisodes;

    string completion;
    if (episodeCompleted == nbrEpisodes) {
        completion = "Completed";
    } else if (episodeCompleted == 0) {
        completion = "Plan to watch";
    } else if (episodeCompleted > 0 && episodeCompleted < nbrEpisodes) {
        completion = "Watching";
    } else {
        completion = "Plan to watch";
    }

    oss << "INSERT INTO ANIME (NAMEROMANJI,RATING,STARTINGDATE,ENDINGDATE,EPISODESCOMPLETED,NBREPISODES,STATUS) VALUES ('" << name << "', " << rating << ", '" << startingDate << "', '" << endingDate << "', " << episodeCompleted << ", " << nbrEpisodes << ", '" << completion << "')";
    string query = oss.str();
    auto *finalquery = const_cast<char *>(query.c_str());
    vector<vector<string>> result = DBManager.query(finalquery);

    writeLog("Un anime a été ajouté à la base de donnée");
    printf("\n %s", "Press any key to quit...");
    updateList();
    getch();
}

void updateAnime() {
    cout << "Selectionnez l'anime a mettre a jour : " << endl;
    int choice, choice2;
    for (Anime anime : animeList) {
        anime.describe();
    }
    cout << "> ";
    cin >> choice;
    Anime theAnime = animeList.at(choice-1);
    theAnime.describe();
    cout << endl << "Quel champ voulez-vous mettre a jour" << endl
         << "1- Nom" << endl
         << "2- Note" << endl
         << "3- Date de debut" << endl
         << "4- Date de fin" << endl
         << "5- Nombre d'episodes completes" << endl
         << "6- Nombre d'episodes total" << endl
         << "7- Status" << endl
         << "8- Quitter" << endl;
    cout << "> ";
    cin >> choice2;
    string field = "", ifString = "";
    int ifInt = 0;
    bool callback = false;
    do {
        switch (choice2) {
            case 1:
                field = "NAMEROMANJI";
                cout << endl << "Entrez le nouveau nom :" << endl << "> ";
                cin >> ifString;
                callback = update(field, theAnime, ifString, "string");
                break;
            case 2:
                field = "RATING";
                cout << endl << "Entrez la nouvelle note :" << endl << "> ";
                cin >> ifInt;
                callback = update(field, theAnime, to_string(ifInt), "int");
                break;
            case 3:
                field = "STARTINGDATE";
                cout << endl << "Entrez la nouvelle date :" << endl << "> ";
                cin >> ifString;
                callback = update(field, theAnime, ifString, "string");
                break;
            case 4:
                field = "ENDINGDATE";
                cout << endl << "Entrez la nouvelle date :" << endl << "> ";
                cin >> ifString;
                callback = update(field, theAnime, ifString, "string");
                break;
            case 5:
                field = "EPISODESCOMPLETED";
                cout << endl << "Entrez le nombre d'épisodes :" << endl << "> ";
                cin >> ifInt;
                callback = update(field, theAnime, to_string(ifInt), "int");
                break;
            case 6:
                field = "NBREPISODES";
                cout << endl << "Entrez le nombre d'épisodes :" << endl << "> ";
                cin >> ifInt;
                callback = update(field, theAnime, to_string(ifInt), "int");
                break;
            case 7:
                field = "STATUS";
                cout << endl << "Entrez le nouveau status :" << endl << "> ";
                cin >> ifString;
                callback = update(field, theAnime, ifString, "string");
                break;
            default:
                break;
        }
    } while (choice != 8 && callback == false);

    writeLog("Un anime a été modifié");
    updateList();
    printf("\n %s", "Press any key to quit...");
    getch();
}

void deleteAnime() {
    cout << "Selectionnez l'anime a supprimer : " << endl;
    int choice, choice2;
    for (Anime anime : animeList) {
        anime.describe();
    }
    cout << "> ";
    cin >> choice;
    Anime theAnime = animeList.at(choice-1);
    theAnime.describe();
    cout << endl << "Voulez-vous vraiment supprimer cet anime ?" << endl
         << "1- Oui" << endl
         << "2- Non" << endl << "> ";
    cin >> choice2;
    do {
        if (choice2 == 1) {
            oss << "DELETE FROM ANIME WHERE NAMEROMANJI = '" << theAnime.getNameRomanji() << "'";
            string query = oss.str();
            auto *finalquery = const_cast<char *>(query.c_str());
            vector<vector<string>> result = DBManager.query(finalquery);
            animeList.erase(animeList.begin() + choice2 - 1);
            break;
        }
    } while (choice2 != 2);
    writeLog("Un anime a été supprimé de la base de donnée");
    printf("\n %s", "Press any key to quit...");
    getch();
}

void updateList() {
    animeList.clear();
    vector<vector<string>> result = DBManager.query(const_cast<char *>("SELECT * FROM ANIME"));
    int iterator = 1;
    for(auto it = result.begin(); it < result.end(); ++it) {
        vector<string> row = *it;
        Anime anime(iterator, row.at(1), stoi(row.at(2)), row.at(3), row.at(4), stoi(row.at(5)), stoi(row.at(6)), row.at(7));
        animeList.push_back(anime);
        iterator++;
    }
    writeLog("La liste d'anime a été mise à jour");
}

bool update(string field, Anime anime, string toReplace, string type) {
    if (type == "int") {
        oss << "UPDATE ANIME SET " << field << " = " << stoi(toReplace) << " WHERE NAMEROMANJI = '" << anime.getNameRomanji() << "'";
    } else if (type == "string") {
        oss << "UPDATE ANIME SET " << field << " = '" << toReplace << "' WHERE NAMEROMANJI = '" << anime.getNameRomanji() << "'";
    }
    string query = oss.str();
    auto *finalquery = const_cast<char *>(query.c_str());
    vector<vector<string>> result = DBManager.query(finalquery);
    return true;
}

void writeLog(string message) {
    time_t now = time(0);
    char* dt = ctime(&now);
    ofstream file(R"(../log.txt)", ios::ate);
    file << dt << " - " << message << endl;
    file.close();
}