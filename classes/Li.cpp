//
// Created by Xiao Shen on 2021/3/22.
//
#include <iostream>
#include "Li.h"

using namespace std;

void Li::add_li(const string &name) {
    l *L = new l(), *pNode = this->list;

    L->name = name;

    while (pNode->next) {
        pNode = pNode->next;
    }

    if (!pNode->next) {
        pNode->next = L;
    }

}

void Li::delete_li(const string &name) {
    l *L = new l(), *p, *pNode = this->list;

    L->name = name;
    while (pNode->next) {
        if (pNode->name == name) {
            delete_i(pNode);
        }
        pNode = pNode->next;
    }

    if (pNode->name == name) {
        delete_i(pNode);
    }
}

void Li::print_li() {
    l *pNode = this->list;
    while (pNode->next) {
        pNode = pNode->next;
        cout << pNode->name << endl;
    }


}

void Li::delete_i(const l *i) {
    l *L = new l(), *p, *pNode = this->list;
    while (pNode->next and pNode->next->next) {
        if (pNode->next == i) {
            p = pNode->next;
            pNode->next = pNode->next->next;
            delete p;
            p = nullptr;
        }
        pNode = pNode->next;
    }
    if (pNode->next == i) {
        delete pNode->next;
        pNode->next = nullptr;
    }
}

Li::Li() {

}
