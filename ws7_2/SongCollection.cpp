
/*
author:Mahrokh Sadrolodabaee
email:msadrolodabaee@myseneca.ca
Student ID:159436195
date:July 17,2021
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/



#include <list>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
#include "SongCollection.h"

using namespace std;
namespace sdds {



	std::string SongCollection::ltrim(const std::string& str)
	{
		string ret = str;
		return ret.substr(0,ret.find_first_not_of(' '));
	}

	std::string SongCollection::rtrim(const std::string& str)
	{
		string ret = str;
		return ret.substr(0,ret.find_last_not_of(' ')+1);
	}

	std::string SongCollection::fullTrim(const std::string& str)
	{
		string ret = str;
		return ltrim(rtrim(ret));
	}

	SongCollection::SongCollection(const char* filename)
	{
		if (!filename) {
			
			throw string("bad filename");
		}
		else {
			
            ifstream fin(filename);

            string myLine;
            Song song;
            while (getline(fin, myLine)) {


                string title = myLine.substr(0, 25);
             
                title = title.substr(0, title.find_last_not_of(' ')+1);
                title = title.erase(0, title.find_first_not_of(' '));
                song.m_title = title;
                myLine.erase(0, 25);


                string artist = myLine.substr(0, 25);
                artist = rtrim(artist);
                artist = artist.erase(0, artist.find_first_not_of(' '));
                song.m_artist = artist;
                myLine.erase(0, 25);
                

                string album = myLine.substr(0, 25);
                album = rtrim(album);
                album = album.erase(0, album.find_first_not_of(' '));
                song.m_album = album;
                myLine.erase(0, 25);
                

                string year = myLine.substr(0, 5);
                year = rtrim(year);
                year = year.erase(0, year.find_first_not_of(' '));

                if (!year.empty())     song.m_year = stoi(year);
                else  song.m_year = 0;//mine


                myLine.erase(0, 5);
              

                string length = myLine.substr(0, 5);
                fullTrim(length);
                song.m_songLength = stoi(length);

                myLine.erase(0, 5);
             

                string price = myLine.substr(0, 5);
                fullTrim(price);
                song.m_price = stod(price);
                myLine.erase(0, 5);
              
                m_arrOfSongs.push_back(song);//add each song to the vector
            }

		}
	}
   
    void SongCollection::display(std::ostream& out) const
    {
       
        for_each(m_arrOfSongs.begin(), m_arrOfSongs.end(), [=,&out](const Song& song) {
                out << song << endl;

        });


        size_t totalSongLength = accumulate(m_arrOfSongs.begin(), m_arrOfSongs.end(), (size_t)0,
            [=](size_t total, const Song song) {
                return total + song.m_songLength;
            });

        size_t h{ totalSongLength / 3600 };
        size_t m{ (totalSongLength % 3600) / 60 };
        size_t s {totalSongLength % 60};
   
        out << "----------------------------------------------------------------------------------------" << endl
            << "|" << right << setw(78) << setfill(' ') << 
            "Total Listening Time: " << h<<":" << m <<":"<< s << " |" << endl;
      
    }

    std::ostream& operator<<(std::ostream& out, const Song& theSong)
    {
        size_t minutes{ theSong.m_songLength / 60 };
        size_t seconds{ theSong.m_songLength % 60 };
        string empty;

        out << "| "
            << left << setw(20) << setfill(' ') << theSong.m_title << " | "
            << setw(15) << theSong.m_artist << " | "
            << setw(20) << theSong.m_album << " | "
            << right << setw(6);
            
            (theSong.m_year == 0 ? out<<empty : out<<theSong.m_year) << " | "
                 << minutes <<":"<<setw(2)<<setfill('0') <<seconds << " | "
                 << setw(4) << theSong.m_price << " |";

          
        return out;
    }

   
    void SongCollection::sort(const char* theField)
    {
        if (strcmp(theField, "length") == 0) {

            ::sort(m_arrOfSongs.begin(), m_arrOfSongs.end(),
                [=](const Song& song1, const Song& song2) {
                    return (song1.m_songLength < song2.m_songLength);


                });


        }
        else if (strcmp(theField, "title") == 0) {

            ::sort(m_arrOfSongs.begin(), m_arrOfSongs.end(),
                [=](const Song& song1, const Song& song2) {
                    return song1.m_title.compare(song2.m_title) <= 0;

                });

        }
        else if (strcmp(theField, "album") == 0) {

            ::sort(m_arrOfSongs.begin(), m_arrOfSongs.end(),
                [=](const Song& song1, const Song& song2) {
                    return song1.m_album.compare(song2.m_album) >= 0;

                });

        }
     
    }
   
    void SongCollection::cleanAlbum()
    {
    
        transform(m_arrOfSongs.begin(), m_arrOfSongs.end(), m_arrOfSongs.begin(), [=](Song& song) {
            song.m_album = song.m_album == "[None]" ? "" : song.m_album;
            return song;
            });

    }
   
    bool SongCollection::inCollection(const char* artist) const
    {
        bool ret=any_of(m_arrOfSongs.begin(), m_arrOfSongs.end(),[=](const Song& song) {
            return song.m_artist == string(artist); }
            );
        return ret;
    }
   
   ::list<Song> SongCollection::getSongsForArtist(const char* artist) const
    {
     
      auto count = count_if(m_arrOfSongs.begin(), m_arrOfSongs.end(),
           [=](const Song& song) {
               return song.m_artist == artist;
           });

       list<Song> ret(count);
       copy_if(m_arrOfSongs.begin(), m_arrOfSongs.end(), ret.begin(),
           [=](const Song& song) {
               return song.m_artist == artist;
           });
       return ret;
   }

}