//
// Created by Restauration on 12/02/2018.
//

#ifndef LEARNING_ANIME_H
#define LEARNING_ANIME_H

#include <string>
#include <list>
#include <ostream>

using namespace std;

class Anime {
    private:
        int id;
        string nameRomanji;
        int rating;
        string startingDate;
        string endingDate;
        int nbrEpisodes;
        int episodesCompleted;
        string status;
    public:
    Anime(int id, const string &nameRomanji, int rating, const string &startingDate,
          const string &endingDate, int nbrEpisodes, int episodesCompleted, const string &status);

    Anime();

    void describe();

    virtual ~Anime();

    const string &getNameRomanji() const;

    void setNameRomanji(const string &nameRomanji);

    int getRating() const;

    void setRating(int rating);

    const string &getStartingDate() const;

    void setStartingDate(const string &startingDate);

    const string &getEndingDate() const;

    void setEndingDate(const string &endingDate);

    int getNbrEpisodes() const;

    void setNbrEpisodes(int nbrEpisodes);

    int getEpisodesCompleted() const;

    void setEpisodesCompleted(int episodesCompleted);

    const string &getStatus() const;

    void setStatus(const string &status);

    int getId() const;

    void setId(int id);
};


#endif //LEARNING_ANIME_H
