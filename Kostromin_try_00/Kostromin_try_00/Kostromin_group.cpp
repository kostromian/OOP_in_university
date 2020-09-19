#include "Kostromin_group.h"

IMPLEMENT_SERIAL(Kostromin_group, CObject, 1)

//сериализация через mfc(необходимо подключить mfc к проекту)
void Kostromin_group::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	if (archive.IsStoring())
	{
		num_students = students.size();
		archive << num_students;
		for (auto it : students)
		{
			archive << it.get();
		}
	}
	else
	{
		students.clear();
		archive >> num_students;
		Kostromin_student *tmp;
		for (int i = 0; i != num_students; i++)
		{
			archive >> tmp;
			shared_ptr<Kostromin_student> tmp_shared(tmp);
			students.push_back(tmp_shared);
		}
	}
}

void Kostromin_group::Ser_from_file()
{
	string name_file;
	cout << "FILE TO WRITE\n";
	cin >> name_file;
	CFile f(name_file.c_str(), CFile::modeCreate | CFile::modeWrite);
	CArchive arStore(&f, CArchive::store);
	Serialize(arStore);
	arStore.Close();
	f.Close();
}

void Kostromin_group::Deser_from_file()
{
	string name_file;
	cout << "FILE TO READ\n";
	cin >> name_file;
	CFile f(name_file.c_str(), CFile::modeRead);
	CArchive  arLoad(&f, CArchive::load);
	Serialize(arLoad);
	arLoad.Close();
	f.Close();
}

Kostromin_group::Kostromin_group() 
{
	num_students = 0; 
}

void    Kostromin_group::Cons_os()
{
	for(auto it : students)	
	{
		it->cons_os();
		cout << '\n';
	}
}

void Kostromin_group::Add() 
{
	shared_ptr<Kostromin_student>	tmp(new Kostromin_student);
	tmp->cons_is();
	students.push_back(tmp);
}

void Kostromin_group::Add_starosta()
{
	shared_ptr<Kostromin_starosta>	tmp(new Kostromin_starosta);
	tmp->cons_is();
	students.push_back(tmp);
}