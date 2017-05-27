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

#define PI 3.1415927  //define number pi as constant

/**
 * brief main_methode start test_class and the programm
 */
int main()
{ 
	if (TEST == 1) //start test_cölass
	{
				bool result = run_full_test();
				if (result == true)
				{
					std::cout << "ALL TESTS PASSED!" << std::endl;
				}
				else
				{
					std::cout << "TEST FAILED!" << std::endl;
				}
			}

	double rad = 0, sightlength = 0, personvektory = 0;
	int zeahler = 0;

	//get the hight of the human
	std::cout << "Wie hoch sind Sie (in m)?" << std::endl;
	std::cin >> personvektory;

	Vektor earth(0, 6371, 0); //set the earth vektor
	Vektor person(0, personvektory / 1000, 0); //set the person vektor
	Vektor person1 = earth.add(person); //set the complete length
	Vektor sight = earth.sub(person1); //set the high of the person

	//while slacrproduct of sight/earth is bigger than 0.01 or less -0.01

	while(sight.scalarProd(earth) >= 0.01 || sight.scalarProd(earth) <= -0.01)
	{
		earth.rotateAroundZ(0.00000001); //rotate the vector around 0.00000001 degrees
		sight = earth.sub(person1);		//set the new sight
		rad += 0.00000001;
		zeahler ++;
	}

	sightlength = sight.length();  //get the length of sight. Is the length how far you can see

	std::cout << std::fixed;

	//print out everything
	std::cout << "Sie können " << sightlength << " Km weit sehen." << std::endl;
	std::cout << "Sie sind " << std::setprecision(3) << person.getY() * 1000 << " Meter hoch." << std::endl;
	std::cout << "Der Winkel beträgt " << std::setprecision(5) << rad * 180 / PI << " Grad." << std::endl;
	std::cout << "Anzhal Steps: " << zeahler << std::endl;

   return 0;

}
