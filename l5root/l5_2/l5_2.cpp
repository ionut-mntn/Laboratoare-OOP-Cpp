#include <iostream>
#include <string>
#include "Movie.h"

using std::cout;
using std::string;

int main()
{
	Movie m1( 1, "The Shawshank Redemption", "Drama", 1994, 93, "https://www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");
	Movie m2( 2, "Miracle in Cell No.7", "Drama", 1994, 93, "https://www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");
/*
	string s1 = "abc";
	string s2 = "def";
	cout << s1 + s2 << '\n';
*/

	cout << (m1 == m2) << '\n';
	cout << m1 << '\n';
}
