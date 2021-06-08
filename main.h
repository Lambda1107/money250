#pragma once
#include <string>
#include <iostream>
#include "books.h"
using namespace std;

//全局定义
#define QUIT 9
#define ERR 10
#define OK 11

//链表结构声明
struct books
{
    book data;
    books *next;
};

//全局函数
void err();
