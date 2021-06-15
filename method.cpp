//����
#include <fstream>
#include "method.h"
#include "Book.h"
#include<iomanip>
using namespace std;

void listBooks()
{
    books *p = HEADP;
    cout << "����listbook" << endl;
    if (!p)
    {
        cout << "ͼ������Ϊ��" << endl;
        return;
    }

    cout << setw(10) << "�鼮���"
         << setw(10) << "����"
         << setw(10) << "����"
         << setw(10) << "�۸�"
         << setw(10) << "������"
         << setw(10) << "�������" << endl;
    while (p)
    {
        p->data.printInformation();
        p = p->next;
    }
}

void insertBook()
{
    int pos;
    cout << "������Ҫ���뵽��λ�ã� ";
    if (!check(pos))
    {
        err();
        return;
    }

    books *dummuHead = new books;
    dummuHead->next = HEADP;
    books *pBooks = dummuHead;

    if (!findPos(pos-1, pBooks))
    {//�ҵ���ǰ��һ��λ��
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
    cout << "������Ҫɾ����λ�ã� ";
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
        //��Ҫɾ�������ǰһ�����
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
    cout << "������Ҫ�޸ĵ�λ�ã� ";
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
        //�����ʾ
        cout << "         ͼ���ѯ��ʽ" << endl;
        cout << endl;
        cout << "[1]    ͼ����" << endl;
        cout << endl;
        cout << "[2]	����" << endl;
        cout << endl;
        cout << "[3]	����" << endl;
        cout << endl;
        cout << "[4]	�۸�" << endl;
        cout << endl;
        cout << "[5]	������" << endl;
        cout << endl;
        cout << "[6]	�������" << endl;
        cout << endl;
        cout << "[7]    ������һ������" << endl;
        cout << endl;
        cout << "�������ѯ��ʽ�� ";
        if (!check(option) /*����option������Χ*/)
        {
            err();
            continue;
        }

        switch (option)
        {
        case 1:
            cout << "��������  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input, 0);
            break;
        case 2:
            cout << "����������  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input,1);
            break;
        case 3:
            cout << "����������  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input,2);
            break;
        case 4:
            cout << "������۸�  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input,3);
            break;
        case 5:
            cout << "�����������  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input,4);
            break;
        case 6:
            cout << "���������ʱ��  ";
            if (!check(input))
            {
                err();
                return;
            }
            findSomething(input,5);
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


//***********************************************
//����������û�������


void bobbleSort(int way, int order)
{
    if (HEADP == NULL || HEADP->next == NULL)
    {
        cout << "����Ҫ���������" << endl;
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
        { //����
            while (p != HEADP->next && isChange)
            {
                books *q = HEADP;
                isChange = false; //��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
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
        { //����
            while (p != HEADP->next && isChange)
            {
                books *q = HEADP;
                isChange = false; //��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
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
        break; //ʣ�µ�����Ȳ����ֱ��ճ���ܿ��
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
    //�����ʾ
    cout << "         ����ʽ" << endl;
    cout << endl;
    cout << "[1]    ͼ����" << endl;
    cout << endl;
    cout << "[2]	����" << endl;
    cout << endl;
    cout << "[3]	����" << endl;
    cout << endl;
    cout << "[4]	�۸�" << endl;
    cout << endl;
    cout << "[5]	������" << endl;
    cout << endl;
    cout << "[6]	�������" << endl;
    cout << endl;
    cout << "[7]    ������һ������" << endl;
    cout << endl;

    int method; //���ղ�ͬ��Ԫ������
    if (!check(method))
    {
        err();
        return;
    }

    cout << " ˳��ѡ�񣺡�0������ ��1������       ";
    int order = 0; //0����1����
    if (!check(order))
    {
        err();
        return;
    }

    //ð�����򡭡���������
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

    case 7: //�˳�
        break;
    }
}
