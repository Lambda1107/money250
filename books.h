#pragma once

class book
{

public:
    //图书编号、书名、作者、价格、出版社、出版年份
    int num;
    int name;
    char author[50];
    double price;
    char press[50];
    int pressYear;
    //反正都要给main操作，干嘛要设置成private呢QwQ
    char *returnInformation(); //返回格式化好的char*
    book(/* args */);
    ~book();
};
