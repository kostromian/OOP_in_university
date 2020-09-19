#include "Kostromin_student.h"

IMPLEMENT_SERIAL(Kostromin_student, CObject, 1)

Kostromin_student::Kostromin_student()
{
    age = 18;
}

//сериализация через mfc(необходимо подключить mfc к проекту)
void    Kostromin_student::Serialize(CArchive& ar)
{
    CObject::Serialize(ar);
    if (ar.IsStoring())
        ar << name << surname << age;
    else
        ar >> name >> surname >> age;
}

void    Kostromin_student::cons_os()
{
    cout << "Name of student: " << name
        << "\nSurname of student: " << surname
        << "\nAge of student: " << age << endl;
}

void    Kostromin_student::cons_is()
{
    string tmp;
    cout << "Input name of student: ";
    getline(cin, name);
    cout << "Input surname of student: ";
    getline(cin, surname);
    cout << "Input age of student: ";
    getline(cin, tmp);
    age = atoi(tmp.c_str());
}
