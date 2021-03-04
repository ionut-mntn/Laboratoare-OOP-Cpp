#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

#include "Movie.h"
#include "Controller.h"
#include "UI.h"

using std::cin;
using std::cout;

using std::string;
using std::vector;

using std::ifstream;
using std::getline;

ifstream get_input(string file)
{
	string mat;
	ifstream input_stream;
	input_stream.open(file);
	try
	{
		cout << mat << '\n';
		return input_stream;
	}
	catch (...) // sau ``exception&`` cred
	{
		cout << "eroare la deschiderea fisierului\n";
	}
}

/*
vector<Movie>parse_input(string linii_fisier)
{
	int i = 0;
	while (linii_fisier[i] != nullptr)
	{
		do
		{
			
			i++;
		}while(linii_fisier[i] != '\n')
	}
}
*/

vector<Movie>parse_input(ifstream file)
{
	int id;
	string title;
	string genre;
	int year; 
	int likes;
	string trailer;

	vector<Movie> lista;

	char c; // ca sa citesc (dar sa ignor)  virgulele
	char s; // ca sa citesc (dar sa ignor) spatiile
	string line;
	while (getline(file, line)) // cat timp pot citi in variabila `line` linii din fisier
	{ // cred ca pentru getline, spearatorul implicit e '\n', dupa cum o spune si numele
/*
		cout << line << '\n';
		cin.get();
		std::istringstream ss(line); // imi iau un stream
		ss.seekg(0);
		ss  >> id >> c >> title >> c >> genre >> c >>  year >> c >>  likes >> c >>  trailer;
*/
//		std::istringstream token;
//		while (getline(line, token))
		
		


/*
		//ASTA MERGE
		std::stringstream stream; // creez un stream
		stream << line;		// pun in stream linia curent obtinuta

		string token;
*/



		// void* pointeri = { &id, &title, &genre, &year, &likes, &trailer };
		// auto pointeri = { &id, &title, &genre, &year, &likes, &trailer };
		//auto * pointeri = { &id, &title, &genre, &year, &likes, &trailer };
/*
		while(getline(stream, token, ',' ))
		{
			cout << "token="<< token << '\n';
			// cout << token << '\n';
		}
*/

//		cout << id << " " << title << " " << genre << " " << year << " " << likes << " " << trailer << '\n';
		// ss  >>  std::noskipws >> id >> c >> title >> c >> genre >> c >>  year >> c >>  likes >> c >>  trailer;
		//ss >> std::noskipws >> id >> c >> s >> title >> c >> s >> genre >> c >> s >>  year >> c >> s >>  likes >> c >> s >>  trailer;


		std::stringstream stream; // creez un stream
		stream << line;		// pun in stream linia curent obtinuta
		string token;
//		id = getline(stream, token, ',');

		/*
		for (int i = 0; i < 1; i++)
		{
			pointeri[i] = getline(stream, token, ',');
		}
		*/

		getline(stream, token, ',');
		//id = (int)token;
		std::stringstream aux(token);
		aux >> id;
		cout << id << '\n';
//		cout << token << '\n';

		getline(stream, token, ',');
		title = token;
		cout << title << '\n';
		getline(stream, token, ',');
		genre = token;
		cout << genre << '\n';

		getline(stream, token, ',');
		std::stringstream aux2(token);
		aux2 >> year;
		cout << year << '\n';

		getline(stream, token, ',');
		std::stringstream aux3(token);
		aux3 >> likes;

		getline(stream, token, ',');
		trailer = token;

		lista.push_back(Movie(int(id), title, genre, int(year), int(likes), trailer));
	}
	return lista;
}

vector<Movie> create_list(string file)
{
	return parse_input(get_input(file));
}


void start()
{
	return;
//	vector<Movie> lista = create_list();
	/*
	Repository(lista);
	Controller ctrl(repo);
	UI ui(ctrl);
	ui.start();
	*/
}

int main()
{

	Movie m1(1, "The Shawshank Redemption", "Drama", 1994, 93, "https://www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");
	Movie m2(2, "The Godfather", "Crime, Drama", 1972, 91, "https://www.imdb.com/video/vi1348706585?playlistId=tt0068646&ref_=tt_ov_vi");
	Movie m3(3, "The Godfather II", "Crime, Drama", 1974, 90, "https://www.imdb.com/video/vi696162841?playlistId=tt0071562&ref_=tt_ov_vi");
	Movie m4(4, "The Dark Knight", "Drama", 2008, 90, "https://www.imdb.com/video/vi324468761?playlistId=tt0468569&ref_=tt_ov_vi");
	Movie m5(5, "12 Angry Men", "Drama", 1957, 89, "https://www.imdb.com/video/vi3452609817?playlistId=tt0050083&ref_=tt_ov_vi");
	Movie m6(6, "Schindler's List", "Biography, Drama, History", 1993, 89, "https://www.imdb.com/video/vi1158527769?playlistId=tt0108052&ref_=tt_ov_vi");
	Movie m7(7, "The Lord of the Rings: The Return of the King", "Adventure, Drama, Fantasy", 2003, 89, "https://www.imdb.com/video/vi2073101337?playlistId=tt0167260&ref_=tt_ov_vi");
	Movie m8(8, "Pulp Fiction", "Crime, Drama", 1994, 89, "https://www.imdb.com/video/vi2620371481?playlistId=tt0110912&ref_=tt_ov_vi");
	Movie m9(9, "The Good, the Bad and the Ugly", "Western", 1966, 88, "https://www.imdb.com/video/vi2789278233?playlistId=tt0060196&ref_=tt_ov_vi" );
	Movie m10(10, "The Lord of the Rings: The Fellowship of the Ring", "Action, Adventure, Drama", 2001, 88, "https://www.imdb.com/video/vi2073101337?playlistId=tt0120737&ref_=tt_ov_vi");
	Movie m11(11, "Fight Club", "Drama", 1999, 88, "https://www.imdb.com/video/vi781228825?playlistId=tt0137523&ref_=tt_ov_vi");
	Movie m12(12, "Forrest Gump", "Drama, Romance" , 1994, 88, "https://www.imdb.com/video/vi3567517977?playlistId=tt0109830&ref_=tt_ov_vi");
	Movie m13(13, "Miracle in Cell No.7", "Drama", 2020, 93, "https://www.imdb.com/video/vi3877612057?playlistId=tt0111161&ref_=tt_ov_vi");

	// vector<Movie> lista{ m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13 };
	vector<Movie> lista = create_list("Movies.txt");
	
	// auto i; // evident ca nu pot initializa asa ! La fel ca la const !!
	int nr = 0;
	
	/*
	for (auto i = lista.begin(); i < lista.end(); i++)
		cout << lista.at(i) << '\n';			// NORMAL CA NU MERGE ASA; i e de tip pointer or smth... iar `.at()` asteapta un intreg!!
	*/

	for (int i = 0; i < lista.size(); i++)
		cout << lista.at(i) << '\n';
	

	//	start();
	return 0;
}
