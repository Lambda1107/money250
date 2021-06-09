#include <fstream>
#include "main.h"
using namespace std;

void err()
{
    cout << "输入指令有误！" << endl;
}

bool check(int &pos)
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

void init() //创建链表
{
    fstream fin("database", ios::binary | ios::in);
    HEADP = new books;
    books *pbooks = HEADP;
    books *pbooks1 = pbooks;
    while (!fin.eof())
    {
        pbooks1 = pbooks;
        fin.read((char *)(&pbooks->data), sizeof(book));
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
    //打印出主界面
}

void listBooks()
{
    //遍历链表输出returnInformation返回的string
}

void insertBook()
{
    //输出提示
    //判断输入
    int pos;
    //遍历出对应pos前一个的地址以及pos的地址
    books *pBooks1;
    books *pBooks2;
    //new出新book
    //让用户输入
    books *tmpBooks = new books();
    //插入
    pBooks1->next = tmpBooks;
    tmpBooks->next = pBooks2;
    //ojbk
}

void deleteBook()
{
    //输出提示
    //判断输入
    int pos;
    //遍历出对应pos前一个的地址以及pos的地址
    books *pBooks1;
    books *pBooks2;
    //记录下一个的地址
    books *tmpBook = pBooks2->next;
    //删除
    delete pBooks2;
    //接上
    pBooks1->next = tmpBook;
    //ojbk
}

void modifyBook()
{
    //输出提示
    //判断输入
    int pos;
    //遍历出对应pos的地址
    books *pBooks1;
    //修改吧
}

void findBook()
{
    //输出提示
    //判断输入
    char tmpInput[50];
    cin >> tmpInput;
    //遍历，与returnInformation匹配
    if (/*匹配到了*/)
    {
        //输出
    }
    //继续查找，直到指针指向NULL
}

void sortBook()
{
    //输出提示
    //判断输入，获取排序类型
    int method;     //按照不同的元素排序
    bool order = 0; //0升序，1降序
    if (!check(method))
    {
        return;
    }
    //冒泡排序………………
    books *pBooks1;
    books *pBooks2;
    //核心的比较大小部分用switch语句
    bool b = 0; //b等于0就说明说明pBooks1<pBooks2,如果是降序则替换，升序就不动
    switch (method)
    {
    case 1: //…………
        if (/*规则*/)
        {
            b = 0;
        }
    }
    //冒泡排序………………
}

void store()
{
    //跟load一样的，二进制存法
}