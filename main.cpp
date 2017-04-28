//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

unsigned long long int fib(int n)
{
	unsigned long long int prevFib = 0;
	unsigned long long int currFib = 1;
	unsigned long long int newFib;
	if(n == 0)
	{
		return 0;
	}
	if(n == 1)
	{
		return 1;
	}
	for (int i = 1; i < n; i++)
	{
		newFib = prevFib + currFib ;
		prevFib = currFib ;
		currFib = newFib ;
	}
	return newFib;
}

int main ()
{
	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 0; i <= 93 ; i ++)
	{
		std :: cout << "f(" << i << ") = " << fib (i) << std :: endl ;
	}
	return 0;
}

//Die 47 Fibonacci-Zahl ist außerhalb des Integer-Werte Bereichs von 32bit.
//Beheben kann man das Problem mit einem long Integer oder noch besser einem long long Integer und einem unsigned dazu, welcher mit 64 bit arbeitet
//Das Programm kann maximal die 93 Fibonacci Zahl ausgeben
