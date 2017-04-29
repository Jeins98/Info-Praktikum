/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	struct Person{
		std::string sNachname;
		std::string sVorname;  //Struct wird angelegt und Variabeln werden deklariert
		int iGeburtsjahr;
		int iAlter;
	};

	struct Person nBenutzer;

	cout << "Geben Sie ihren Vornamen ein: " << endl;   //Daten werden eingelesen und die Variabeln initalisiert
	cin >> nBenutzer.sVorname;
	cout << "Geben Sie ihren Nachnamen ein: " << endl;
	cin >> nBenutzer.sNachname;
	cout << "Geben Sie ihr Geburtsjahr ein: " << endl;
	cin >> nBenutzer.iGeburtsjahr;
	cout << "Geben Sie ihr Alter ein: " << endl;
	cin >> nBenutzer.iAlter;

	cout << "Name: " << nBenutzer.sVorname << " " << nBenutzer.sNachname   //Struct wird ausgegeben
			<< "\n" << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << "\n"
			<< "Alter: " << nBenutzer.iAlter << endl;



	Person nKopieGesamt = nBenutzer;  //Komplettes Struct wird kopiert

	Person nKopieEinzeln;       					//Struct wird einzeln kopiert
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	cout << "Benutzer Kopie Gesamt: " << endl;									//Komplett kopiertes Struct wird ausgegeben

	cout << "Name: " << nKopieGesamt.sVorname << " " << nKopieGesamt.sNachname
				<< "\n" << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << "\n"
				<< "Alter: " << nKopieGesamt.iAlter << endl;

	cout << "Benutzer Kopie Einzeln: " << endl;									//Einzeln kopiertes Struct wird ausgegeben

	cout << "Name: " << nKopieEinzeln.sVorname << " " << nKopieEinzeln.sNachname
					<< "\n" << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << "\n"
					<< "Alter: " << nKopieEinzeln.iAlter << endl;



	return 0;
	
}
