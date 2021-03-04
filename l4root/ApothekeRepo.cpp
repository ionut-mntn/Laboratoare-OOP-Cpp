#include <iostream>
#include "ApothekeRepo.h"
#include "Medikation.h"
#include <algorithm>

using namespace std;

ApothekeRepo::ApothekeRepo() 
{
	//konstruktor
}

void ApothekeRepo::hinzufugen(Medikation m)
{
	//hinzufugt ein Medikament
	istoric_undo.push_back(med); //salvez in istoric inainte sa adaug cv nou

	med.push_back(m);
	cout << med.size() << endl;

}

void ApothekeRepo::loschen(string n, int k)
{
	//loscht ein Medikament
	istoric_undo.push_back(med); //salvez in istoric inainte sa adaug cv nou

	for (int i = 0; i < med.size(); i++)
		if (med.at(i).get_Name() == n && med.at(i).get_Konzentration() == k) //unice dupa nume si concentratie
		{
			med.erase(med.begin() + i); //inceputul+offset i
			break;
		}
}

void ApothekeRepo::bearbeiten(string n, int k)
{
	//bearbeitet den Preis
	istoric_undo.push_back(med); //salvez in istoric inainte sa adaug cv nou

	for (int i = 0; i < med.size(); i++)
		if (med.at(i).get_Name() == n && med.at(i).get_Konzentration() == k)
		{
			med.at(i).set_Preis(med.at(i).get_Preis()*2); //dubleaza pretul
		}
}

bool ApothekeRepo::existieren(Medikation m) {

	for (int i = 0; i < med.size(); i++)
		if (med.at(i).get_Name() == m.get_Name() && med.at(i).get_Konzentration() == m.get_Konzentration())
			return true;

	return false;
}

void ApothekeRepo::sortieren_nach_Name()
{
	auto relation = [](Medikation a, Medikation b) { return a.get_Name() < b.get_Name(); };
	sort(med.begin(), med.end(), relation);
}

void ApothekeRepo::suchen_string(Medikation m)
{
	string s;
	cin >> s;
	vector <Medikation> t; //vector temporar

	sortieren_nach_Name();
	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i).get_Name().find(s) != string::npos && med.at(i).get_Menge() > 0)
			t.push_back(med.at(i));
	}

	for (int i = 0; i < t.size(); i++)
		t[i].zeigen();

}

void ApothekeRepo::kleiner_als_menge(int menge)
{
	for (int i = 0; i < med.size(); i++)
	{
		if (med.at(i).get_Menge() < menge)
			med.at(i).zeigen();
	}
}

void ApothekeRepo::sortieren_nach_Preis()
{
	auto relation = [](Medikation a, Medikation b) { return a.get_Preis() < b.get_Preis(); };
	sort(med.begin(), med.end(), relation);

	for (int i = 0; i < med.size(); i++)
		med.at(i).zeigen();

}

void ApothekeRepo::undo() //nu face redo ul poate va prindeti voi cum ar trebui scris
{
	if (istoric_undo.size() != 0)
	{
		istoric_redo.push_back(med);
		med = istoric_undo.at(istoric_undo.size() - 1);
		istoric_undo.erase(istoric_undo.begin() + istoric_undo.size() - 1);
		//cout << "undo"<<" "<<endl;
	}
	else
		cout << " Nu este posibil! " << endl;
}

void ApothekeRepo::redo() //nu face redo ul poate va prindeti voi cum ar trebui scris
{
 if (istoric_redo.size() != 0)
	{
	    istoric_undo.push_back(med);
		med = istoric_redo.at(istoric_redo.size() - 1);
		istoric_redo.erase(istoric_redo.begin() + istoric_redo.size() - 1);
		//cout << "redo" <<" "<<endl;
	}
	else
		cout << " Nu este posibil! " << endl;
}




