#pragma once
//组件库
#include<iostream>
using namespace std;

//全局错误
void err()
{
    cout << "输入内容有误！请检查输入！" << endl;
}

//各种输入检查
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

//找pos位置
bool findPos(int pos, books *pBooks){
    for(int i=0;i<pos;i++){
        if(!pBooks){
            err();
            return false;
        }
        pBooks = pBooks->next;
    }
    return true;
}

//用户输入图书信息
bool inputBookInfo(books *tmpBooks){
    cout << "图书编号： ";
    if (!check(tmpBooks->data.num)){
        return false;
    }
    if (!check(tmpBooks->data.name)){
        return false;
    }
    if (!check(tmpBooks->data.author)){
        return false;
    }
    if (!check(tmpBooks->data.price)){
        return false;
    }
    if (!check(tmpBooks->data.press)){
        return false;
    }
    if (!check(tmpBooks->data.pressYear)){
        return false;
    }
    return true;
}

//遍历链表查找信息
template<typename T>
bool findSomething(T input, int way){
    books* p = HEADP;
    if (!p){
        cout << "图书数据为空" << endl;
    }

    bool if_find = false;

    switch (way)
    {
    case 1: 
        while (p){
            if(p->data.num==input){
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 2: 
        while (p){
            if(strcmp(p->data.name,input)){
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 3: 
        while (p){
            if(strcmp(p->data.author,input)){
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 4: 
        while (p){
                if(p->data.price==input){
                    p->data.printInformation();
                    if_find = true;
                }
            }
        break;
    case 5: 
        while (p){
            if(strcmp(p->data.press,input)){
                p->data.printInformation();
                if_find = true;
            }
        }
        break;
    case 6: 
        while (p){
            if(p->data.pressYear==input){
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
        cout << "未查询到相关信息" << endl;
    }
}

//链表的冒泡函数
template<typename T>
books* bobbleSort(){

}