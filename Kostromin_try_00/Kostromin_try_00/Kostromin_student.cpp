#include "Header.h"
#include "Kostromin_student.h"

void    Kostromin_student::cons_os()
{
    cout << "Name of student: " << name
        << "\nSurname of student: " << surname
        << "\nAge of student: " << age << '\n';
}

void    Kostromin_student::file_os(ofstream& out)
{
    out << name << '\n'
        << surname << '\n'
        << age << '\n';
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

void	Kostromin_student::file_is(istream& is)
{
    string tmp;
    getline(is, name);
    getline(is, surname);
    getline(is, tmp);
    age = atoi(tmp.c_str());
}

istream& operator >> (istream& in, Kostromin_student& self)
{
    string tmp;
    auto print_state = [&in](string str) {if (&in == &cin) cout << str; };
    print_state("Input name of student: ");
    getline(in, self.name);
    print_state("Input surname of student: ");
    getline(in, self.surname);
    print_state("Input age of student: ");
    getline(in, tmp);
    self.age = atoi(tmp.c_str());
    return in;
}

ostream& operator << (ostream& out, Kostromin_student* self)
{
     if (&out == &cout)
         return out << "Name of student: " << self->name
                    << "\nSurname of student: " << self->surname 
                    << "\nAge of student: " << self->age << '\n';
     return out << self->name << '\n'
         << self->surname << '\n'
         << self->age << '\n';
}
