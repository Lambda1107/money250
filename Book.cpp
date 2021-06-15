#include <iostream>
#include <iomanip>
#include <cstring>
#include "Book.h"

using namespace std;

Book::Book(int _num, char _name[50], char _author[50], double _price, char _press[50], int _pressYear)
{
    num = _num;
    strcpy(name, _name);
    strcpy(author, _author);
    price = _price;
    strcpy(press, _press);
    pressYear = _pressYear;
}

Book::Book()
{
}

Book::~Book()
{
}

void Book::printInformation()
{
    cout << setw(10) << num
         << setw(10) << name
         << setw(10) << author
         << setw(10) << price
         << setw(10) << press
         << setw(10) << pressYear << endl;
}
