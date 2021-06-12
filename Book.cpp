#include<iostream>
#include<iomanip>
#include"Book.h"
#include<string.h>

using namespace std;

Book::Book(int _num, char _name[50], char _author[50], double _price, char _press[50], int _pressYear) {
    num = _num;
    strcpy_s(name, _name);
    strcpy_s(author, _author);
    price = _price;
    strcpy_s(press, _press);
    pressYear = _pressYear;
}

//char* Book::returnInformation() {
//
//}

void Book::printInformation() {
    cout << setw(10) << num
        << setw(10) << name
        << setw(10) << author
        << setw(10) << price
        << setw(10) << press
        << setw(10) << pressYear << endl;
}
