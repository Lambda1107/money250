//小组件
#include<iostream>
#include<fstream>
#include"utils.h"
#include<cstring>
#include<stdlib.h>
#include<iomanip>
#include"Book.h"
#include"method.h"
using namespace std;

books *HEADP = nullptr;

void init() //创建链表,从二进制文件中读入
{
    HEADP = nullptr;//没数据的话在下面return是个空指针
    fstream fin("database.dat", ios::binary | ios::in);
    if (!fin)
        return;
    HEADP = new books;
    books *pbooks = HEADP;
    books *pbooks1 = pbooks;
    while (!fin.eof() && fin.peek() != EOF)
    {
        pbooks1 = pbooks;
        fin.read((char *)(&pbooks->data), sizeof(Book));
        pbooks->next = new books;
        pbooks = pbooks->next;
    } //读到文件尾了就退出
    delete pbooks;
    pbooks1->next = NULL;
    fin.close();
}

void printInterface()
{
    system("cls");
    cout << "         图书管理" << endl;
    cout << endl;
    cout << "[1]    显示图书数据" << endl;
    cout << endl;
    cout << "[2]	插入图书数据" << endl;
    cout << endl;
    cout << "[3]	删除图书数据" << endl;
    cout << endl;
    cout << "[4]	修改图书数据" << endl;
    cout << endl;
    cout << "[5]	数据查询" << endl;
    cout << endl;
    cout << "[6]	数据排序" << endl;
    cout << endl;
    cout << "[7]    数据保存" << endl;
    cout << endl;
    cout << "[8]    退出程序" << endl;
    cout << endl;
}

void err()
{
    cout << "输入内容有误！请检查输入！" << endl;
}

bool findPos(int pos, books* &pBooks)
{
    for (int i = 0; i < pos; i++)
    {
        if (!pBooks)
        {
            err();
            return false;
        }
        cout << "go next" << endl;//方便dbug
        pBooks = pBooks->next;
    }
    return true;
}

void findSomething(char input[50], int way)
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (strcmp(p->data.info[way], input)==0)
        {
            if(!if_find){
                cout << setw(10) << "书籍编号"
                << setw(10) << "书名"
                << setw(10) << "作者"
                << setw(10) << "价格"
                << setw(10) << "出版社"
                << setw(10) << "出版年份" << endl;
            }
            p->data.printInformation();
            if_find = true;
        }
        p = p->next;
    }

    if (!if_find)
    {
        cout << "未查询到相关信息" << endl;
    }
}

bool inputBookInfo(books *tmpBooks)
{
    cout << "图书编号： ";
    if (!check(tmpBooks->data.num))
    {
        return false;
    }
    cout << "图书名称： ";
    if (!check(tmpBooks->data.name))
    {
        return false;
    }
    cout << "作者： ";
    if (!check(tmpBooks->data.author))
    {
        return false;
    }
    cout << "价格： ";
    if (!check(tmpBooks->data.price))
    {
        return false;
    }
    cout << "出版社： ";
    if (!check(tmpBooks->data.press))
    {
        return false;
    }
    cout << "出版年份： ";
    if (!check(tmpBooks->data.pressYear))
    {
        return false;
    }

    sprintf(tmpBooks->data.info[0],"%d",tmpBooks->data.num);
    strcpy(tmpBooks->data.info[1], tmpBooks->data.name);
    strcpy(tmpBooks->data.info[2], tmpBooks->data.author);
    sprintf(tmpBooks->data.info[3],"%lf",tmpBooks->data.price);
    strcpy(tmpBooks->data.info[4], tmpBooks->data.press);
    sprintf(tmpBooks->data.info[5],"%d",tmpBooks->data.pressYear);

    //test
    // cout << "here" << endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << tmpBooks->data.info[i] << endl;
    // }
    
    return true;
}

void store()
{
    //跟load一样的，二进制存法
    fstream fout("database.dat", ios::binary | ios::out);
    books *pbooks = HEADP;
    while (pbooks)
    {
        fout.write((char *)(&pbooks->data), sizeof(Book));
        pbooks = pbooks->next;
    }
    delete pbooks;
    fout.close();
}