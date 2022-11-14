#include "song.h"

using namespace std;

Song::Song ( ) { }

Song::Song (const Song& s) : songName(s.songName), author(s.author), ranking(s.ranking){
	
}

Song& Song::operator = (const Song& s) {
	
	songName = s.songName;
	author = s.author;
	ranking = s.ranking;
	
	return *this;
	
}


string Song::toString ( ) const{
	
	string result;
	
	
	result = "\t";
	result += songName;
	result += " - ";
	result += author;
	result += " - ";
	result += " #";
	result += ranking;
	result += "\n";

	
	return result;
	
}



string Song::getSongName ( ) {
	return songName;
}

string Song::getaAuthor ( ) {
	return author;
}

string Song::getRanking ( ) {
	return ranking;
}

void Song::setSongName (const string& n) {
	songName = n;
}

void Song::setAuthor (const string& a) {
	author = a;
}

void Song::setRanking (const string& r) {
	ranking = r;
}


bool Song::operator == (const Song& s) const {
	return songName == s.songName or author == s.author;
}

bool Song::operator != (const Song& s) const {
	return songName != s.songName or author != s.author;
}

bool Song::operator < (const Song& s) const {
	return songName < s.songName or author < s.author;
}

bool Song::operator > (const Song& s) const {
	return songName > s.songName or songName > s.songName;
}

bool Song::operator <= (const Song& s) const {
	return songName <= s.songName or author <= s.author;
}

bool Song::operator >= (const Song& s) const {
	return songName >= s.songName or author >= s.author;
}

ostream& operator << (ostream& os, Song& s){
	
	os << s.songName << endl;
	os << s.author << endl;
	os << s.ranking << endl;
	
	return os;
}

istream& operator >> (istream& is, Song& s){
	
	getline(is, s.songName);
	getline(is, s.author);
	getline(is, s.ranking);
	
	return is;
}

