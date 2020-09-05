#include "Header.h"
#include "Kostromin_group.h"

void Kostromin_group::clear() { this->students.clear(); }

ifstream& operator >> (ifstream& in, Kostromin_group& self)
{
	Kostromin_student tmp;

	self.students.clear();
	while (in >> tmp)
		self.students.push_back(tmp);
	return in;
}

ostream& operator << (ostream& out, Kostromin_group& self)
{
	for (auto it : self.students)
		(&out == &cout) ? out << it << '\n' : out << it;
	return out;
}

void Kostromin_group::add() 
{
	Kostromin_student tmp;
	cin >> tmp;
	this->students.push_back(tmp);
}