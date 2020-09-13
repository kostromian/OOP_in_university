#pragma once
#include "Header.h"
#include "Kostromin_student.h"
using namespace std;

class Kostromin_group : public CObject
{
public:
	list<Kostromin_student *>	students;
	CString					name;
	DECLARE_SERIAL(Kostromin_group);
	void	cons_os();
	void	file_os(ofstream& out);
	void	file_is(ifstream& is);
	friend ifstream& operator >> (ifstream& in, Kostromin_group& self);
	friend ostream& operator << (ostream& out, Kostromin_group& self);
	void clear();
	void add();
	virtual void Serialize(CArchive& archive);
	~Kostromin_group();
};
