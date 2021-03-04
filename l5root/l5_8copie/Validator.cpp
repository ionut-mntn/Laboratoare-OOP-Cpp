#include "Validator.h"



bool Validator::validate_year(const int &year)
{
	return (1887 <= year && year <= 2020); // primul film ever a aparut in 1887
}

bool Validator::validate_likes(const int &likes)
{
	return (0 <= likes);
}