#include "MedikamentRepo.h"
#include <algorithm>


MedikamentRepo::MedikamentRepo() {
	//undo_redo_list.push_back(lista);	// pun lista vida in istoric
	index_undo_redo = 0; // index ul va fi pana la primul undo
	// mereu egal cu 
}

void MedikamentRepo::showUR()
{
	cout << "===========================================\n";
	cout << '\n';
	cout << " ISTORICUL: " << undo_redo_list.size() << '\n';
	for (int i = 0; i < undo_redo_list.size(); i++)
	{
		cout << "-------------------------------------------\n";
		//		cout << undo_redo_list[i]<< '\n';
		//for (auto i = lista.begin(); i!=lista.end(); i++ )
		for (int j = 0; j < undo_redo_list[i].size(); j++)
			undo_redo_list[i][j].print();
		//cout << (*i);
		cout << "-------------------------------------------\n";
		cout << '\n';
	}
	cout << "===========================================\n";
	cout << '\n';
	cout << "LISTA CURENTA DIN ISTORIC:\n";
	/*
	for (int i = 0; i < index_undo_redo; i++)
	{
		for (int j = i; j < undo_redo_list[i].size(); j++) // nu cred ca era j = i
			undo_redo_list[i][j].print();
	}
	cout << '\n';
	cout << '\n';
	*/
	for(int i = 0; i < lista.size();i++)
		lista[i].print();
	
	cout << "===========================================\n";
	
	cout << "index_undo_redo:"<<index_undo_redo <<'\n';
	cout << '\n';
	
	/*
	// undo_redo_list[i].()
		//for(a:undo_redo_list[i])
	*/
}

void MedikamentRepo::addMedikament(Medikament med) {
/*
	if (undo_redo_list.size() != index_redo_undo)
	{
		undo_redo_list
	}
*/
	lista.push_back(med);

//	cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

	if (index_undo_redo == undo_redo_list.size()) 
	// daca nu s au mai efectuat alte operatii 
	// ( adica daca sunt "actual" cu lista undo_redo("actual" = `lista` coincide cu 
	// `undo_redo_list`
	// intre undo uri si redo uri
	{
		// cout << "       aici" << '\n';
		undo_redo_list.push_back(lista); // intai retin stadiul curent, apoi actualizez
		index_undo_redo++;
	}
	else
	{
		// cout << "       aici2\n";
		//replace a ce e pe pozitia ... cu lista in undo_redo_list
		undo_redo_list.at(index_undo_redo) = lista;
		index_undo_redo++;
	}
	cout << '\n';
}

void MedikamentRepo::deleteMedikament(string n, float konz) {

	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getName() == n && lista.at(i).getKonzentration() == konz) {
			lista.erase(lista.begin() + i);
			break; // sau 'return;' aici
		}
	}

	if (index_undo_redo == undo_redo_list.size())
	{
		undo_redo_list.push_back(lista);
		index_undo_redo++;
	}
	else
	{
		undo_redo_list.at(++index_undo_redo) = lista;
	}
}
/*
void MedikamentRepo::editMedikament()
{

}
*/


bool MedikamentRepo::exists(Medikament med) {

	for (int i = 0; i < lista.size(); i++) 
		if (lista.at(i).getName() == med.getName() && lista.at(i).getKonzentration() == med.getKonzentration()) 
			return true;

	return false;
}


void MedikamentRepo::showMedikament(string str) {

	vector<Medikament> temp;
	auto relatie = [](Medikament a, Medikament b) { return a.getName() < b.getName(); };


	for (int i = 0; i < lista.size(); i++) {
		if (lista.at(i).getName().find(str) != std::string::npos && lista.at(i).getMenge() > 0) {
			temp.push_back(lista.at(i));
		}
	}

	sort(temp.begin(), temp.end(), relatie);
	for (int i = 0; i < temp.size(); i++)
		temp.at(i).print();


}
// de aici in jos am adaugat eu ( John )
void MedikamentRepo::showMedikamentBelow(float limit)
{
	vector<Medikament> temp;
	auto relatie = [](Medikament a, Medikament b) { return a.getName() < b.getName(); };

	for (int i = 0; i < lista.size(); i++) {
		/*
		Medikament* pm = lista[i];
		if(lista.at(i).getPreis() < limit)
			temp.push_back(lista.at(i))
		*/
		if (lista.at(i).getPreis() < limit)
			temp.push_back(lista.at(i));
	}

	sort(temp.begin(), temp.end(), relatie);
	for (int i = 0; i < temp.size(); i++)
		temp.at(i).print();
}

void MedikamentRepo::groupByPriceA()
{
	auto relatie = [](Medikament a, Medikament b) { return a.getPreis() < b.getPreis(); };
	vector<Medikament> temp;

	for (int i = 0; i < lista.size(); i++)			//fac o copie a listei
		temp.push_back(lista.at(i));

	sort(temp.begin(), temp.end(), relatie);		// sortez copia
	for (int i = 0; i < lista.size(); i++)			// afisez copia ascendent
		temp.at(i).print();						
}

void MedikamentRepo::groupByPriceD()
{
	auto relatie = [](Medikament a, Medikament b) { return a.getPreis() > b.getPreis(); };
	vector<Medikament> temp;

	for (int i = 0; i < lista.size(); i++)			//fac o copie a listei
		temp.push_back(lista.at(i));

	sort(temp.begin(), temp.end(), relatie);		// sortez copia
	for (int i = 0; i < lista.size(); i++)			// afisez copia sortata descendent
		temp.at(i).print();
}

void MedikamentRepo::undo()
{
	cout << "index_undo_redo:" << index_undo_redo << '\n';
	if (index_undo_redo<=1) { cout << "!NU ESTE POSIBILA COMANDA UNDO IN ACEST MOMENT!"; } // aici ar trebui aruncata exceptie, de fapt
	else
	{
		for (int i = 0; i < lista.size(); i++)
			lista[i].print();

		index_undo_redo--;
		lista = undo_redo_list[index_undo_redo - 1];
	}
}

void MedikamentRepo::redo()
{
	cout << "index_undo_redo:" << index_undo_redo << '\n';
	if (index_undo_redo == undo_redo_list.size()) {
		cout << "!NU ESTE POSIBILA COMANDA REDO IN ACEST MOMENT!\n"; cout << '\n';
	}
	else
	{
		lista = undo_redo_list[index_undo_redo];
		index_undo_redo++;
	}
}