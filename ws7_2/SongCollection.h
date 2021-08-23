/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 17,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_SONGSCOLLECTION_H
#define SDDS_SONGSCOLLECTION_H

#include <string>
#include <vector>
#include <list>
namespace sdds {

    class SongCollection;
    struct Song {

        std::string m_artist;
        std::string m_title;
        std::string m_album;
        double m_price{};
        size_t m_year{};
        size_t m_songLength{};

        friend class SongCollection;
    };
    
    class SongCollection {

        std::vector<Song> m_arrOfSongs;
        size_t m_numOfSongs{};
        std::string ltrim(const std::string& str);
        std::string rtrim(const std::string& str);
        std::string fullTrim(const std::string& str);
   
    public:
        SongCollection(const char*);
        void display(std::ostream& out) const;
        void sort(const char*);
        void cleanAlbum();
        bool inCollection(const char*) const;
        std::list<Song> getSongsForArtist(const char*) const;


    };
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif