#include <iostream>
#include <exception>
#include <windows.h>

#include "UI.h"

using std::cin;
using std::cout;
using std::cerr;
using std::exception;

UI::UI(Controller c)
{
	contr = c;
}

Controller& UI::getController()
{
	return contr;
}


void UI::ask_get(string mesaj, int &value)
{
	cout << '\n';
	cout << mesaj << ": ";
	cin >> value; cin.get();  // citesc caracterul '\n' ramas in buffer
}

void UI::ask_get(string mesaj, char& value)
{
	cout << '\n';
	cout << mesaj << ": ";
	cin >> value; cin.get(); // citesc caracterul '\n' ramas in buffer
}

void UI::ask_get(string mesaj, string& value)
{
	cout << '\n';
	cout << mesaj << ": "; getline(cin, value);
}

void UI::wrong_option_screen()
{
	cout << "Please enter one of the numbers corresponding to the options!!\n";
}

void generic_error_msg(exception& e)
{
	cerr << "===EROARE===\n";	// cerr scrie intr un stream separat de cout; in cazul nostru, coincide stream urile, tho
	cerr << e.what() << '\n';
	cerr << "===============\n";
	cout << '\n';
}

/*
void UI::main_menu(int &mode, vector<Movie> &own_list)
{
	switch (mode)
	{
	case 1: 
		admin_menu_screen();
		break;

	case 2:
		//user_menu_screen(own_list);
		break;

	default:
		exception e;
		throw e;
	}
}
*/

void UI::select_mode_screen()
{
	cout << "Select mode:\n"
		<< "1.Administrator\n"
		<< "2.User\n"
		<< "0.Exit\n";
}

void UI::run()
{
	int mode;
	//select_mode_screen();
	//ask_get("mode", mode);
	vector<Movie> user_watchlist;
	
	/*
	while (true)
	{
		try
		{
			main_menu(mode, user_watchlist);
		}
		catch (exception &e) // 
		{
			cout << "de aici e problema!!!!\n";
			//wrong_input_msg();
			wrong_input_screen();
			ask_get("mode", mode);
		}
	}
	*/
	int option;
	while (true)
	{
		select_mode_screen();
		ask_get("mode", mode);
		switch (mode)
		{
			case 1:
			{
				admin_menu_screen();
				execute_amo();
				break;
			}
			case 2:
			{
				// execute_umo(option, user_watchlist);
				user_menu_screen();
				execute_umo(user_watchlist);
				break;
			}
			case 0:
			{
				cout << "Exiting...\n See you soon!";
				return;
			}
			default: { wrong_option_screen(); break; }
		}
	}
	
	
	// void (*screen)();
//	while (true)
	/*
	do
	{
		ask_get("mode", mode);
		switch (mode)
		{
				/*
				case 1:
				{
					admin_menu_screen();

					int option;
					ask_get("option", option);
					try
					{
						execute_amm(option); // de vazut de facut cu asta duplicata in user_mm()
					}
					catch (exception& e)
					{
						run();
					}

					break;
				}
				case 2:
				{
					user_menu_screen(user_list);
					try
					{

					}
					execute_umm
					{

					}
					break;
				}
				case 0:
				{
					cout << "Exiting...\n";
					// system("pause");
					return;
				}
				default:
				{
					wrong_input_msg();
					ask_get("mode", mode);
				}
				*/
			/*
			case 1:
			{
				screen = &admin_menu_screen;
				break;
			}
			case 2:
			{
				screen = &user_menu_screen;
				break;
			}
			case 0:
			{
				cout << "Exiting...\n";
				return;
			}
			default:
				screen = &wrong_input_screen;
		}
		screen();
	} while (screen != &wrong_input_screen);

	int option;
	ask_get("option", option);
	*/
}



void UI::ask_get_ma(string &id, string &title, string &genre, int &year, int &likes, string &trailer)
{
	ask_get("id", id);
	ask_get("title", title);
	ask_get("genre", genre);
	ask_get("year", year);
	ask_get("likes", year);
	// cin.get(); // citesc caracterul '\n' ramas in buffer de la citirea variabilei likes
	ask_get("trailer", trailer);

	/*
	cout << " id = ";	 getline(cin, id);
	cout << " title = ";  getline(cin, title); // Atentie!! a nu se citi titluri ce contin virgule
	cout << " genre = "; getline(cin, genre); //cin.getline(genre); // de data aceasta voi folosi getline
	cout << " year = "; cin >> year;
	cout << " likes = "; cin >> likes;
	cout << " trailer = "; cin.get(); // citesc caracterul '\n' ramas in buffer de la citirea de mai sus in variabila `likes` ( as fi putut folosi tot getline, tho )
	getline(cin, trailer);
	*/
}

void UI::invalid_screen(string token, const int &low_boundary, const int &high_boundary)
{
	cout << "Invalid value!\n"
		<< token.c_str() << " must be between: " << low_boundary
		<< " and " << high_boundary;
}

void UI::validation_screen(int &year, int &likes)
{
	cout << "Checking integrity of data...\n";
	while (!validator.validate_likes(year))
	{
		invalid_screen("year", validator.lowest_year, validator.highest_year);
		ask_get("year", year);
	}
	while (!validator.validate_likes(likes))
	{
		invalid_screen("likes", validator.lowest_likes, validator.highest_likes);
		ask_get("likes", likes);
	}
	cout << "Finished. Data has valid values! :D\n";
}

