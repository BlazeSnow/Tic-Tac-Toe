// Copyright (C) 2024 BlazeSnow
// 保留所有权利
// 本程序以GNU General Public License v3.0的条款发布
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

int jing[9] = {0};
// X是1，O是2
int status = 1;

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
    cout << "Copyright (C) 2024 BlazeSnow.保留所有权利。" << endl;
    cout << "本程序以GNU General Public License v3.0的条款发布。" << endl;
    cout << "当前程序版本号：v1.0.0" << endl;
    cout << "https://github.com/BlazeSnow/Tic-Tac-Toe" << endl
         << endl;
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
            cout << temp << "号位置有" << pring_jing_words(jing[temp]) << "了" << endl;
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
    while (true)
    {
        print_jing();
        input();
        if (success() == 1)
        {
            print_jing_csv();
            break;
        }
    }
    system("pause");
    return 0;
}