#pragma once

class Book {
public:
    //ͼ���š����������ߡ��۸񡢳����硢�������
    int num;
    char name[50];
    char author[50];
    double price;
    char press[50];
    int pressYear;

    char* returnInformation(); //���ظ�ʽ���õ�char*
    void printInformation(); //��ӡ��ʽ���õ�char*

    Book(/* args */);
    Book(int _num, char _name[50], char _author[50], double _price, char _press[50], int _pressYear);
    ~Book();
};
