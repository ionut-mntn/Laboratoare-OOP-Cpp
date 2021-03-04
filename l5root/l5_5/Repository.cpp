#include "Repository.h"

//#include<iostream> // vad ca merge si fara asta
using std::cout;

/*
template<typename container_type>
Repository<container_type>::Repository(container_type lista) : list(lista)
{}
*/

Repository::Repository(vector<Movie> lista = vector<Movie>()): list(lista) // initializer list
{} // parametru default la o lista de tipul `vector<Movie>` goala

vector<Movie> Repository::getList() { return list; } // ar trebui sa returneze poitner ? sau referinta?

vector<Movie> Repository::generateList(string genre="")
{
	if (genre == "")
	{
		// return getList();
		return list;
	}

	vector<Movie> preference_list;
	int l = list.size();
	for (int i = 0; i < l; i++)
		if (list[i].getGenre() == genre)
			preference_list.push_back(list[i]);
	
	return preference_list;
}

void Repository::toString()
{
	string rez = "";
	int l = list.size();
	/*
	for (int i = 0; i < l; i++)
	{
		rez += string(list[i]);
	}
	rez += '\n';
	*/
	//////////////////////////////////////////////////////////////////////////////////////////////////////de trecut in stream aici!!
	for (int i = 0; i < l; i++)
		cout << list[i] << '\n';
	cout << '\n';
	//	return rez;
}
