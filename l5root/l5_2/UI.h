#pragma once
template<typename tip_controller>
class UI
{
private:
	tip_controller controller;

public:
	// doar getter imi trebuie!!
	tip_controller getController();

	//void main_menu()
	//ostream& operator<<main_menu()
	//string main_menu();

	// log_in_mode

	void main_menu();
};