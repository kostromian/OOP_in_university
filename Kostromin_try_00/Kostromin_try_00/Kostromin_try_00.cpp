// Kostromin_try_00.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"
#include "Kostromin_student.h"
#include "Kostromin_group.h"
using namespace std;

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

void menu(Kostromin_group& group)
{
    string tmp;
    ifstream is;
    ofstream os;
    enum states { add = 1, consol_out, read_fd, resave, clear };
    list<string> commands =
    {
        "1)ADD STUDENT TO GROUP",
        "2)COUT GROUP",
        "3)READ_FD",
        "4)OUT GROUP TO FILE",
        "5)CLEAR LIST"
    };

    for (;;)
    {
        for (auto i : commands) cout << i << endl;
        switch (prov_int(1, 5))
        {
        case add:
            system("cls");
            group.add();
            break;
        case consol_out:
            system("cls");
            cout << group;
            break;
        case read_fd:
            system("cls");
            cout << "FILE TO READ\n";
            cin >> tmp;
            is.open(tmp);
            is >> group;
            is.close();
            break;
        case resave:
            system("cls");
            cout << "FILE TO WRITE\n";
            cin >> tmp;
            os.open(tmp);
            os << group;
            os.close();
            break;
        case clear:
            system("cls");
            group.clear();
        }
    }
}

int main()
{
    Kostromin_student stud;
    Kostromin_group     group;
    menu(group);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
