#include <iostream>
#include "Book.h"
#include "main.h"

using namespace std;

int main()
{
    HEADP = nullptr;
    int option = 0;
    init();
    do
    {
        printInterface();
        if (!check(option) /*或者option超出范围*/)
        {
            err();
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
        case 8: //退出
            store();
            break;
        default:
            err();
            break;
        }
    } while (option != QUIT);
    store();
    cout << "感谢使用" << endl;
}