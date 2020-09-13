#include "Kostromin_starosta.h"

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

void Kostromin_starosta::file_os(ofstream& os)
{
	Kostromin_student::file_os(os);
	os	<< mid_name << '\n'
		<< part_time << '\n';
}

void Kostromin_starosta::file_is(istream& is)
{
	string tmp;
	Kostromin_student::file_is(is);
	getline(is, mid_name);
	getline(is, tmp);
	part_time = atoi(tmp.c_str());
}