#pragma once
#include "Controller.h"
#include "Validator.h"
class UI
{
private:
	
	Controller contr;

	Validator validator;

	void afis_lista(vector<Movie>&);

	/* aici am incercat ceva cu template dar ar fi trebuit sa folosim ceva numit ""
		ca sa pastram abstractizarea "header-cpp" si era ceva cam complicat, asa ca
		am ramas la overloaded functions
	*/
	void ask_get(string mesaj, int& var);
	void ask_get(string mesaj, string& var);
	void ask_get(string mesaj, char &c);

	void ask_get_ma(string& id, string& title, string& genre, int& year, int& likes, string& trailer);

	void wrong_option_screen();
	
	void validation_screen(int&, int &);
	void invalid_screen(string, const int &, const int&);

	void main_menu(int&, vector<Movie>&);
	void select_mode_screen();
	void admin_menu_screen(); // admin main menu
	//void user_menu_screen(vector<Movie>&); // user main menu
	void user_menu_screen(); // user main menu
	void go_back_screen();

	//void execute_amo(int option); // execute admin menu option
	void execute_amo(); // execute admin menu option
	//void execute_umo(int option, vector<Movie>& own_list); // execute user menu option
	void execute_umo(vector<Movie>& own_list); // execute user menu option
	//void execute_umo(); // execute user menu option

public:
	UI(Controller c = Controller() );

	//getter controller
	Controller& getController();

	void run();
};
