#include "Header.h"
#include "Kostromin_student.h"

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

ostream& operator << (ostream& out, Kostromin_student& self)
{
     if (&out == &cout)
         return out << "Name of student: " << self.name
                    << "\nSurname of student: " << self.surname 
                    << "\nAge of student: " << self.age << '\n';
     return out << self.name << '\n'
         << self.surname << '\n'
         << self.age << '\n';
}
