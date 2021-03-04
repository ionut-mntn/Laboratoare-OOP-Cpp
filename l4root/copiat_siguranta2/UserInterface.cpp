#include "UserInterface.h"
#include <iostream>

using namespace std;
UserInterface::UserInterface()
{
	
}

void UserInterface::start() {
	//aici se face meniul din consola
	Controller c;
	MedikamentRepo lista;

	/*
	vector<int> vi = { 1,2,3 };
	vector<vector<int>> vvi = { { 1,2,3 },{4,5,6},{7,8,9} };

	vi = vvi[1];
	*/

	// vvi

	
	lista.addMedikament(Medikament("1", 1, 1, 1));
	lista.addMedikament(Medikament("2", 2, 2, 2));
	lista.addMedikament(Medikament("3", 3, 3, 3));
	
	//for (int i = 0; i < lista.lista.size(); i++)
		//lista.lista[i].print();

	//MedikamentRepo lista_aux = lista.lista[0];

	/*
	MedikamentRepo lista_aux = lista[0];
	for (int i = 0; i < lista.size(); i++)
		lista[i].print();
	lista_aux = lista[1];
	for (int i = 0; i < lista.size(); i++)
		lista[i].print();
	lista_aux = lista[2];
	for (int i = 0; i < lista.size(); i++)
		lista[i].print();
	*/

	int optiune;
	while (true)
	{
		cout << "Meniu Principal" << endl;
		cout << "0. UR list" << endl;
		cout << "1. Adauga Medicament" << endl;
		cout << "2. Sterge Medicament" << endl;
		cout << "3. Editeaza Medicament" << endl;
		cout << "4. Vizualizeaza Medicamente" << endl;
		// de aici am adaugat eu ( John )
		cout << "5. Vizualizeaza Medicamente sub un anumit pret:" << endl;
		cout << "6. Vizualizeaza Medicamente grupate dupa pret:" << endl;
		cout << "7. Undo" << endl;
		cout << "8. Redo" << endl;
		//pana aici
		cout << "0. Exit" << endl;
		cout << "Introdu Operatiunea: "; 
		
		/*	// doar daca o sa fie timp
		auto optiune;
		c.preia_optiune(&optiune);
		*/
		cin >> optiune; cout << endl;
		// si asta

		/* // doar daca o sa fie timp
		case 0:
			cout << "Exiting\n";
			break;
		case 1:
			cout << "-Add Medikament-\n";
			cout << " Name: Konzentration: Menge: Preis: (type in them in, pressing enter or space after each)";
		*/

		if (optiune == 6)
		{
			cout << "9.ascendent\n";
			cout << "10.descendent\n";
			cout << "Introdu Operatiunea: "; cin >> optiune; cout << endl;

		}
		// pana aici
		if (0 <= optiune && optiune <= 10)
			c.executa(optiune, &lista);
		else cout << "Nu s-a introdus o optiune valida!\n"
			<<"Va rugam sa introduceti optiune valida!\n";

	}
	

}