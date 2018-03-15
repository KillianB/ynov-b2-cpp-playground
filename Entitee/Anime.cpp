//
// Created by Restauration on 12/02/2018.
//

#include "Anime.h"
#include <iostream>

Anime::Anime(int id, const string &nameRomanji, int rating, const string &startingDate,
             const string &endingDate, int nbrEpisodes, int episodesCompleted, const string &status) : id(id), nameRomanji(
        nameRomanji), rating(rating), startingDate(startingDate), endingDate(endingDate),
                                                                                                       nbrEpisodes(
                                                                                                               nbrEpisodes),
                                                                                                       episodesCompleted(
                                                                                                               episodesCompleted),
                                                                                                       status(status) {}

Anime::Anime() {}

Anime::~Anime() {

}

const string &Anime::getNameRomanji() const {
    return nameRomanji;
}

void Anime::setNameRomanji(const string &nameRomanji) {
    Anime::nameRomanji = nameRomanji;
}

int Anime::getRating() const {
    return rating;
}

void Anime::setRating(int rating) {
    Anime::rating = rating;
}

const string &Anime::getStartingDate() const {
    return startingDate;
}

void Anime::setStartingDate(const string &startingDate) {
    Anime::startingDate = startingDate;
}

const string &Anime::getEndingDate() const {
    return endingDate;
}

void Anime::setEndingDate(const string &endingDate) {
    Anime::endingDate = endingDate;
}

int Anime::getNbrEpisodes() const {
    return nbrEpisodes;
}

void Anime::setNbrEpisodes(int nbrEpisodes) {
    Anime::nbrEpisodes = nbrEpisodes;
}

int Anime::getEpisodesCompleted() const {
    return episodesCompleted;
}

void Anime::setEpisodesCompleted(int episodesCompleted) {
    Anime::episodesCompleted = episodesCompleted;
}

const string &Anime::getStatus() const {
    return status;
}

void Anime::setStatus(const string &status) {
    Anime::status = status;
}

void Anime::describe() {
    cout << getId() << "- " << "Anime : "
         << getNameRomanji() << ". De : "
         << getStartingDate() << " a "
         << getEndingDate() << ". Note : "
         << getRating() << ". Status : "
         << getStatus() << ". Episodes : "
         << getEpisodesCompleted() << "/"
         << getNbrEpisodes() << "." << endl;
}

int Anime::getId() const {
    return id;
}

void Anime::setId(int id) {
    Anime::id = id;
}


