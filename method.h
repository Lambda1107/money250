#pragma once
//功能
#include <cstring>
#include <iostream>
#include "Book.h"
#include"utils.h"
using namespace std;

//全局定义
#define QUIT 8
#define ERR 9
#define OK 10


//主功能函数
void init();
void printInterface();
void listBooks();
void insertBook();
void deleteBook();
void modifyBook();
void findBook();
void sortBook();

