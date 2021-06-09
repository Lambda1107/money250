#pragma once

class Book{
public:
    //图书编号、书名、作者、价格、出版社、出版年份
    int num;
    char name[50];
    char author[50];
    double price;
    char press[50];
    int pressYear;
    
    char *returnInformation(); //返回格式化好的char*
    void printInformation(); //打印格式化好的char*

    Book(/* args */);
    Book(int _num, char _name[50],char _author[50], double _price, char _press[50], int _pressYear);
    ~Book();
};
