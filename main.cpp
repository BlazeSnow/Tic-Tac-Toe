#include <iostream>
#include <vector>
// #include <cstdlib>

using namespace std;

int jing[9] = {0};

char pring_jing_words(int number)
{
    if (number == 0)
    {
        return ' ';
    }
    else if (number == 1)
    {
        return 'X';
    }
    else if (number == 2)
    {
        return 'O';
    }
    else
    {
        cout << endl
             << "ERROR:棋盘内容出现错误" << endl;
        system("pause");
        exit(-1);
    }
}

void print_jing()
{
    system("cls");
    cout << " 1 " << pring_jing_words(jing[0]) << " |";
    cout << " 2 " << pring_jing_words(jing[1]) << " |";
    cout << " 3 " << pring_jing_words(jing[2]) << " |";
    cout << endl;
    cout << " 4 " << pring_jing_words(jing[3]) << " |";
    cout << " 5 " << pring_jing_words(jing[4]) << " |";
    cout << " 6 " << pring_jing_words(jing[5]) << " |";
    cout << endl;
    cout << " 7 " << pring_jing_words(jing[6]) << " |";
    cout << " 8 " << pring_jing_words(jing[7]) << " |";
    cout << " 9 " << pring_jing_words(jing[8]) << " |";
    cout << endl;
}

int main()
{
    system("chcp 65001");
    print_jing();
    system("pause");
    return 0;
}