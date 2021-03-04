#pragma once
#include "Medikament.h"
#include <vector>
using namespace std;
class MedikamentRepo
{


public:
	vector<Medikament> lista;

	/*
		Constructor
	*/
	MedikamentRepo();
	
	/*
		Adauga un medicament in lista de medicamente
		med - medicamentul de adaugat
	*/
	void addMedikament(Medikament med);

	/*
		Sterge un medicament din lista de medicamente
		med - medicamentul de sters
	*/
	void deleteMedikament(string n, float konz);

	/*
		Verifica daca un medicament exista in lista de medicamente(verificarea se face conform cerintei)
		med - medicamentul de cautat
	*/
	bool exists(Medikament med);

	/*
		??
	*/
	void showMedikament(string str);
	// de aici in jos am adaugat eu ( John )
	void showMedikamentBelow(float limit);
	void groupByPriceA();
	void groupByPriceD();
	void undo();
	void redo();

	void showUR();

	vector <vector<Medikament>> undo_redo_list;
	int index_undo_redo;

};

