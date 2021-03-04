#pragma once
#include "Movie.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

// template<typename container_type>
// clasa singleton
class Repository
{
private:
	 vector<Movie> list;
	 
//	 static Repository* getInstance();
	// Repository() {};

public:
	
	Repository(vector<Movie> = vector<Movie>() );
	vector<Movie> getList();

	vector<Movie> generateList(string);

	// string toString();
	void toString();
	// de destructor cred ca se ocupa automat
};