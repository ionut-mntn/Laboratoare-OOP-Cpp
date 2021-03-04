#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Movie
{
private:

	int id;

	string title;
	string genre;
	int year; //release year
	int likes;
	string trailer; // trailer link

public:
	/* Constructor */
	Movie(int, string, string, int, int, string);
	
	/* getters & setters for all attributes*/

	int getID() const;
	void setID(int);

	string getTitle() const;
	void setTitle(string);
	
	string getGenre() const;
	void setGenre(string);
	
	int getYear() const;
	void setYear(int);
	
	int getLikes() const;
	void setLikes(int);
	
	string getTrailer() const;
	void setTrailer(string);
};
bool operator==(const Movie& lhs, const Movie& rhs);
ostream& operator<<(ostream& os, const Movie& m); // o referinta la un stream pentru ca modific streamul