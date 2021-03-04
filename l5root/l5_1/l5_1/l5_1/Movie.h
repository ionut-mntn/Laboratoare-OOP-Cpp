#pragma once
#include <string>
using std::string;
class Movie
{
private:
	string title;
	string genre;
	int year; //release year
	int likes;
	string trailer; // trailer link

public:
	/* getters & setters for all attributes*/
	Movie(string, string, int, int, string);
	string getTitle();
	void setTitle(string);
	string getGenre();
	void setGenre(string);
	int getYear();
	void setYear(int);
	int getLikes();
	void setLikes(int);
	string getTrailer();
	void setTrailer(string);
};