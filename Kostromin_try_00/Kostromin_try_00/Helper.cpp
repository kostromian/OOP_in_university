#include "Helper.h"

istream& getline(istream& is, CString &Cstr)
{
    string tmp = Cstr.GetString();
    getline(is, tmp);
    Cstr.SetString(tmp.c_str());
    return is;
}

short int prov_int(short int min = -32767, short int max = 32767)
{
    short int out;
    while (!(cin >> out) || (out > max) || (out < min))
    {
        cout << "ERROR RETRY: ";
        cin.clear();
        cin.ignore(32767, '\n');
    }
    return out;
}