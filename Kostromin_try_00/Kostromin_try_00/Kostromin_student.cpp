#include "Kostromin_student.h"

ifstream& operator >> (ifstream& in, Kostromin_student& self)
{
    getline(in, self.name);
    getline(in, self.surname);
    in >> self.age;
    return in;
}

istream& operator >> (istream& in, Kostromin_student& self)
{
    cout << "Input name of student: ";
    getline(cin, self.name);
    cout << "Input surname of student: ";
    getline(cin, self.surname);
    cout << "Input age of student: ";
    cin >> self.age;
    return cin;
}

ostream& operator << (ostream& out, Kostromin_student& self)
{
    return out  << "Name of student: " << self.name
                << "\nSurname of student: " << self.surname 
                << "\nAge of student: " << self.age;
}
