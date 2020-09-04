#pragma once
#include "Header.h"
using namespace std;
class	Kostromin_student
{
public:
	string name;
	string surname;
	unsigned short int age;
	friend ifstream& operator >> (ifstream& in, Kostromin_student& self);
	friend istream& operator >> (istream& in, Kostromin_student& self);
	friend ostream& operator << (ostream& out, Kostromin_student& self);
};

