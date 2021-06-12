#pragma once
//组件库
#include <iostream>
#include "Book.h"
#include "main.h"
#include <string.h>
using namespace std;

//全局错误
void err();

//各种输入检查
template <typename T>
bool check(T pos)
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