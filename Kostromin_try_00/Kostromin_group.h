#pragma once
#include "Header.h"
#include "Kostromin_student.h"
using namespace std;

class Kostromin_group
{
public:
	list<Kostromin_student>	students;
	friend ifstream& operator >> (ifstream& in, Kostromin_group& self);
	friend ostream& operator << (ostream& out, Kostromin_group& self);
	void clear();
	void add();
};

