#include <iostream>
#include "main.h"
#include "books.h"
using namespace std;
//全局变量
book* HEADP = NULL;

int main()
{
    int option = 0;
    init();
    do
    {
        printInterface();
        if (!check(option) /*或者option超出范围*/)
        {
            continue;
        }
        switch (option)
        {
        case 1: //显示图书数据
            listBooks();
            break;
        case 2: //插入图书数据
            insertBook();
            break;
        case 3: //删除图书数据
            deleteBook();
            break;
        case 4: //修改图书数据
            modifyBook();
            break;
        case 5: //数据查询
            findBook();
            break;
        case 6: //数据排序
            sortBook();
            break;
        case 7: //数据保存
            store();
            break;
        default:
            break;
        }
    } while (option == QUIT);
    store();
}