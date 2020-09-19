// Kostromin_try_00.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Helper.h"
#include "Kostromin_student.h"
#include "Kostromin_starosta.h"
#include "Kostromin_group.h"

void menu(Kostromin_group& group)
{
    string tmp;
    enum states { add = 1, consol_out, ser, deser, clear, add_starosta, end};
    list<string> commands =
    {
        "1)ADD STUDENT TO GROUP",
        "2)COUT GROUP",
        "3)SERIALIZE",
        "4)DESERIALIZE",
        "5)CLEAR LIST",
        "6)ADD STAROSTA TO GROUP",
        "7)EXIT",
    };

    for (;;)
    {
        system("cls");
        for (auto& i : commands) cout << i << endl;
        switch (prov_int(1, 7))
        {
        case add:
            cin.ignore();
            group.Add();
            break;
        case consol_out:
            group.Cons_os();
            system("pause");
            break;
        case clear:
            group.students.clear();
            break;
        case add_starosta:
            cin.ignore();
            group.Add_starosta();
            break;
        case ser:
        {
            group.Ser_from_file();
            break;
        }
        case deser:
        {
            group.Deser_from_file();
            break;
        }
        case end:
            exit(0);
        }
    }
}

int main()
{
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
