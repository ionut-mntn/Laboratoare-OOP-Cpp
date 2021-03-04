// !! REFERINTA = POINTER CU DEREFERENTIERE AUTOMATA !!

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <exception>

#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::getline;


using std::string;
using std::vector;

ifstream get_input(string file)
{
	string mat;
	ifstream input_stream;
	input_stream.open(file);
	try
	{
//		cout << mat << '\n';
		return input_stream;
	}
	catch (...) // sau ``exception&`` cred
	{
		cout << "eroare la deschiderea fisierului\n";
		// return nullptr; // i dunno
	}
}

vector<Movie>parse_input(ifstream file)
{
	int id;
	string title;
	string genre;
	int year; 
	int likes;
	string trailer;

	vector<Movie> lista;

	///char c; // ca sa citesc (dar sa ignor)  virgulele
	char s; // ca sa citesc (dar sa ignor) spatiile
	string line;
	while (getline(file, line)) // cat timp pot citi in variabila `line` linii din fisier
	{ // cred ca pentru getline, spearatorul implicit e '\n', dupa cum o spune si numele
		
		std::stringstream stream; // creez un stream
		stream << line;		// pun in stream linia curent obtinuta
		string token;

		getline(stream, token, ',');
		std::stringstream aux(token);	// convertesc la int
		aux >> id;
		
		getline(stream, token, ',');
		token = token.substr(1); // elimin si space ul de la inceputul string ului
		title = token;
		getline(stream, token, ',');
		token = token.substr(1); // elimin si space ul de la inceputul string ului
		genre = token;

		getline(stream, token, ',');
		token = token.substr(1);	// elimin si space ul de la inceputul string ului
		std::stringstream aux2(token);	// convertesc la int
		aux2 >> year;

		getline(stream, token, ',');	// convertesc la int
		token = token.substr(1);	// elimin si space ul de la inceputul string ului
		std::stringstream aux3(token);
		aux3 >> likes;

		getline(stream, token, ',');
		token = token.substr(1);
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
	vector<Movie> lista = create_list("Movies.txt");
	/*
	for (int i = 0; i < lista.size(); i++)
		cout << lista.at(i) << '\n';
	*/
	
//	Repository<vector<Movie>>(lista);
	Repository repo = Repository(lista);
	/*
	Controller ctrl(repo);
	UI ui(ctrl);
	ui.start();
	*/
}

int main()
{	
/*
	string string1 = "";
	string string2 = 0;
	string* string3 = '\0';

	if (!string1) cout << "1 nu e null";
	else cout << "1 e null";
	
	if (!string2) cout << "2 nu e null";
	else cout << "2 e null";
	
	if (!string2) cout << "3 nu e null";
	else cout << "3 e null";
*/
	// vector<Movie> l1 = nullptr;
	start();

	return 0;
}