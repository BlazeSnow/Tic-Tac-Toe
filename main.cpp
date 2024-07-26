#include <iostream>
#include <vector>
// #include <cstdlib>

using namespace std;

int jing[9] = {0};
// X是1，O是2
int status = 1;

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

void input()
{
    while (true)
    {
        cout << "请输入" << pring_jing_words(status) << "下子位置：" << endl;
        int temp;
        cin >> temp;
        if (temp < 1 || temp > 9)
        {
            cout << "输入数字应当在1~9之间" << endl;
            continue;
        }
        else
        {
            temp--;
        }
        if (jing[temp] == 0)
        {
            jing[temp] = status;
            if (status = 1)
            {
                status = 2;
                break;
            }
            else if (status = 2)
            {
                status = 1;
                break;
            }
        }
        else if (jing[temp] == 1 || jing[temp] == 2)
        {
            cout << temp << "号位置有" << pring_jing_words(jing[temp]) << "了" << endl;
        }
    }
}

int success()
{
    return 0;
}

int main()
{
    system("chcp 65001");
    while (true)
    {
        print_jing();
        input();
        if (success() == 1)
            break;
    }
    system("pause");
    return 0;
}