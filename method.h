#pragma once
//����
#include <cstring>
#include <iostream>
#include "Book.h"
#include"utils.h"
using namespace std;

//ȫ�ֶ���
#define QUIT 8
#define ERR 9
#define OK 10


//�����ܺ���
void init();
void printInterface();
void listBooks();
void insertBook();
void deleteBook();
void modifyBook();
void findBook();
void sortBook();

