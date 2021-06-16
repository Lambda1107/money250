#include <iostream>
#include "Book.h"
#include "method.h"

using namespace std;

books *HEADP = nullptr;

int main()
{
    int option = 0;
    init();
    printInterface();
    do
    {
        cout << "��ѡ������� ";
        if (!check(option) /*����option������Χ*/)
        {
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
            break;
        default:
            err();
            break;
        }
    } while (option != QUIT);
    store();
    cout << "��лʹ��" << endl;
}