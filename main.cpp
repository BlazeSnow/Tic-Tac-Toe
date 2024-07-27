// Copyright (C) 2024 BlazeSnow
// 保留所有权利
// 本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

void BlazeSnow_copyright_print()
{
    cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
    cout << "本程序以GNU General Public License v3.0的条款发布。" << endl;
    cout << "当前程序版本号：v1.1.1" << endl;
    cout << "https://github.com/BlazeSnow/Tic-Tac-Toe" << endl
         << endl;
}

// 棋盘
int jing[9] = {0};
// X是1，O是2
int status = 1;
// X和O的位置序列，下第4个棋时，清除棋盘上第一个棋
vector<int> status_X;
vector<int> status_O;
// 棋盘上允许有几个棋
int number_chess_permitted = 3;
// 游戏模式，0为正常模式，1为仅有3个棋子模式
int GameMode = -1;

void write_status_X_O(int position)
{
    if (status == 1)
    {
        status_X.push_back(position);
    }
    else if (status == 2)
    {
        status_O.push_back(position);
    }
    else
    {
        cout << endl
             << "ERROR:棋手状态出现错误" << endl;
        system("pause");
        exit(-1);
    }
}

void check_chess_out_permitted()
{
    if (status_X.size() > number_chess_permitted)
    {
        jing[status_X.front()] = 0;
        status_X.erase(status_X.begin());
    }
    if (status_O.size() > number_chess_permitted)
    {
        jing[status_O.front()] = 0;
        status_O.erase(status_O.begin());
    }
}

// 数字转 XO
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

// 打印棋盘
void print_jing()
{
    system("cls");
    BlazeSnow_copyright_print();
    if (GameMode == 0)
    {
        cout << "当前模式为：普通模式" << endl
             << endl;
    }
    else if (GameMode == 1)
    {
        cout << "当前模式为：仅有3个棋子模式" << endl
             << endl;
    }
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

// 输入内容-下棋
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
            write_status_X_O(temp);
            if (status == 1)
            {
                status = 2;
                break;
            }
            else if (status == 2)
            {
                status = 1;
                break;
            }
        }
        else if (jing[temp] == 1 || jing[temp] == 2)
        {
            cout << temp + 1 << "号位置有" << pring_jing_words(jing[temp]) << "了" << endl;
        }
    }
}

// 打印棋盘到csv文件
void print_jing_csv()
{
    fstream file("Tic-Tac-Toe.csv", ios::out);
    if (file.is_open())
    {
        file << pring_jing_words(jing[0]) << ",";
        file << pring_jing_words(jing[1]) << ",";
        file << pring_jing_words(jing[2]) << ",";
        file << endl;
        file << pring_jing_words(jing[3]) << ",";
        file << pring_jing_words(jing[4]) << ",";
        file << pring_jing_words(jing[5]) << ",";
        file << endl;
        file << pring_jing_words(jing[6]) << ",";
        file << pring_jing_words(jing[7]) << ",";
        file << pring_jing_words(jing[8]) << ",";
        file << endl;
        file.close();
        cout << "打印棋盘成功" << endl;
        cout << "文件名：\"Tic-Tac-Toe.csv\"" << endl;
        cout << "路径：" << filesystem::current_path() << endl;
    }
    else
    {
        cout << "ERROR:打印棋盘到csv失败" << endl;
    }
}

int success()
{
    int answer = 1;
    if (
        (jing[0] == answer && jing[1] == answer && jing[2] == answer) ||
        (jing[3] == answer && jing[4] == answer && jing[5] == answer) ||
        (jing[6] == answer && jing[7] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[3] == answer && jing[6] == answer) ||
        (jing[1] == answer && jing[4] == answer && jing[7] == answer) ||
        (jing[2] == answer && jing[5] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[4] == answer && jing[8] == answer) ||
        (jing[2] == answer && jing[4] == answer && jing[6] == answer))
    {
        print_jing();
        cout << pring_jing_words(answer) << "赢了" << endl;
        return 1;
    }
    answer = 2;
    if (
        (jing[0] == answer && jing[1] == answer && jing[2] == answer) ||
        (jing[3] == answer && jing[4] == answer && jing[5] == answer) ||
        (jing[6] == answer && jing[7] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[3] == answer && jing[6] == answer) ||
        (jing[1] == answer && jing[4] == answer && jing[7] == answer) ||
        (jing[2] == answer && jing[5] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[4] == answer && jing[8] == answer) ||
        (jing[2] == answer && jing[4] == answer && jing[6] == answer))
    {
        print_jing();
        cout << pring_jing_words(answer) << "赢了" << endl;
        return 1;
    }
    answer = 0;
    int count = 0;
    for (auto i : jing)
    {
        if (i == answer)
        {
            count++;
        }
    }
    if (count == 0)
    {
        print_jing();
        cout << "平局" << endl;
        return 1;
    }
    return 0;
}

int main()
{
    system("chcp 65001");
    system("cls");
    BlazeSnow_copyright_print();
    cout << "正常模式(0)或仅有3个棋子模式(1)：" << endl;
    cin >> GameMode;
    if (GameMode == 0)
    {
        number_chess_permitted = INT_MAX;
    }
    else if (GameMode == 1)
    {
        number_chess_permitted = 3;
    }
    else
    {
        cout << "ERROR:输入不合法" << endl;
        system("pause");
        exit(1);
    }
    while (true)
    {
        print_jing();
        input();
        check_chess_out_permitted();
        if (success() == 1)
        {
            print_jing_csv();
            break;
        }
    }
    system("pause");
    return 0;
}