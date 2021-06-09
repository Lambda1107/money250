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

