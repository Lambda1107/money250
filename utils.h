#pragma once
//小组件
#include <iostream>
#include <fstream>
#include "Book.h"
using namespace std;

//链表结构声明
struct books
{
    Book data;
    books *next;
};

extern books *HEADP;
void init();           //创建链表
void store();          //保存链表
void printInterface(); //index

//找pos位置
bool findPos(int pos, books *&pBooks);

//用户输入图书信息
bool inputBookInfo(books *tmpBooks);

//遍历链表查找信息
void findSomething(char input[50], int way);

//链表的冒泡函数
void bobbleSort(books *head, int way, int order);

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