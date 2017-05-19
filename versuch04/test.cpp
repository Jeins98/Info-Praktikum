/*
 * test.cpp
 *
 *  Created on: 19.05.2017
 *      Author: Jonas
 */

#include <iostream>
#include "Vektor.h"
#include "test.h"

bool test_add()
{
	std::cout << "Running test for 'vektor_add'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	Vektor v1(1,2,3);
	Vektor v2(1,2,3);
	Vektor vresult(2,4,6);
	Vektor v1result = v1.add(v2);

	double x = 0, y = 0, z = 0;
	x = v1result.getX();
	y = v1result.getY();
	z = v1result.getZ();

if(x == vresult.getX() && y == vresult.getY() && z == vresult.getZ()){
	return true;
}
else
{
	return false;
}

}

bool test_sub()
{
	std::cout << "Running test for 'vektor_sub'..." << std::endl;
	std::cout << "----------------------------" << std::endl;
	Vektor v1(3,3,4);
	Vektor v2(2,2,3);
	Vektor vresult(1,1,1);
	Vektor v1result = v1.sub(v2);

	double x = 0, y = 0, z = 0;
	x = v1result.getX();
	y = v1result.getY();
	z = v1result.getZ();

if(x == vresult.getX() && y == vresult.getY() && z == vresult.getZ()){
	return true;
}
else
{
	return false;
}

}

bool test_rotate_z()
{

		std::cout << "Running test for 'vektor_rotate_z'..." << std::endl;
		std::cout << "----------------------------" << std::endl;
		Vektor v1(0, 6317, 0);
		Vektor vresult(-0.000064,6371,0);
		v1.rotateAroundZ(0.00000001);

		double x = 0, y = 0, z = 0;
		x = v1.getX();
		y = v1.getY();
		z = v1.getZ();

	if(x == vresult.getX() && y == vresult.getY() && z == vresult.getZ()){
		return true;
	}
	else
	{
		return false;
	}
}

bool run_full_test (void)
{
	bool result = true;

	test_add();
	test_sub();
	test_rotate_z();


	return result;

}



