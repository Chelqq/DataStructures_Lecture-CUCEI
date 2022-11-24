#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

class Song{
private:
	
	std::string songName;
	std::string author;
	std::string ranking;
	bool flag;
	
public:
	
	Song();
	Song(const Song&);
	
	Song& operator = (const Song&);
	
	std::string getSongName() ;
	std::string getAuthor() ;
	std::string getRanking() ;
	
	std::string toString() const;
	
	void setSongName(const std::string& );
	void setAuthor(const std::string& );
	void setRanking(const std::string& );
	
	bool operator == (const Song&) const;
	bool operator != (const Song&) const;
	bool operator < (const Song&) const;
	bool operator > (const Song&) const;
	bool operator <= (const Song&) const;
	bool operator >= (const Song&) const;
	
	
	friend std::ostream& operator << (std::ostream&, Song&);
	friend std::istream& operator >> (std::istream&, Song&);
	
};

#endif
