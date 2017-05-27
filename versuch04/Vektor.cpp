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

/**
 * @brief prints the x,y,z value of the vektor
 */
void Vektor::ausgabe() const
{
	std::cout << "Vektor: " << std::endl;
	std::cout << "X: " << this->getX() << std::endl;
	std::cout << "Y: " << this->getY() << std::endl;
	std::cout << "Z: " << this->getZ() << std::endl;

}
/**
 * @brief return x value
 * @return x value of vektor
 */

double Vektor::getX() const
{
	return this->x;
}
/**
 * @brief return y value
 * @return y value of vektor
 */

double Vektor::getY() const
{
	return this->y;
}
/**
 * @brief return z value
 * @return z value of vektor
 */
double Vektor::getZ() const
{
	return this->z;
}
/**
 * @brief calculate the length of the vektor
 * @return length of vektor
 */
double Vektor::length() const
{
	return sqrt(pow(this->getX(),2) + pow(this->getY(),2) + pow(this->getZ(),2));
}

/**
 * @brief calculate the difference between two vektors
 * @return the difference vektor
 * @param input vektor
 */
Vektor Vektor::sub(const Vektor& vector) const
{
	Vektor v(this->getX() - vector.getX(), this->getY() - vector.getY(), this->getZ() - vector.getZ());
	return v;
}
/**
 * @brief calculate the addition between two vektors
 * @return the addititon vektor
 * @param input vektor
 */
Vektor Vektor::add(const Vektor& vector) const
{
	Vektor v(this->getX() + vector.getX(), this->getY() + vector.getY(), this->getZ() + vector.getZ());
	return v;
}
/**
 * @brief check if two vektors are orthogonal
 * @return true if they orthogonal, else return false
 * @param input vektor
 */
bool Vektor::ortho(const Vektor&  vector) const
{
 	if(this->scalarProd(vector) == 0)
 	{
		return true;
	}
	else
	{
		return false;
	}
 //(this->scalarProd(vector) == 0) ? (true) : (false);
}

/**
 * @brief calculate the scalarprodcut between two vektors
 * @return the scalarproduct
 * @param input vektor
 */
double Vektor::scalarProd(const Vektor& vector) const
{
	return (this->getX() * vector.getX() + this->getY() * vector.getY() + this->getZ() * vector.getZ());
}
/**
 * @brief calculate the angle between two vektors
 * @return the angle
 * @param input vektor
 */
double Vektor::angle(const Vektor& vector) const
{
	return acos(this->scalarProd(vector)/this->length()*vector.length());
}
/**
 * @brief turn a vektor around the z-axis
 * @param angle
 */
void Vektor::rotateAroundZ(const double rad)
{
	this->x = (cos(rad) * this->getX() - sin(rad) * this->getY());
	this->y = (sin(rad) * this->getX() + cos(rad) * this->getY());
}


