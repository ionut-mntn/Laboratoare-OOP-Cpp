#pragma once

#include <string>

using std::string;

class Validator
{
private:

public:

	const int lowest_likes = 0;
	const int highest_likes = 10005;

	const int lowest_year = 1887;
	const int highest_year = 1887;

	bool validate_likes(const int &); // nu validez tipul, validez logica !!
	bool validate_year(const int &);
		
};