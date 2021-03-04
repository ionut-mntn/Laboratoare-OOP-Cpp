#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>

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

/*
	Create the layer-architecture of the app.
*/

//!! ce am vrut eu sa fac in repository cu switch(option) si wod unde wod era watchlist sau database 

/*
// const int x = 2;
// const int y = 3;
const int x = 2;
const int y = 3;

int& f(const int& option)
{
	int* p;
	switch (option)
	{
	case 1:
		p = &x;
		break;
	case 2:
		p = &y;
	}
}
*/

void start()
{
	Repository repo("Movies.txt");
	Controller ctrl(repo);
	UI ui(ctrl);

	ui.run(); // run the app
			
	//int aux = get_ref(2);
	// cout << aux;
}

int main()
{	
	start();

	return 0;
}