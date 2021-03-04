#include "Repository.h"

#include<iostream> // vad ca merge si fara asta
#include<fstream> // vad ca merge si fara asta
#include <exception>
#include <sstream>


using std::cin;
using std::cout;
using std::ifstream;
using std::getline;
using std::exception;


Repository::Repository(string database_file, string watchlist_file) : 
list (read_database(database_file)), user_watchlist(read_database(watchlist_file))
{}

vector<Movie>& Repository::getList() // nu apare aici `const` dupa numele metodei
// pentru ca 
{ 
	return list;
}
//vector<Movie>& Repository::getWatchlist() { return user_watchlist; }

vector<Movie>& Repository::getUserWatchlist()
{
	return user_watchlist;
}

ifstream Repository::get_input(string file)
{
	string mat;
	ifstream input_stream;
	input_stream.open(file);
	return input_stream;
}

vector<string> Repository::getIds()
{
	vector<string> aux;
	int l = list.size();
	for (int i = 0; i < l; i++)
		aux.push_back(list[i].getID());
	return aux;
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
	token = token.substr(1); // elivalidate_idmin space ul de la inceputul string ului
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

	string line;
	while (getline(file, line))
	{
		parse_line(line, id, title, genre, year, likes, trailer);
		lista.push_back(Movie(id, title, genre, int(year), int(likes), trailer));
	}

	return lista;
}

vector<Movie> Repository::read_database(string file)
{
	if (file == "") return vector<Movie>();
	return parse_input(get_input(file));
}


// vector<Movie> & Repository::get_ref(const int &option ) // reference to a pointer !!
// vector<Movie>* & Repository::get_ref(const int &option ) // reference to a pointer !!
vector<Movie> & Repository::get_ref(const int &option) // reference to a pointer !!
// cumva: variabila e pasata prin referinta, iar tipul este `int *` (pointer la un int)
{
	// vector<Movie>& dow; // asa nu merge pt ca referinta trebuie initializata; 
	// nu poate fi pasata asa, cum vreau eu; pe cand un pointer poate !!!!
	
//	vector<Movie>* dow; // pointer catre o adresa la care voi stoca o referinta
	switch (option)
	{
	case 1:
		//dow = &list;
		// cout << "returneaza bn aici !!!\n";
		return list;
		//break;
	case 2:
		return user_watchlist;
		//dow = &user_watchlist;
	}
	
	//return *dow; // returnez referinta, nu pointer ul ( dereferentiez pointer ul ) !!
//	return (option == 1 ? list : user_watchlist);
}

// ! initializare = declarare(alocare) + atribuire
int Repository::exists(const vector<Movie> &list, const string& id) // database or watchlist
{
	/* vector<Movie>* ref; /* o referinta e un alias, nu se poate pasa de la o variabila la alta
	in C se putea la un moment dat, parca; ori era vorba de compilator;
	de asta ii dam pointer si nu referinta, pentru ca o referinta trebuie
	initializata la declarare
	*/
	// vector<Movie> & lista = get_ref(option);
	int l = list.size();
	//cout << "len=============" << l <<  '\n';
	//cout << "id==============" << id << '\n';
	for (int i = 0; i < l; i++) // REFERINTELE SUNT ALIAS URI DECI SE APELEAZA CU PUNCT !
	{	// ref->at(i) ? DA !
		//if (ref.at(i).getID() == id)  return i; // sau Movie == Movie
		if (list.at(i).getID() == id)  return i; // sau Movie == Movie
		// `ref` e referinta deci o folosim cu operatorul punct nu cu sageata
	}
	return -1;
}

void Repository::add(const Movie &m, const int & option)
{
	vector<Movie> & list = get_ref(option); // ala e pointer; nu tre sa gandesti prea mult
	// vector<Movie> * list = get_ref(option); // ala e pointer; nu tre sa gandesti prea mult
	// am un obiect de un tip, iar get_ref returneaza un 
	if (exists(list, m.getID()) == -1)  
		list.push_back(m);
	else
	{
		exception already_exists("The movie already exists in the respective list!");
		throw already_exists;
	}
}

void Repository::del(const string &id, const int &option) // cred ca oricum vine prin refereinta
{	
	vector<Movie> & list = get_ref(option);
//	cout << "=================================\n";
	//cout << list << '\n';
	//cout << "=================================\n";
	int poz = exists(list, id); // aici dedesubt e referinta deci se apeleaza cu 
	//cout << "poz = " << poz << '\n';
	// operatorul '.' nu '->'
	if (poz != -1) list.erase(list.begin() + poz);
	else
	{
		exception not_here("The movie does not exist in the respective list!");
		throw not_here;
	}
}


void Repository::edit(const string &id, const Movie& new_movie, const int &option)
{
	vector<Movie>& list = get_ref(option);
	int poz = exists(list, id);
	if (poz != -1) { list.at(poz) == new_movie; }
	else
	{
		exception nu_exista("The movie does not exist in the respective list!");
		throw nu_exista;
	}
}

/*
void Repository::toString(const int &option)
{
	vector<Movie>& list = get_ref(option);
	int l = list.size();
	for (int i = 0; i < l; i++)
		cout << i + 1 << ". " << list[i] << '\n';
	cout << '\n';
}
*/

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

ostream& operator<<(ostream& os, const vector<Movie>& list)
{
	int l = list.size();
	for (int i = 0; i < l; i++)
		os << i + 1 << ". " << list[i] << '\n';
	return os;
}