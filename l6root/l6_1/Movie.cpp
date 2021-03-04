#include <string>
#include "Movie.h"

using std::string;
using std::to_string;

Movie::Movie(string id, string title, string genre, int year, int likes, string trailer) :id{ id }, title{ title }, genre{ genre }, year{ year }, likes{likes},
trailer{trailer}
{}

string Movie::getID() const { return id; }
void Movie::setID(string value) { id = value; }

string Movie::getTitle() const { return title; }
void Movie::setTitle(string value) { title = title; }

string Movie::getGenre() const { return genre; }
void Movie::setGenre(string value) { genre = value; }

int Movie::getYear() const { return year; }
void Movie::setYear(int value) { year = value; }

int Movie::getLikes() const { return likes; }
void Movie::setLikes(int value) { likes = value; }

string Movie::getTrailer() const { return trailer; }
void Movie::setTrailer(string value) { trailer = value; }

string Movie::toString() const
{
	/*
	std::stringstream aux2(token);	// convertesc un string
	aux2 >> year;					// la un int 
	*/
/*
	string year = getYear();
	std::stringstream aux(year);
	aux >> year;		// convertesc la int

	string likes = getLikes();
	std::stringstream aux2(likes);
	aux2 >> likes;		// convertesc la int
*/
	return 	getID() + ", " + getTitle() + ", " + getGenre() + ", " + to_string(getYear()) + ", " + to_string(getLikes());
}

bool operator==(const Movie& lhs, const Movie& rhs)
{
	return lhs.getID() == rhs.getID();
}

ostream& operator<<(ostream& os, const Movie& m) // o referinta la un stream pentru ca modific streamul
{
	//	os << "id = " << m.getID() <<"; \"" << m.getTitle() << "\" " << m.getGenre() << " " << m.getYear() << " " << m.getLikes();
	// os << m.getID() <<", " << m.getTitle() << ", " << m.getGenre() << ", " << m.getYear() << ", " << m.getLikes() << '\n';
	os << m.getID() << ", " << m.getTitle() << ", " << m.getGenre() << ", " << m.getYear() << ", " << m.getLikes() << ", " << m.getTrailer();
	// am ales intentionat sa nu afisam si link ul URL ( initial )
	return os;
}