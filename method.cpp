//功能
#include <fstream>
#include "method.h"
#include "utils.h"
#include "Book.h"
#include <iomanip>
using namespace std;

void listBooks()
{
    books *p = HEADP;
    // cout << "进入listbook" << endl;
    if (!p)
    {
        cout << "图书数据为空" << endl;
        return;
    }

    cout << setw(10) << "书籍编号"
         << setw(10) << "书名"
         << setw(10) << "作者"
         << setw(10) << "价格"
         << setw(10) << "出版社"
         << setw(10) << "出版年份" << endl;
    while (p)
    {
        p->data.printInformation();
        p = p->next;
    }
}

void insertBook()
{
    int pos;
    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;
    cout << "请输入要插入到的位置： ";
    if (!check(pos))
    {
        err();
        return;
    }
    if (pos <= 0)
    {
        err();
        return;
    }

    if (!findPos(pos - 1, pBooks))
    { //找到它前面一个位置
        return;
    }

    books *tmpBooks = new books;
    inputBookInfo(tmpBooks);

    tmpBooks->next = pBooks->next;
    pBooks->next = tmpBooks;

    HEADP = dummuHead->next;
    delete dummuHead;
}

void deleteBook()
{
    int pos;
    cout << "请输入要删除的位置： ";
    if (!check(pos))
    {
        err();
        return;
    }

    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;

    if (!findPos(pos - 1, pBooks))
    {
        //找要删除对象的前一个结点
        return;
    }

    if (!pBooks->next)
    {
        err();
        return;
    }

    books *ptmp = pBooks->next;
    pBooks->next = pBooks->next->next;
    delete ptmp;

    HEADP = dummuHead->next;
    delete dummuHead;
}

void modifyBook()
{
    int pos;
    cout << "请输入要修改的位置： ";
    if (!check(pos))
    {
        err();
        return;
    }

    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;

    if (!findPos(pos, pBooks))
    {
        return;
    }

    inputBookInfo(pBooks);

    HEADP = dummuHead->next;
    delete dummuHead;
}

void findBook()
{
    char input[50];

    int option = 0;
    do
    {
        //输出提示
        cout << "         图书查询方式" << endl;
        cout << endl;
        cout << "[1]    图书编号" << endl;
        cout << endl;
        cout << "[2]	书名" << endl;
        cout << endl;
        cout << "[3]	作者" << endl;
        cout << endl;
        cout << "[4]	价格" << endl;
        cout << endl;
        cout << "[5]	出版商" << endl;
        cout << endl;
        cout << "[6]	出版年份" << endl;
        cout << endl;
        cout << "[7]    返回上一级功能" << endl;
        cout << endl;
        cout << "请输入查询方式： ";
        if (!check(option) || option > 7 || option < 1)
        {
            err();
            continue;
        }

        switch (option)
        {
        case 1:
            cout << "请输入编号  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 0);
            break;
        case 2:
            cout << "请输入书名  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 1);
            break;
        case 3:
            cout << "请输入作者  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 2);
            break;
        case 4:
            cout << "请输入价格  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 3);
            break;
        case 5:
            cout << "请输入出版社  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 4);
            break;
        case 6:
            cout << "请输入出版时间  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 5);
            break;
        case 7:
            option = QUIT;
            break;

        default:
            err();
            break;
        }
    } while (option != QUIT);
}

void sortBook()
{
    //输出提示
    cout << "         排序方式" << endl;
    cout << endl;
    cout << "[1]    图书编号" << endl;
    cout << endl;
    cout << "[2]	书名" << endl;
    cout << endl;
    cout << "[3]	作者" << endl;
    cout << endl;
    cout << "[4]	价格" << endl;
    cout << endl;
    cout << "[5]	出版商" << endl;
    cout << endl;
    cout << "[6]	出版年份" << endl;
    cout << endl;
    cout << "[7]    返回上一级功能" << endl;
    cout << endl;

    int method; //按照不同的元素排序
    if (!check(method))
    {
        err();
        return;
    }

    if (method == 7)
        return;

    if (method < 1 || method > 7)
    {
        err();
        return;
    }

    cout << " 顺序选择：【0】升序， 【1】降序       ";
    int order = 0; //0升序，1降序
    if (!check(order))
    {
        err();
        return;
    }

    bobbleSort(HEADP, method, order);
}
