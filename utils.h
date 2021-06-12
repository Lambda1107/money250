#pragma once
//�����
#include<iostream>
#include"Book.h"
#include"main.h"
using namespace std;

//ȫ�ִ���
void err()
{
    cout << "�������������������룡" << endl;
}

//����������
template<typename T>
bool check(T& pos)
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

//��posλ��
bool findPos(int pos, books* pBooks) {
    for (int i = 0; i < pos; i++) {
        if (!pBooks) {
            err();
            return false;
        }
        pBooks = pBooks->next;
    }
    return true;
}

//�û�����ͼ����Ϣ
bool inputBookInfo(books* tmpBooks) {
    cout << "ͼ���ţ� ";
    if (!check(tmpBooks->data.num)) {
        return false;
    }
    if (!check(tmpBooks->data.name)) {
        return false;
    }
    if (!check(tmpBooks->data.author)) {
        return false;
    }
    if (!check(tmpBooks->data.price)) {
        return false;
    }
    if (!check(tmpBooks->data.press)) {
        return false;
    }
    if (!check(tmpBooks->data.pressYear)) {
        return false;
    }
    return true;
}

//�������������Ϣ
template<typename T>
bool findSomething(T input, int way) {
    books* p = HEADP;
    if (!p) {
        cout << "ͼ������Ϊ��" << endl;
    }

    bool if_find = false;

    switch (way)
    {
    case 1:
        while (p) {
            if (p->data.num == input) {
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 2:
        while (p) {
            if (strcmp(p->data.name, input)) {
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 3:
        while (p) {
            if (strcmp(p->data.author, input)) {
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 4:
        while (p) {
            if (p->data.price == input) {
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 5:
        while (p) {
            if (strcmp(p->data.press, input)) {
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 6:
        while (p) {
            if (p->data.pressYear == input) {
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 7:
        break;
    default:
        err();
        break;
    }

    if (!if_find)
    {
        cout << "δ��ѯ�������Ϣ" << endl;
    }
    return if_find;
}

//�����ð�ݺ���
void bobbleSort(int way, int order) {
    if (HEADP == NULL || HEADP->next == NULL) {
        cout << "����Ҫ���������" << endl;
        return;
    }
    books* p = NULL;
    bool isChange = true;

    int op;
    if (!(check(op))) {
        err();
        return;
    }

    switch (way)
    {
    case 1:
        if (!order) {//����
            while (p != HEADP->next && isChange)
            {
                books* q = HEADP;
                isChange = false;//��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
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
        else {//����
            while (p != HEADP->next && isChange)
            {
                books* q = HEADP;
                isChange = false;//��־��ǰ��һ������û�з���Ԫ�ؽ��������û�����ʾ�����Ѿ�����
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
        break;//ʣ�µ�����Ȳ����ֱ��ճ���ܿ��
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