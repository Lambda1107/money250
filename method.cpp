#include <fstream>
#include "utils.h"
#include "main.h"
#include"Book.h"
using namespace std;

void init() //��������
{
    fstream fin("database", ios::binary | ios::in);
    HEADP = new books;
    books* pbooks = HEADP;
    books* pbooks1 = pbooks;
    while (!fin.eof())
    {
        pbooks1 = pbooks;
        fin.read((char*)(&pbooks->data), sizeof(Book));
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
    cout << "         ͼ�����" << endl; puts("");
    cout << "[1]    ��ʾͼ������" << endl; puts("");
    cout << "[2]	����ͼ������" << endl; puts("");
    cout << "[3]	ɾ��ͼ������" << endl; puts("");
    cout << "[4]	�޸�ͼ������" << endl; puts("");
    cout << "[5]	���ݲ�ѯ" << endl; puts("");
    cout << "[6]	��������" << endl; puts("");
    cout << "[7]    �˳�����" << endl; puts("");
}

void listBooks() {
    //���������ӡ��Ϣ
    books* p = HEADP;
    if (!p) {
        cout << "ͼ������Ϊ��" << endl;
    }

    while (p) {
        p->data.printInformation();
    }
}

void insertBook()
{
    int pos;
    cout << "������Ҫ���뵽��λ�ã� ";
    if (!check(pos)) {
        err();
        return;
    }

    books* dummuHead = new books;
    dummuHead->next = HEADP;
    books* pBooks = dummuHead;

    if (!findPos(pos, pBooks)) {
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
    cout << "������Ҫɾ����λ�ã� ";
    if (!check(pos)) {
        err();
        return;
    }

    books* dummuHead = new books;
    dummuHead->next = HEADP;
    books* pBooks = dummuHead;

    if (!findPos(pos - 1, pBooks)) {
        //��Ҫɾ�������ǰһ�����
        return;
    }

    if (!pBooks->next) {
        err();
        return;
    }

    books* ptmp = pBooks->next;
    pBooks->next = pBooks->next->next;
    delete ptmp;

    HEADP = dummuHead->next;
    delete dummuHead;
}

void modifyBook()
{
    int pos;
    cout << "������Ҫ�޸ĵ�λ�ã� ";
    if (!check(pos)) {
        err();
        return;
    }

    books* dummuHead = new books;
    dummuHead->next = HEADP;
    books* pBooks = dummuHead;

    if (!findPos(pos, pBooks)) {
        return;
    }

    inputBookInfo(pBooks);

    HEADP = dummuHead->next;
    delete dummuHead;
}

void findBook()
{
    //�����ʾ
    cout << "         ͼ���ѯ��ʽ" << endl; puts("");
    cout << "[1]    ͼ����" << endl; puts("");
    cout << "[2]	����" << endl; puts("");
    cout << "[3]	����" << endl; puts("");
    cout << "[4]	�۸�" << endl; puts("");
    cout << "[5]	������" << endl; puts("");
    cout << "[6]	�������" << endl; puts("");
    cout << "[7]    ������һ������" << endl; puts("");
    //�ж�����

    int input1 = 0;
    char input2[50];
    double input3 = 0;

    int option = 0;
    do
    {
        printInterface();
        if (!check(option) /*����option������Χ*/)
        {
            err();
            option = QUIT;
        }
        switch (option)
        {
        case 1:
            if (!check(input1)) {
                err();
                return;
            }
            findSomething1(input1);
            break;
        case 2:
            if (!check(input2)) {
                err();
                return;
            }
            findSomething2(input2);
            break;
        case 3:
            if (!check(input2)) {
                err();
                return;
            }
            findSomething3(input2);
            break;
        case 4:
            if (!check(input3)) {
                err();
                return;
            }
            findSomething4(input3);
            break;
        case 5:
            if (!check(input2)) {
                err();
                return;
            }
            findSomething5(input2);
            break;
        case 6:
            if (!check(input1)) {
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

void sortBook()
{
    //�����ʾ
    cout << "         ����ʽ" << endl; puts("");
    cout << "[1]    ͼ����" << endl; puts("");
    cout << "[2]	����" << endl; puts("");
    cout << "[3]	����" << endl; puts("");
    cout << "[4]	�۸�" << endl; puts("");
    cout << "[5]	������" << endl; puts("");
    cout << "[6]	�������" << endl; puts("");
    cout << "[7]    ������һ������" << endl; puts("");

    int method;     //���ղ�ͬ��Ԫ������
    if (!check(method)) {
        err();
        return;
    }

    cout << " ˳��ѡ�񣺡�0������ ��1������       ";
    int order = 0; //0����1����
    if (!check(order)) {
        err();
        return;
    }

    //ð�����򡭡���������
    books* pBooks1;
    books* pBooks2;
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

void store()
{
    //��loadһ���ģ������ƴ淨
    fstream fout("database", ios::binary | ios::out);
    books* pbooks = HEADP;
    while (pbooks) {
        fout.write((char*)(&pbooks->data), sizeof(Book));
        pbooks = pbooks->next;
    }
    delete pbooks;
    fout.close();
}