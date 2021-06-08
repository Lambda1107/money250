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
bool strToVar(string str);
template <typename T, typename... Ts>
int strToVar(string str, T &var, Ts &...Vars)
{
    while (*(str.begin()) == ' ' || *(str.begin()) == '\n')
        str.erase(0, 1);
    istringstream ss(str);
    if (!(ss >> var))
    {
        return ERR;
    }
    size_t i = str.find(' ');
    if (i == str.npos)
        i = str.length();
    str.erase(0, i);
    return strToVar(str, Vars...);
}

template <typename... Ts>
bool getLineVar(istream &is, Ts &...Vars)
{
    string str;
    getline(is, str);
    return strToVar(str, Vars...);
}
