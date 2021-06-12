#pragma once
#include <string>
#include <iostream>
#include "Book.h"
using namespace std;

//ȫ�ֶ���
#define QUIT 8
#define ERR 10
#define OK 11

//����ṹ����
struct books {
    Book data;
    books* next;
};

extern books* HEADP;

//ȫ�ֺ���
void err();
bool check(int& pos);
void init();
void printInterface();
void listBooks();
void insertBook();
void deleteBook();
void modifyBook();
void findBook();
void sortBook();
void store();

