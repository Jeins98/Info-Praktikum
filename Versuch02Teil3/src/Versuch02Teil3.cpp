//============================================================================
// Name        : Versuch02Teil3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char getGeheim(char cZeichen, char lookUp[2][26]) {

	int iPos = cZeichen - 65;

	return lookUp[1][iPos];
}

char getKlar(char cZeichen, char lookUpTab1[2][26]) {
	int i = 0;
	while (cZeichen != lookUpTab1[1][i])
		i++;
	return lookUpTab1[0][i];
}

int main(void) {

	string sWort;
	string sVerschluesselt;
	string sEntschluesselt;

	char lookUpTab1[2][26] = { { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
			'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
			'W', 'X', 'Y', 'Z' }, { 'B', 'D', 'E', 'H', 'K', 'L', 'O', 'R', 'T',
			'Y', 'X', 'C', 'V', 'W', 'S', 'G', 'I', 'F', 'A', 'J', 'N', 'U',
			'Z', 'Q', 'M', 'P' } };

	cout << "Geben Sie ein Wort ein" << endl;
	cin >> sWort;

	for (int i = 0; i < sWort.length(); ++i) {
		sVerschluesselt += getGeheim(sWort[i], lookUpTab1);
	}

	cout << "Klartext: " << sWort << endl;
	cout << "Verschlüsselt: " << sVerschluesselt << endl;



	cout << "\n" << "Geben Sie ein verschlüsseltes Wort ein" << endl;
	cin >> sWort;

	for (int i = 0; i < sWort.length(); ++i) {
		sEntschluesselt += getKlar(sWort[i], lookUpTab1);
	}

	cout << "Verschlüsselt: " << sWort << endl;
	cout << "Entschlüsselt: " << sEntschluesselt << endl;

	return 0;
}
