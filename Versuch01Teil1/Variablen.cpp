//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

void aufgabe1_3();
void aufgabe4_6_7(); //Methoden werden initalisiert
void aufgabe5();


int main()
{
	aufgabe4_6_7(); //Methode wird aufgerufen

	return 0;
}

void aufgabe1_3(){ //Methode wird deklariert


	int iErste, iZweite, iSumme, iQoutient;
	double dQoutient, dSumme, dSummeCast, dQoutientCast;//Initalisieurng der Variablen

	std::cout << "Erste Zahl: ";
	std::cin >> iErste;				//Erste Zahl wird eingelesen
	std::cout << "Zweite Zahl: ";
	std::cin >> iZweite;			//Zweite Zahl wird eingelesen

	iSumme = iErste + iZweite;
	dSumme = iErste + iZweite;
	//Summe wird berechnet


	iQoutient = iErste / iZweite;
	dQoutient = iErste / iZweite;
	//Qoutient wird berechnet

	std::cout << "Die Summe ist: " << iSumme << "\n" << "Der Qoutient ist: " << iQoutient << std::endl; //Ausgabe beider Werte
	std::cout << "Die Summe ist: " << dSumme <<"\n" << "Der Qoutient ist: " << dQoutient << std::endl;


	dSummeCast = (double) iErste + (double) iZweite;		//TypeCast
	dQoutientCast = (double) iErste / (double) iZweite;

	std::cout << "Die Summe ist: " << dSummeCast <<"\n" << "Der Qoutient ist: " << dQoutientCast << std::endl; //Ausgabe TypeCast
}

void aufgabe4_6_7(){

	std::string sVorname, sNachname, sVornameName, sNameVorname; //String wird initalisiert

	std::cout << "Vorname: ";
	std::cin >> sVorname;
	std::cout << "Nachname: ";  //Strings werden deklariert
	std::cin >> sNachname;

	sVornameName = sVorname + " " + sNachname;   //Strings werden addiert
	sNameVorname = sNachname + ", " + sVorname;

	std::cout << "Vorname Nachname: " << sVornameName << "\n" << "Nachname, Vorname: " << sNameVorname << std::endl; //Strings werden ausgegeben


	int iName1 = (int) sVorname[0];  //TypeCast auf int (Also ASCII-Code)
	int iName2 = (int) sVorname[1];

	std::cout <<"Erster Buchstabe in ASCII: " <<  iName1 << ", " << "Zweiter Buchstabe in ASCII: " << iName2 << std::endl;  //ASCII-Zahl wird ausgegben


	if (iName1 >= 97){
		iName1 -= 96;
	}else{                 		//Abfrage Buchstabe im Alphabet
		iName1 -= 64;
	}

	if (iName2 >= 97){
			iName2 -= 96;		//Abfrage Buchstabe im Alphabet
	}else{
			iName2 -= 64;
		}

	std::cout <<"Erster Buchstabe im Alphabet: " <<  iName1 << ", " << "Zweiter Buchstabe im Alphabet: " << iName2 << std::endl;  //Zahl des Buchstaben wird ausgegeben


}

void aufgabe5(){

	{//Block-Anfang

  int iFeld[2] = {1,2};

  //Mit iFeld[index] können die Werte in einem Array aufgerufen werden. Entweder Index = 1 oder 2, da nicht mehr Felder im Array vorhanden sind

  int spielfeld[2][3] = {{1,2,3},
  	 	 	 	 	 	 {4,5,6} };

  //Mit spielfeld[i][j] kann auf das Array zugegriffen werden

  for (int i = 0;  i < 2; ++ i) {          //for-Schleife um eindimensionales Array auszugeben
	std::cout << iFeld[i];
}
  std::cout << "\n";

  for (int i = 0; i < 2; ++i) {     //Zwei for-SChleifen für zweidimensionale Arrays, um alle Werte des Array auszugeben
	for (int j = 0; j < 3; ++j) {
		std::cout << spielfeld[i][j];
	}
}


  const int iZweite = 1;


  std::cout << "\n";
  std::cout <<"Constante Variable: " << iZweite << std::endl;

	}//Block-Ende

	//Auf Konstante iZweite kann nach Block-Ende nicht mehr zugegriffen werden und somit kann sie auch nicht ausgegeben werden

}




