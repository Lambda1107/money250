#pragma once
#include <string>
#include <iostream>
#include "books.h"
using namespace std;

//全局定义
#define QUIT 9
#define ERR 10
#define OK 11
extern books *HEADP;
//链表结构声明
struct books
{
    book data;
    books *next;
};

//全局函数
void err();
bool check(int &pos);
void init();
void printInterface();
void listBooks();
void insertBook();
void deleteBook();
void modifyBook();
void findBook();
void sortBook();
void store();
