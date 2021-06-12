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
        if (!check(option) /*����option������Χ*/)
        {
            err();
            continue;
        }
        switch (option)
        {
        case 1: //��ʾͼ������
            listBooks();
            break;
        case 2: //����ͼ������
            insertBook();
            break;
        case 3: //ɾ��ͼ������
            deleteBook();
            break;
        case 4: //�޸�ͼ������
            modifyBook();
            break;
        case 5: //���ݲ�ѯ
            findBook();
            break;
        case 6: //��������
            sortBook();
            break;
        case 7: //���ݱ���
            store();
            break;
        case 8: //�˳�
            store();
            break;
        default:
            err();
            break;
        }
    } while (option != QUIT);
    store();
    cout << "��лʹ��" << endl;
}