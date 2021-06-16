//С���
#include <iostream>
#include <fstream>
#include "utils.h"
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include "Book.h"
using namespace std;

void init() //��������,�Ӷ������ļ��ж���
{
    HEADP = nullptr; //û���ݵĻ�������return�Ǹ���ָ��
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
    } //�����ļ�β�˾��˳�
    delete pbooks;
    pbooks1->next = NULL;
    fin.close();
}

void printInterface()
{
    system("cls");
    cout << "         ͼ�����" << endl;
    cout << endl;
    cout << "[1]    ��ʾͼ������" << endl;
    cout << endl;
    cout << "[2]	����ͼ������" << endl;
    cout << endl;
    cout << "[3]	ɾ��ͼ������" << endl;
    cout << endl;
    cout << "[4]	�޸�ͼ������" << endl;
    cout << endl;
    cout << "[5]	���ݲ�ѯ" << endl;
    cout << endl;
    cout << "[6]	��������" << endl;
    cout << endl;
    cout << "[7]    ���ݱ���" << endl;
    cout << endl;
    cout << "[8]    �˳�����" << endl;
    cout << endl;
}

void err()
{
    cout << "�������������������룡" << endl;
}

bool findPos(int pos, books *&pBooks)
{
    for (int i = 0; i < pos; i++)
    {
        if (!pBooks)
        {
            err();
            return false;
        }
        //cout << "go next" << endl; //����dbug
        pBooks = pBooks->next;
    }
    return true;
}

void findSomething(char input[50], int way)
{
    books *p = HEADP;
    if (!p)
    {
        cout << "ͼ������Ϊ��" << endl;
    }

    bool if_find = false;
    while (p)
    {
        if (strcmp(p->data.info[way], input) == 0)
        {
            if (!if_find)
            {
                cout << setw(10) << "�鼮���"
                     << setw(10) << "����"
                     << setw(10) << "����"
                     << setw(10) << "�۸�"
                     << setw(10) << "������"
                     << setw(10) << "�������" << endl;
            }
            p->data.printInformation();
            if_find = true;
        }
        p = p->next;
    }

    if (!if_find)
    {
        cout << "δ��ѯ�������Ϣ" << endl;
    }
}

bool inputBookInfo(books *tmpBooks)
{
    cout << "ͼ���ţ� ";
    if (!check(tmpBooks->data.num))
    {
        return false;
    }
    cout << "ͼ�����ƣ� ";
    if (!check(tmpBooks->data.name))
    {
        return false;
    }
    cout << "���ߣ� ";
    if (!check(tmpBooks->data.author))
    {
        return false;
    }
    cout << "�۸� ";
    if (!check(tmpBooks->data.price))
    {
        return false;
    }
    cout << "�����磺 ";
    if (!check(tmpBooks->data.press))
    {
        return false;
    }
    cout << "������ݣ� ";
    if (!check(tmpBooks->data.pressYear))
    {
        return false;
    }

    sprintf(tmpBooks->data.info[0], "%d", tmpBooks->data.num);
    strcpy(tmpBooks->data.info[1], tmpBooks->data.name);
    strcpy(tmpBooks->data.info[2], tmpBooks->data.author);
    sprintf(tmpBooks->data.info[3], "%lf", tmpBooks->data.price);
    strcpy(tmpBooks->data.info[4], tmpBooks->data.press);
    sprintf(tmpBooks->data.info[5], "%d", tmpBooks->data.pressYear);

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
    //��loadһ���ģ������ƴ淨
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

void bobbleSort(books *head, int way, int order)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "����Ҫ���������" << endl;
        return;
    }
    books *p = head;
    bool j = 1;
    while (j)
    {
        j = 0;
        while (p->next)
        {
            bool b; //����
            bool t;
            switch (way)
            {
            case 1:
                b = p->data.num > p->next->data.num;
                t = p->data.num == p->next->data.num;
                break;
            case 2:

                b = strcmp(p->data.name, p->next->data.name) > 0;
                t = p->data.name == p->next->data.name;
                break;
            case 3:
                b = strcmp(p->data.author, p->next->data.author) > 0;
                t = p->data.author == p->next->data.author;
                break;
            case 4:
                b = p->data.price > p->next->data.price;
                t = p->data.price == p->next->data.price;
                break;
            case 5:
                b = strcmp(p->data.press, p->next->data.press) > 0;
                t = p->data.press == p->next->data.press;
                break;
            case 6:
                b = p->data.pressYear > p->next->data.pressYear;
                t = p->data.pressYear == p->next->data.pressYear;
                break;
            default:
                break;
            }

            if (order == 1) //��Ϊ����
                b = !b;

            if (b && !t)
            {
                j = 1;
                swap(p->data, p->next->data);
            }
            p = p->next;
        }
        p = head;
    }
}