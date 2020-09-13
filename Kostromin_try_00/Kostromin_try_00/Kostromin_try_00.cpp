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
    enum states { add = 1, consol_out, read_fd, resave, clear, end };
    list<string> commands =
    {
        "1)ADD STUDENT TO GROUP",
        "2)COUT GROUP",
        "3)READ_FD",
        "4)OUT GROUP TO FILE",
        "5)CLEAR LIST",
        "6)EXIT"
    };

    for (;;)
    {
        for (auto i : commands) cout << i << endl;
        switch (prov_int(1, 6))
        {
        case add:
            system("cls");
            cin.ignore();
            group.add();
            break;
        case consol_out:
            system("cls");
            group.cons_os();
            break;
        case read_fd:
        {
            system("cls");
            cout << "FILE TO READ\n";
            cin >> tmp;
            ifstream is(tmp);
            group.file_is(is);
            break;
        }
        case resave:
        {
            system("cls");
            cout << "FILE TO WRITE\n";
            cin >> tmp;
            ofstream os(tmp);
            group.file_os(os);
            break;
        }
        case clear:
            system("cls");
            group.clear();
        case end:
            exit(0);
        }
    }
}

int main()
{
    Kostromin_starosta  star;
    Kostromin_group     group;
    

    CFile f;
    CFileException e;
    CString str = "Open_File.dat";
    f.Open(str, CFile::modeCreate | CFile::modeWrite, &e);
    CArchive arStore(&f, CArchive::store);
    group.Serialize(arStore);
    arStore.WriteString(str);
    arStore.Close();
    

    
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
