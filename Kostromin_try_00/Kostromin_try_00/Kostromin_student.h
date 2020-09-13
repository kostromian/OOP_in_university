#pragma once
#include "Header.h"
using namespace std;

class	Kostromin_student
{
public:
	string name;
	string surname;
	unsigned short int age;

	void	cons_os();
	void	file_os(ofstream& out);
	void	cons_is();
	void	file_is(istream& is);
	friend istream& operator >> (istream& in, Kostromin_student& self);
	friend ostream& operator << (ostream& out, Kostromin_student& self);
};

