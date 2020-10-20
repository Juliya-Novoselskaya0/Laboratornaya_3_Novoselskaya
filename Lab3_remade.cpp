// example_by_teacher.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Lab #3 
//Task 13
//
//perfomed by Juliya Novoselskaya 
//group 044691
#include <iostream>
#include <string.h>

class set {
    char* str;
public:
    set(char* ss) {
        str = new char[strlen(ss) + 1];
        strcpy_s(str, strlen(ss) + 1, ss);
    }
    set(const set& ss)
    {
        str = new char[strlen(ss.str) + 1];
        strcpy_s(str, strlen(ss.str) + 1, ss.str);
    }
    ~set()
    {
        delete[] str;
    }
    char* operator+(set);
};

char* non_repeatRecording(char* s1, char* st, int &l)
{
    int t = 0;
    int j = 0;
    int i = 0;
    bool v = false;
    int k = 0;
    for (j = 0; st[j] != '\0'; j++)
    {
        for (k = 0; s1[k] != '\0'; k++)
        {
            if (st[j] == s1[k])
            {
                v = true;
                break;
            }
            else {
                v = false;
            }
        }
        if ((k != 0) && (v == false))
        {
            s1[l] = st[j];
            l++;
        }
    }
    s1[l] = '\0';
    return s1;
}

char* set:: operator+(set S)
{
    int l = 0;
    int size = strlen(str) + strlen(S.str);
    char* s1 = new char[size];
    non_repeatRecording(non_repeatRecording(s1, str, l), S.str, l);
    return s1;
}

int main()
{
    char ss[80];
    char* ss1;
    std::cout << "Vvod stroki 1" << std::endl;
    std::cin >> ss;
    set S1(ss);
    std::cout << "Vvod stroki 2" << std::endl;
    std::cin >> ss;
    set S2(ss);
    std::cout << "Obiedinenie strok" << std::endl;
    ss1 = S1.operator+(S2);
    std::cout << ss1 << std::endl;
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
