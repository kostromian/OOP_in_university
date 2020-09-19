#include "Kostromin_starosta.h"

IMPLEMENT_SERIAL(Kostromin_starosta, Kostromin_student, 1)

Kostromin_starosta::Kostromin_starosta()
{
	part_time = 0;
}

//сериализация через mfc(необходимо подключить mfc к проекту)
void    Kostromin_starosta::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
		ar << mid_name << part_time << name << surname << age;
	else
		ar >> mid_name >> part_time >> name >> surname >> age;
}

void Kostromin_starosta :: cons_os()
{
	Kostromin_student::cons_os();
	cout << "Middle name of student: " << mid_name << endl;
	cout << "Participation time in pairs: " << part_time << endl;
}

void Kostromin_starosta::cons_is()
{
	string tmp;
	Kostromin_student::cons_is();
	cout << "Input middle name of student: ";
	getline(cin, mid_name);
	cout << "Input participation time in pairs: ";
	getline(cin, tmp);
	part_time = atoi(tmp.c_str());
}