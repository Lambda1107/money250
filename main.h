#pragma once
#include <cstring>
#include <iostream>
#include "Book.h"
using namespace std;

//全局定义
#define QUIT 7
#define ERR 10
#define OK 11

//链表结构声明
struct books {
    Book data;
    books* next;
};

extern books* HEADP;

//全局函数
void err();

void init();
void printInterface();
void listBooks();
void insertBook();
void deleteBook();
void modifyBook();
void findBook();
void sortBook();
void store();

//全局错误
void err();

//各种输入检查
template <typename T>
bool check(T &pos)
{
    if (!(cin >> pos))
    {
        cin.clear();
        cin.sync();
        err();
        return false;
    }
    return true;
}

//找pos位置
bool findPos(int pos, books *pBooks);

//用户输入图书信息
bool inputBookInfo(books *tmpBooks);

//遍历链表查找信息
bool findSomething1(int input);

bool findSomething2(char input[50]);

bool findSomething3(char input[50]);

bool findSomething4(double input);

bool findSomething5(char input[50]);

bool findSomething6(int input);
//链表的冒泡函数
void bobbleSort(int way, int order);