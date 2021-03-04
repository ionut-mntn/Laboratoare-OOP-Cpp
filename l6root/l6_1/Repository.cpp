#include <iostream> // vad ca merge si fara asta
#include <fstream> // vad ca merge si fara asta
#include <exception>
#include <sstream>

#include "Repository.h"

using std::ios;

using std::cin;
using std::cout;

using std::to_string;
using std::getline;

using std::ifstream;
using std::ofstream;

using std::exception;

Repository::Repository(string database_file, string watchlist_file) : 
list (read_database(database_file)), user_watchlist(read_database(watchlist_file))
{}

vector<Movie>& Repository::getList() { return list; }

vector<Movie>& Repository::getUserWatchlist() { return user_watchlist; }

ifstream Repository::get_input(string file)
{
	ifstream input_stream;
	input_stream.open(file); /* 1) vad ca la `ostream`.open() pot pasa un string;
	2) va arunca oricum exceptie aici daca nu exista fisierul, iar o exceptie netratata
	( uncaught ) va opri executia programului */
							// input_stream.close(); // inchid fisierul dupa ce il deschid ? cred...
	return input_stream;
}

void Repository::parse_line(string line, string& id, string& title, string& genre, int& year, int& likes, string& trailer)
{
	std::stringstream stream; // creez un stream
	stream << line;		// pun in stream linia curent obtinuta

	string token;
	getline(stream, token, ',');
	id = token; // nu am niciun spatiu de eliminat aici

	getline(stream, token, ',');
	token = token.substr(1); // elimin space ul de la inceputul string ului
	title = token;
	getline(stream, token, ',');
	token = token.substr(1); // elimin space ul de la inceputul string ului
	genre = token;

	getline(stream, token, ',');
	token = token.substr(1);	// elimin space ul de la inceputul string ului
	std::stringstream aux2(token);	// convertesc un string
	aux2 >> year;					// la un int 

	getline(stream, token, ',');	// convertesc la int
	token = token.substr(1);	// elimin space ul de la inceputul string ului
	std::stringstream aux3(token);	// convertesc un string
	aux3 >> likes;					// la un int

	getline(stream, token, ',');
	token = token.substr(1);
	trailer = token;
}

vector<Movie> Repository::parse_input(ifstream file)
{
	string id;
	string title;
	string genre;
	int year;
	int likes;
	string trailer;

	vector<Movie> lista;

	string first_line; 
	getline(file, first_line); 
//	cout << "first line: " << first_line << '\n'; /* Citesc prima linie din fisier */
	// cout << "trece22\n";
	string line;	
	while (getline(file, line))
	{
		try
		{
			//cout << "line = " << line << '\n';
			parse_line(line, id, title, genre, year, likes, trailer);
			// cout << "trece55\n";
			lista.push_back(Movie(id, title, genre, int(year), int(likes), trailer));
		}
		catch (exception& e) { cout << e.what() << '\n'; cin.get(); }
	}
//	cout << "treceeeeee\n";
//	file.close();
	
	return lista;
}

vector<Movie> Repository::read_database(string file)
{
	if (file == "") return vector<Movie>();
	return parse_input(get_input(file));
}

void Repository::write_to_file(const string &file, const vector<Movie> &list) const
{
	ofstream os;		
	// os.open(file);/* !ATENTIE! cand deschid fisierul atunci ii precizez ce o sa vreau sa se intample
//	os.open(file, std::trunc);/* !ATENTIE! cand deschid fisierul atunci ii precizez ce o sa vreau sa se intample
	
	// os.open(file, ios::out | ios::trunc);
	os.open(file, ios::trunc);
	/* !ATENTIE! cand deschid fisierul atunci ii precizez ce o sa vreau sa se intample
	cand operez obiectul cu operatorul `<<` sau `>>`*/
	//os.open(file); /* !ATENTIE! cand deschid fisierul atunci ii precizez ce o sa vreau sa se intample
	
	/* vad ca la `ostream`.open() pot pasa un string; arunca exceptie
	oricum daca nu se poate deschide fisierul, de asta nu am tratat cazul acesta ! */
	
	string first_line = "ID, Title, Genre, Year, Likes, Trailer";
	os << first_line;
	os << '\n';
	os << list;
	
	os.close();
}

vector<string> Repository::getIds()
{
	vector<string> aux;
	int l = list.size();
	for (int i = 0; i < l; i++)
		aux.push_back(list[i].getID());
	return aux;
}

/*
vector<Movie> & Repository::get_ref(const int &option)
{	
	switch (option)
	{
	case 1:
		return list;
	case 2:
		return user_watchlist;
	}
}
*/

//////////////////////////////////////////////////////////////////////// de automatizat aici !!
string Repository::get_filename(const vector<Movie> &list) const
{
	if (list == this->list) return "Movies Database.txt";
	return "User Watchlist.txt";
}
//////////////////////////////////////////////////////////////////////// de automatizat aici !!


int Repository::exists(const vector<Movie> &list, const string& id) // database or watchlist
{
	int l = list.size();
	for (int i = 0; i < l; i++)
		if (list.at(i).getID() == id)  return i;

	return -1;
}

void Repository::add(vector<Movie> & list, const Movie &m)
{
	if (exists(list, m.getID()) == -1)
	{
		list.push_back(m);
//		if (list == this->list) write_to_file("Movies.txt", this->list);
		// else write_to_file("")
		write_to_file(get_filename(list), list);
	}
	else
	{
		exception already_exists("The movie already exists in the respective list!");
		throw already_exists;
	}
}

void Repository::del(vector<Movie> &list, const string &id) // cred ca oricum vine prin refereinta
{	
	int poz = exists(list, id); 
	if (poz != -1)
	{
		list.erase(list.begin() + poz);
		write_to_file(get_filename(list), list);
	}
	else
	{
		exception not_here("The movie does not exist in the respective list!");
		throw not_here;
	}
}

void Repository::edit(vector<Movie> & list, const string &id, const Movie& new_movie)
{
	int poz = exists(list, id);
	if (poz != -1)
	{
		list[poz] = new_movie;
		write_to_file(get_filename(list), list);
	}
	else
	{
		exception nu_exista("The movie does not exist in the respective list!");
		throw nu_exista;
	}
}

vector<Movie> Repository::generateUserWatchlist(const string &genre)
{
	if (genre == "") return list; 

	vector<Movie> preference_list;
	int l = list.size();
	for (int i = 0; i < l; i++)
	{
		string token;
		std::stringstream stream;
		stream << list[i].getGenre(); 
		while (getline(stream, token, ' ' ))
		{
			if (token == genre)
			{
				preference_list.push_back(list[i]);
				break;
			}				
		}
	}
	return preference_list;
}

string Repository::toString(const vector<Movie> & list) const
{
	string aux = "";
//	string endline = "\n";

	int l = list.size();
	for (int i = 0; i < l; i++)
	{
		aux = aux + list[i].toString() + '\n'; // asta merge
		// aux = aux + list[i].toString() + to_string('\n'); // asta merge dar afiseaza rau, fara endline-urile care trebuie
		// aux = aux + list[i].toString() + to_string("\n"); // asta nu merge
		// aux = aux + list[i].toString() + "\n"; // asta merge si ea normal
	}
	return aux;
}

ostream& operator<<(ostream& os, const vector<Movie>& list)
{
	int l = list.size();
	for (int i = 0; i < l; i++)
		// os << i + 1 << ". " << list[i] << '\n';
		os << list[i] << '\n';
	
	return os;
}