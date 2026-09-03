#include <cstdio>
#include <cstdlib>
#include <climits> // for linux
#include <filesystem>
#include <fstream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void enterToContinue() {
    printf("按回车键继续...");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    getchar();
}

void copyrightPrint() {
    printf("Copyright (C) 2024-2026 BlazeSnow. 保留所有权利。\n");
    printf("https://github.com/BlazeSnow/Tic-Tac-Toe\n\n");
}

int jing[9] = {0};
int status = 1;
vector<int> status_X;
vector<int> status_O;
int number_chess_permitted = 3;
int GameMode = -1;

void writeStatusXO(int position) {
    if (status == 1) {
        status_X.push_back(position);
    } else if (status == 2) {
        status_O.push_back(position);
    } else {
        printf("\nERROR:棋手状态出现错误\n");
        enterToContinue();
        exit(-1);
    }
}

void checkChessOutPermitted() {
    if (status_X.size() > number_chess_permitted) {
        jing[status_X.front()] = 0;
        status_X.erase(status_X.begin());
    }
    if (status_O.size() > number_chess_permitted) {
        jing[status_O.front()] = 0;
        status_O.erase(status_O.begin());
    }
}

char printJingWords(int number) {
    if (number == 0) {
        return ' ';
    } else if (number == 1) {
        return 'X';
    } else if (number == 2) {
        return 'O';
    } else {
        printf("\nERROR:棋盘内容出现错误\n");
        enterToContinue();
        exit(-1);
    }
}

void printJing() {
    clearConsole();
    copyrightPrint();
    if (GameMode == 0) {
        printf("当前模式为：普通模式\n\n");
    } else if (GameMode == 1) {
        printf("当前模式为：仅有3个棋子模式\n\n");
    }
    printf(" 1 %c | 2 %c | 3 %c |\n", printJingWords(jing[0]), printJingWords(jing[1]), printJingWords(jing[2]));
    printf(" 4 %c | 5 %c | 6 %c |\n", printJingWords(jing[3]), printJingWords(jing[4]), printJingWords(jing[5]));
    printf(" 7 %c | 8 %c | 9 %c |\n", printJingWords(jing[6]), printJingWords(jing[7]), printJingWords(jing[8]));
}

void input() {
    while (true) {
        printf("请输入%c下子位置：\n", printJingWords(status));
        int temp;
        scanf("%d", &temp);
        if (temp < 1 || temp > 9) {
            printf("输入数字应当在1~9之间\n");
            continue;
        } else {
            temp--;
        }
        if (jing[temp] == 0) {
            jing[temp] = status;
            writeStatusXO(temp);
            if (status == 1) {
                status = 2;
                break;
            } else if (status == 2) {
                status = 1;
                break;
            }
        } else if (jing[temp] == 1 || jing[temp] == 2) {
            printf("%d号位置有%c了\n", temp + 1, printJingWords(jing[temp]));
        }
    }
}

void printJingCsv() {
    fstream file("Tic-Tac-Toe.csv", ios::out);
    if (file.is_open()) {
        file << printJingWords(jing[0]) << "," << printJingWords(jing[1]) << "," << printJingWords(jing[2]) << endl;
        file << printJingWords(jing[3]) << "," << printJingWords(jing[4]) << "," << printJingWords(jing[5]) << endl;
        file << printJingWords(jing[6]) << "," << printJingWords(jing[7]) << "," << printJingWords(jing[8]) << endl;
        file.close();
        printf("打印棋盘成功\n");
        printf("文件名：\"Tic-Tac-Toe.csv\"\n");
        printf("路径：%s\n", filesystem::current_path().string().c_str());
    } else {
        printf("ERROR:打印棋盘到csv失败\n");
    }
}

int success() {
    int answer = 1;
    if ((jing[0] == answer && jing[1] == answer && jing[2] == answer) ||
        (jing[3] == answer && jing[4] == answer && jing[5] == answer) ||
        (jing[6] == answer && jing[7] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[3] == answer && jing[6] == answer) ||
        (jing[1] == answer && jing[4] == answer && jing[7] == answer) ||
        (jing[2] == answer && jing[5] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[4] == answer && jing[8] == answer) ||
        (jing[2] == answer && jing[4] == answer && jing[6] == answer)) {
        printJing();
        printf("%c赢了\n", printJingWords(answer));
        return 1;
    }
    answer = 2;
    if ((jing[0] == answer && jing[1] == answer && jing[2] == answer) ||
        (jing[3] == answer && jing[4] == answer && jing[5] == answer) ||
        (jing[6] == answer && jing[7] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[3] == answer && jing[6] == answer) ||
        (jing[1] == answer && jing[4] == answer && jing[7] == answer) ||
        (jing[2] == answer && jing[5] == answer && jing[8] == answer) ||
        (jing[0] == answer && jing[4] == answer && jing[8] == answer) ||
        (jing[2] == answer && jing[4] == answer && jing[6] == answer)) {
        printJing();
        printf("%c赢了\n", printJingWords(answer));
        return 1;
    }
    int count = 0;
    for (auto i: jing) {
        if (i == 0) {
            count++;
        }
    }
    if (count == 0) {
        printJing();
        printf("平局\n");
        return 1;
    }
    return 0;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    clearConsole();
    copyrightPrint();
    printf("正常模式(0)或仅有3个棋子模式(1)：\n");
    scanf("%d", &GameMode);
    if (GameMode == 0) {
        number_chess_permitted = INT_MAX;
    } else if (GameMode == 1) {
        number_chess_permitted = 3;
    } else {
        printf("ERROR:输入不合法\n");
        enterToContinue();
        exit(1);
    }
    while (true) {
        printJing();
        input();
        checkChessOutPermitted();
        if (success() == 1) {
            printJingCsv();
            break;
        }
    }
    enterToContinue();
    return 0;
}
