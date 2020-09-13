#include "Header.h"
#include "Kostromin_group.h"

void Kostromin_group::Serialize(CArchive& archive)
{
	// call base class function first
	// base class is CObject in this case
	CObject::Serialize(archive);

	// now do the stuff for our specific class
	if (archive.IsStoring())
		archive << name;
	else
		archive >> name;
}

void Kostromin_group::clear() 
{
	for (auto it : students)
		delete it;
	this->students.clear(); 
}

Kostromin_group::~Kostromin_group() { clear(); }

void    Kostromin_group::cons_os()
{
	for(auto it : students)	
	{
		it->cons_os();
		cout << '\n';
	}
}

void    Kostromin_group::file_os(ofstream &os)
{
	for (auto it : students)
		it->file_os(os);
}

void	Kostromin_group::file_is(ifstream& is)
{
	clear();
	while (is)
	{
		Kostromin_student* tmp = new Kostromin_student;
		tmp->file_is(is);
		students.push_back(tmp);
	}
	delete students.back();
	students.pop_back();
}

ifstream& operator >> (ifstream& in, Kostromin_group& self)
{
	self.file_is(in);

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
	Kostromin_student* tmp = new Kostromin_student;
	tmp->cons_is();
	this->students.push_back(tmp);
}