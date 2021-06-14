#include <fstream>
#include "main.h"
#include "Book.h"
using namespace std;

void init() //创建链表
{
    fstream fin("database", ios::binary | ios::in);
    if (!fin)
        return;
    HEADP = new books;
    books *pbooks = HEADP;
    books *pbooks1 = pbooks;
    while (!fin.eof())
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
    system("clear");
    cout << "         图书管理" << endl;
    puts("");
    cout << "[1]    显示图书数据" << endl;
    puts("");
    cout << "[2]	插入图书数据" << endl;
    puts("");
    cout << "[3]	删除图书数据" << endl;
    puts("");
    cout << "[4]	修改图书数据" << endl;
    puts("");
    cout << "[5]	数据查询" << endl;
    puts("");
    cout << "[6]	数据排序" << endl;
    puts("");
    cout << "[7]    退出程序" << endl;
    puts("");
}

void listBooks()
{
    //遍历链表打印信息
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    while (p)
    {
        p->data.printInformation();
    }
}

void insertBook()
{
    int pos;
    cout << "请输入要插入到的位置： ";
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
    //输出提示
    cout << "         图书查询方式" << endl;
    puts("");
    cout << "[1]    图书编号" << endl;
    puts("");
    cout << "[2]	书名" << endl;
    puts("");
    cout << "[3]	作者" << endl;
    puts("");
    cout << "[4]	价格" << endl;
    puts("");
    cout << "[5]	出版商" << endl;
    puts("");
    cout << "[6]	出版年份" << endl;
    puts("");
    cout << "[7]    返回上一级功能" << endl;
    puts("");
    //判断输入

    int input1 = 0;
    char input2[50];
    double input3 = 0;

    int option = 0;
    do
    {
        printInterface();
        if (!check(option) /*或者option超出范围*/)
        {
            err();
            option = QUIT;
        }
        switch (option)
        {
        case 1:
            if (!check(input1))
            {
                err();
                return;
            }
            findSomething1(input1);
            break;
        case 2:
            if (!check(input2))
            {
                err();
                return;
            }
            findSomething2(input2);
            break;
        case 3:
            if (!check(input2))
            {
                err();
                return;
            }
            findSomething3(input2);
            break;
        case 4:
            if (!check(input3))
            {
                err();
                return;
            }
            findSomething4(input3);
            break;
        case 5:
            if (!check(input2))
            {
                err();
                return;
            }
            findSomething5(input2);
            break;
        case 6:
            if (!check(input1))
            {
                err();
                return;
            }
            findSomething6(input1);
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
    return true;
}

void err()
{
    cout << "输入内容有误！请检查输入！" << endl;
}

bool findPos(int pos, books *pBooks)
{
    for (int i = 0; i < pos; i++)
    {
        if (!pBooks)
        {
            err();
            return false;
        }
        pBooks = pBooks->next;
    }
    return true;
}

bool findSomething1(int input)
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (p->data.num == input)
        {
            p->data.printInformation();
            if_find = true;
        }
    }

    if (!if_find)
    {
        cout << "未查询到相关信息" << endl;
    }
    return if_find;
}

bool findSomething2(char input[50])
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (strcmp(p->data.name, input))
        {
            p->data.printInformation();
            if_find = true;
        }

        if (!if_find)
        {
            cout << "未查询到相关信息" << endl;
        }
        return if_find;
    }
    return if_find;
}

bool findSomething3(char input[50])
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (strcmp(p->data.author, input))
        {
            p->data.printInformation();
            if_find = true;
        }
    }

    if (!if_find)
    {
        cout << "未查询到相关信息" << endl;
    }
    return if_find;
}

bool findSomething4(double input)
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (p->data.price == input)
        {
            p->data.printInformation();
            if_find = true;
        }
    }

    if (!if_find)
    {
        cout << "未查询到相关信息" << endl;
    }
    return if_find;
}

bool findSomething5(char input[50])
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (strcmp(p->data.press, input))
        {
            p->data.printInformation();
            if_find = true;
        }
    }

    if (!if_find)
    {
        cout << "未查询到相关信息" << endl;
    }
    return if_find;
}

bool findSomething6(int input)
{
    books *p = HEADP;
    if (!p)
    {
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (p->data.pressYear == input)
        {
            p->data.printInformation();
            if_find = true;
        }
    }

    if (!if_find)
    {
        cout << "未查询到相关信息" << endl;
    }
    return if_find;
}

void bobbleSort(int way, int order)
{
    if (HEADP == NULL || HEADP->next == NULL)
    {
        cout << "无需要排序的数据" << endl;
        return;
    }
    books *p = NULL;
    bool isChange = true;

    int op;
    if (!(check(op)))
    {
        err();
        return;
    }

    switch (way)
    {
    case 1:
        if (!order)
        { //升序
            while (p != HEADP->next && isChange)
            {
                books *q = HEADP;
                isChange = false; //标志当前这一轮中又没有发生元素交换，如果没有则表示数组已经有序
                for (; q->next && q->next != p; q = q->next)
                {
                    if (q->data.num > q->next->data.num)
                    {
                        swap(q->data, q->next->data);
                        isChange = true;
                    }
                }
                p = q;
            }
        }
        else
        { //降序
            while (p != HEADP->next && isChange)
            {
                books *q = HEADP;
                isChange = false; //标志当前这一轮中又没有发生元素交换，如果没有则表示数组已经有序
                for (; q->next && q->next != p; q = q->next)
                {
                    if (q->data.num < q->next->data.num)
                    {
                        swap(q->data, q->next->data);
                        isChange = true;
                    }
                }
                p = q;
            }
        }
        break; //剩下的排序等测过了直接粘贴很快的
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:
        break;
    default:
        err();
        break;
    }
    return;
}

void sortBook()
{
    //输出提示
    cout << "         排序方式" << endl;
    puts("");
    cout << "[1]    图书编号" << endl;
    puts("");
    cout << "[2]	书名" << endl;
    puts("");
    cout << "[3]	作者" << endl;
    puts("");
    cout << "[4]	价格" << endl;
    puts("");
    cout << "[5]	出版商" << endl;
    puts("");
    cout << "[6]	出版年份" << endl;
    puts("");
    cout << "[7]    返回上一级功能" << endl;
    puts("");

    int method; //按照不同的元素排序
    if (!check(method))
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

    //冒泡排序………………
    books *pBooks1;
    books *pBooks2;
    switch (method)
    {
    case 1:

        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7: //退出
        break;
    }
}

void store()
{
    //跟load一样的，二进制存法
    fstream fout("database", ios::binary | ios::out);
    books *pbooks = HEADP;
    while (pbooks)
    {
        fout.write((char *)(&pbooks->data), sizeof(Book));
        pbooks = pbooks->next;
    }
    delete pbooks;
    fout.close();
}