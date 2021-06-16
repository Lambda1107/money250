#pragma once
//С���
#include <iostream>
#include <fstream>
#include "Book.h"
using namespace std;

//����ṹ����
struct books
{
    Book data;
    books *next;
};

extern books *HEADP;
void init();           //��������
void store();          //��������
void printInterface(); //index

//��posλ��
bool findPos(int pos, books *&pBooks);

//�û�����ͼ����Ϣ
bool inputBookInfo(books *tmpBooks);

//�������������Ϣ
void findSomething(char input[50], int way);

//�����ð�ݺ���
void bobbleSort(books *head, int way, int order);

//ȫ�ִ���
void err();

//����������
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