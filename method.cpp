#include <fstream>
#include "main.h"
#include "utils.h"
using namespace std;

void init() //创建链表
{
    fstream fin("database", ios::binary | ios::in);
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
    system("cls");
    cout << "         图书管理" << endl; puts("");
    cout << "[1]    显示图书数据" << endl; puts("");
    cout << "[2]	插入图书数据" << endl; puts("");
    cout << "[3]	删除图书数据" << endl; puts("");
    cout << "[4]	修改图书数据" << endl; puts("");
    cout << "[5]	数据查询" << endl; puts("");
    cout << "[6]	数据排序" << endl; puts("");
    cout << "[7]    退出程序" << endl; puts("");
}

void listBooks(){
//遍历链表打印信息
    books* p = HEADP;
    if (!p){
        cout << "图书数据为空" << endl;
    }

    while (p){
        p->data.printInformation();
    }
}

void insertBook()
{
    int pos;
    cout << "请输入要插入到的位置： ";
    if(!check(pos)){
        err();
        return;
    }
    
    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;

    if(!findPos(pos, pBooks)){
        return;
    }

    books* tmpBooks = new books;
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
    if(!check(pos)){
        err();
        return;
    }
    
    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;

    if(!findPos(pos-1, pBooks)){
        //找要删除对象的前一个结点
        return;
    }

    if(!pBooks->next){
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
    if(!check(pos)){
        err();
        return;
    }
    
    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;

    if(!findPos(pos, pBooks)){
        return;
    }

    inputBookInfo(pBooks);

    HEADP = dummuHead->next;
    delete dummuHead;
}

void findBook()
{
    //输出提示
    cout << "         图书查询方式" << endl; puts("");
    cout << "[1]    图书编号" << endl; puts("");
    cout << "[2]	书名" << endl; puts("");
    cout << "[3]	作者" << endl; puts("");
    cout << "[4]	价格" << endl; puts("");
    cout << "[5]	出版商" << endl; puts("");
    cout << "[6]	出版年份" << endl; puts("");
    cout << "[7]    返回上一级功能" << endl; puts("");
    //判断输入
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
            int input;
            if(!check(input)){
                err();
                return;
            }
            findSomething(input, 1);
            break;
        case 2: 
            char input[50];
            if(!check(input)){
                err();
                return;
            }
            findSomething(input, 2);
            break;
        case 3: 
            char input[50];
            if(!check(input)){
                err();
                return;
            }
            findSomething(input, 3);
            break;
        case 4: 
            double input;
            if(!check(input)){
                err();
                return;
            }
            findSomething(input, 4);
            break;
        case 5: 
            char input[50];
            if(!check(input)){
                err();
                return;
            }
            findSomething(input, 5);
            break;
        case 6: 
            int input;
            if(!check(input)){
                err();
                return;
            }
            findSomething(input, 6);
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
        if (1/*规则*/)
        {
            b = 0;
        }
    }
    //冒泡排序………………
}

void store()
{
    //跟load一样的，二进制存法
    fstream fout("database", ios::binary | ios::out);
    books* pbooks = HEADP;
    while (pbooks){
        fout.write((char *)(&pbooks->data), sizeof(Book));
        pbooks = pbooks->next;
    } 
    delete pbooks;
    fout.close();
}