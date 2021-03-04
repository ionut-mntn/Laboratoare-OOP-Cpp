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
		//ifstream s("ERROR");
		//ifstream ("ERROR");
		cout << "eroare la deschiderea fisierului\n";
		//return nullptr; // i dunno
		//return ifstream("error"); // asta vad ca merge !
	}
}

void parse_line(string line, string& id, string& title, string& genre, int& year, int& likes, string& trailer)
{
	std::stringstream stream; // creez un stream
	stream << line;		// pun in stream linia curent obtinuta

	string token;
	getline(stream, token, ',');
	//std::stringstream aux(token);	// convertesc la int
	//aux >> id;
	id = token; // nu am niciun spatiu de eliminat aici

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

}

vector<Movie>parse_input(ifstream file)
{
	string id;
	string title;
	string genre;
	int year; 
	int likes;
	string trailer;

	vector<Movie> lista;

	///char c; // ca sa citesc (dar sa ignor)  virgulele
	// char s; // ca sa citesc (dar sa ignor) spatiile
	string line;
	while (getline(file, line)) // cat timp pot citi in variabila `line` "linii" din fisier
	{ // cred ca pentru getline, spearatorul implicit e '\n', dupa cum o spune si numele
		parse_line(line, id, title, genre, year, likes, trailer);
		lista.push_back(Movie(id, title, genre, int(year), int(likes), trailer));
	}
//	lista.

	// lista.erase(0, 1);
	/*
	for (int i = 0; i < lista.size(); i++)
		cout << lista.at(i);
	cout << '\n'<<'\n';
	lista.erase(lista.begin());
	lista.erase(lista.begin() + 0);
	*/
/*
	for (int i = 0; i < lista.size(); i++)
		cout << lista.at(i);

	cout << '\n';
	lista.at(3) = Movie();
	lista.at(4) = Movie; // vad ca trebui apelat...dar parca era ceva cu treaba
	// asta cu paranteze / fara
	cout << '\n';

	for (int i = 0; i < lista.size(); i++)
		cout << lista.at(i);
*/

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
	// repo.toString();
	
	// vector<Movie> aux = repo.getList();
//	cout << aux[11].getGenre() << '\n';

	
	//cout << "==============================================\n";
	//vector<Movie> aux = repo.generateUserGenreList("Drama");
////////////////////////////////////////////////////////////////////	vector<Movie> aux = repo.generateUserGenreList("Drama");
	//cout << "==============================================\n";
	
/*
	cout << aux.size() << '\n';
	for (int i = 0; i < aux.size(); i++)
		cout << aux[i] << '\n';
*/

	Controller ctrl(repo);
	
	
	//UI ui();
	//UI ui;

	UI ui(ctrl); // nu 
	ui.start();
	// ui();
	//ui.start();
	// ctrl.start(); // nu ! ui ul incepe aplicatia
	/*
	 * In UI fac: input & output !!
	 * In controller apelez metode din repository!!
	 * controller ul reprezinta un simplu intermediar, deoarece task ul de fatza este de o complexitate simpla
	 * voi face in setterevalidarea de date!
	 */
}


/*
! ATENTIE !
1) int* func(); // asta e o functie care returneaza un pointer
la un integer
2) int (*func) (int, string); // asta e un pointer la o functie 
care are return-type `int` (returneaza un intreg)
si are 2 parametri: un int si un string !
*/

int& f()
{
	int y = 5;
	cout << "y=" << y << '\n';
	cout << "&y=" << &y << "(local)\n";
	return y;
}

double& g()
{
	double z = 5;
	cout << "z=" << z << '\n';
	cout << "&z=" << &z << "(local)\n";
	return z;
}

int& func1()
{
	int i = 5;
	cout << "i=" << i << '\n';
	cout << "&i=" << &i << "(local)\n";
	return i;
}

/*
bool not_separator(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'); // there could be more separators
	/* if you know all the characters that could be read from the user, you can do
	think and implement this "similarily reverse"
	
}
*/
int main()
{	
/*
	int x = f();
	cout << "x=" << x << '\n';
	cout << "&x=" << &x << "(in main)\n";

	cout << '\n';
*/
/*
	int a = func1();
	cout << "a=" << a << '\n';
	cout << "&a=" << &a << "(in main)\n";
	cout << typeid(a).name() << '\n';

	cout << '\n';

	int& b = func1();	// isn't this equivalent with `` int* b; *b =  
	// b e un pointer cu dereferentiere automata! deci, NU va retine adresa a ceea ce ii
	// returneaza `func1`, CI ceea ce se gaseste la aceasta adresa, deoarece 
	cout << "b=" << b << '\n';
	cout << "&b=" << &b << "(in main)\n";
	cout << "&(b)=" << &(b) << "(in main)\n";
//	cout << "*(b)=" << *(b) << "(in main)\n";
	cout << typeid(b).name() << '\n';

	cout << '\n';

//	int* c = &func1(); // this does not work because I am trying to assign the address of a function to `c` variable;, which is of type `int *` 
	int* c = &(func1()); // this does not work; but why? Isn't a reference actually a "pointer
// with implicit dereference ?
	cout << "c=" << c << '\n';
	cout << "&c=" << &c << "(in main)\n";
	cout << typeid(c).name() << '\n';
*/
	

/*
	cout << '\n';

	double c = g();
	cout << "c=" << c << '\n';
	cout << "&c=" << &c << "(in main)\n";

	cout << '\n';

	double& d = g();
	cout << "d=" << d << '\n';
	cout << "&d=" << &d << "(in main)\n";

	cout << sizeof(int) << '\n';
*/
	 start();

/*
	const int Nmax = 105;
	char buffer[Nmax];

	int characters = 0;
	int newlines = 0;
	int tabs = 0;
	int spaces = 0;
	int words = 0;

	//	while (cin >> sw >> buffer)
	char prev_char;
	char current_char;
*/
	/*
	cin >> current_char; // read first character

	do
	{
		switch (c) // tread current character 
		{
			case '\n':{ endlines++; break; }
			case '\t':
			case ' ': treat_word(prev_char);
		}
		nr++; // increment number of read characters
/*
		// cout << buffer << '\n';
		// cout << nr << '\n';
		char_nr += strlen(buffer); // this does not include the endline character ('\n')
		//char_nr += 1; // if you want to count both the spaces AND the endline character ('\n') you must also do this
		cout << char_nr << '\n';
//	
		prev_char = current_char;
	} while (cin >> current_char);
	cout << "Number of words:" << nr << '\n';
	cout << "Number of characters:" << char_nr <<'\n';
	*/

	/*
	char c;
	do
	{

	} while (cin >> c);
	*/

	return 0;
}