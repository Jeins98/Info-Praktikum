//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#include <cmath>
#include <iostream>


Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}


void Vektor::ausgabe() const
{
	std::cout << "Vektor: " << std::endl;
	std::cout << "X: " << this->getX() << std::endl;
	std::cout << "Y: " << this->getY() << std::endl;
	std::cout << "Z: " << this->getZ() << std::endl;

}

double Vektor::getX() const
{
	return this->x;
}

double Vektor::getY() const
{
	return this->y;
}

double Vektor::getZ() const
{
	return this->z;
}

double Vektor::length() const
{
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2) + pow(this->getZ(),2));
}

Vektor Vektor::sub(const Vektor& vector) const
{
	Vektor v(this->getX() - vector.getX(), this->getY() - vector.getY(), this->getZ() - vector.getZ());
	return v;
}

Vektor Vektor::add(const Vektor& vector) const
{
	Vektor v(this->getX() + vector.getX(), this->getY() + vector.getY(), this->getZ() + vector.getZ());
	return v;
}

bool Vektor::ortho(const Vektor&  vector) const
{

 	if(this->scalarProd(vector) == 0){
		return true;
	}
	else
	{
		return false;


	}
 //(this->scalarProd(vector) == 0) ? (true) : (false);
}

double Vektor::scalarProd(const Vektor& vector) const
{
	return (this->getX() * vector.getX() + this->getY() * vector.getY() + this->getZ() * vector.getZ());
}

double Vektor::angle(const Vektor& vector) const
{
	return acos(this->scalarProd(vector)/this->length()*vector.length());
}

void Vektor::rotateAroundZ(const double rad)
{
	this->x = (cos(rad) * this->getX() - sin(rad) * this->getY());
	this->y = (sin(rad) * this->getX() + cos(rad) * this->getY());
}


