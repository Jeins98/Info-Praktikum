//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vektor.h"
#include "test.h"
#include "config.h"

#define PI 3.1415927

int main()
{ 
	if (TEST == 1) {
				bool result = run_full_test();
				if (result == true) {
					std::cout << "ALL TESTS PASSED!" << std::endl;
				} else {
					std::cout << "TEST FAILED!" << std::endl;
				}
			}

	double rad = 0, sightlength = 0;

	Vektor earth(0, 6371, 0);
	Vektor person(0, 0.8318, 0);
	Vektor person1 = earth.add(person);
	Vektor sight = earth.sub(person1);
	int zeahler = 0;

	while(sight.scalarProd(earth) >= 0.01 || sight.scalarProd(earth) <= -0.01)
	{
		earth.rotateAroundZ(0.00000001);
		sight = earth.sub(person1);
		rad += 0.00000001;
		zeahler ++;
	}

	sightlength = sight.length();

	std::cout << std::fixed;

	std::cout << "Sie können " << sightlength << " Km weit sehen." << std::endl;
	std::cout << "Sie sind " << std::setprecision(3) << person.getY() * 1000 << " Meter hoch." << std::endl;
	std::cout << "Der Winkel beträgt " << rad * 180 / PI << " Grad." << std::endl;
	std::cout << "Anzhal Steps: " << zeahler << std::endl;

   return 0;

}
