#include <iostream>
#include <string>
using namespace std;
//
// Created by Xiao Shen on 2021/3/22.
//

#ifndef UNTITLED_LI_H
#define UNTITLED_LI_H

struct l{
    string name;
    struct l *next;
};
class Li {
private:
    struct l *list;
public:
    Li();
    void add_li(const string& name);
    void delete_li(const string& name);
    void delete_i(const l *i);
    void print_li();
};


#endif //UNTITLED_LI_H