void UI::execute_amo()
{
	string id, title, genre, trailer;
	int year, likes;
	int option;
	while (true)
	{
//		admin_menu_screen();
		ask_get("option", option);
		switch (option)
		{
			case 1:
			{
				// cin.get(); // read trailing '\n' character left in buffer
				ask_get_ma(id, title, genre, year, likes, trailer);
				validation_screen(year, likes );
				try { contr.getRepo().add(Movie(id, title, genre, year, likes, trailer)); }
				catch (exception& e)
				{
					generic_error_msg(e);
					admin_menu_screen();
				}
				break;
			}
			case 2:
			{
				string old_id;
				//cout << "id (of movie to be updated) = "; 
				//cin >> old_id;
				ask_get("id (of movie to be replaced):", id);
				ask_get_ma(id, title, genre, year, likes, trailer);
				try
				{
					contr.getRepo().edit(old_id, Movie(id, title, genre, year, likes, trailer));
				}
				catch (exception& e)
				{
					generic_error_msg(e);
				}
				break;
			}
			case 3:
			{
				string old_id;
				cout << "id (of movie to be deleted) = ";  cin >> old_id;
				try
				{
					contr.getRepo().del(old_id);
					// daca trece de partea asta; nvm...

				}
				catch (exception& e)
				{
					generic_error_msg(e);
				}
				break;
			}
			case 4:
			{
				contr.getRepo().toString();
				break;
			}
			case 0:
			{
				/*
				cout << "intra\n";
				exception leave;
				throw leave;
				break;
				//			main_menu();
				*/
				go_back_screen();
				return;
			}
			default:
			{
				cout << "nu mai intra2\n";
				wrong_option_screen();
				//break ;
			}
		}
	}
}

	
// void UI::afis_lista(const vector<Movie>& aux)
void UI::afis_lista(vector<Movie>& aux)
{
	int l = aux.size();
	for (int i = 0; i < l; i++)
		cout << aux[i] << '\n';
	cout << '\n';
}

void one_by_one(vector<Movie> aux, vector<Movie> &watchlist)
{
	int i = 0;
	char yne; // yes / no / exit 
	string mesaj = "\"y\" = yes  \"n \" = no \"e\" = exit";
	int l = aux.size();
	while (i < l)
	{
		cout << aux[i] << '\n';
		cout << "---Check trailer open in Internet browser!---\n";
		string aux1 = '"' + aux[i].getTrailer() + '"';
		cout << aux1 << '\n';
		ShellExecute(NULL, "open",
			aux1.c_str(),	// convertesc la `const char*` (wlstr)
			NULL, NULL, SW_SHOWNORMAL);

		cout << (" Do you like it? Would you like to add it to your watch list ?\n");
		cout << mesaj << '\n';
		cin >> yne;
		
		switch(yne)
		{
		case 'y':
		{
			watchlist.push_back(aux[i]); 
			break;
		}

		case 'n':
			break;
		case 'e':
			return ;
		}
		i++;
	}
}

// void UI::execute_umo(int option, vector<Movie>& own_list)
//void UI::execute_umo(vector<Movie>& own_list)
void UI::execute_umo(vector<Movie>& own_list)
{
	int option;
	while (true)
	{
		user_menu_screen();
		ask_get("option", option);
		switch (option)
		{
			case 1:
			{

				string genre;
				ask_get("genre", genre);
				vector<Movie> aux = contr.getRepo().generateUserGenreList(genre);

				int l = aux.size();
				one_by_one(aux, own_list);
				cout << "Your current watchlist is:\n";
				afis_lista(own_list);
				break;
			}
			case 2:
			{
				string id;
				if (!own_list.size()) { cout << "You have not added any movie to your watchlist yet!\n"; return; }

				ask_get("id", id);
				try
				{
					contr.getRepo().del(id);

					char c;
					ask_get("option", c);
					switch (c)
					{
					case 'y':
					{
						int poz = contr.getRepo().exists(id);
						vector<Movie> aux = contr.getRepo().getList(); // asta e chiar baza mea de date, pentru ca metoda returneaza referinta ! nu e o copie!
						int nr_likes = aux.at(poz).getLikes();
						aux.at(poz).setLikes(++nr_likes);
					}
					case 'n': break;
					}
				}
				catch (exception& e)
				{
					cerr << e.what();
					cout << "(Maybe check id ?)\n";
				}
				break;
			}
			case 3:
			{
				if (!own_list.size()) { cout << "You have not chosen any movie yet!\n"; break; }
				afis_lista(own_list);
				break;
			}
			case 0:
			{
			//	cout << "intra2\n";
				//exception leave;
				//throw leave;
				//break;
				go_back_screen();
				return;
			}
			default:
			{
				cout << "nu mai intra2\n";
				wrong_option_screen();
				break;
			}
		}
	}
}

void UI::admin_menu_screen()
{
	cout << "===ADMIN MAIN MENU===\n";
	cout << "0. Go back\n"
		<< "1. Add movie\n"
		<< "2. Update Movie\n"
		<< "3. Delete movie\n"
		<< "4. Display movies\n\n";
	
	/*
	int option;
	ask_get("option", option);
	try
	{
		execute_amo(option); // de vazut de facut cu asta duplicata in user_mm()
	}
	catch(exception &e)
	{
		run();
	}
	*/
}

//void UI::user_menu_screen(vector<Movie> &own_list)
void UI::user_menu_screen()
{
	cout << "===USER MAIN MENU===\n"
		<< "0. Go back\n"
		<< "1. View movies by specified genre(leave blank to view all movie trailers)\n"
		<< "2. Delete movie from own watchlist\n"
		<< "3. Display own list\n";
	cout << '\n';

	/*
	int option;
	ask_get("option", option);
	execute_umo(option, own_list);
	*/
}

void UI::go_back_screen()
{
	cout << "Going back...\n";
	cout << '\n';
}