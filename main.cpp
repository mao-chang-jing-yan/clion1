#include <iostream>
#include <fstream>
#include <string>
#include "classes/Point.h"

using namespace std;


void fi(int *x);
int main() {
//    int x = 1,*p;
//    p = &x;
//    fi(p);
////    x = 2;
////    fi(&x);
//    int a[10][1], **pa;
////    a[0]=1;
////    *pa=&a[0][0];
//    Point P1, P2, p3(1,2);
//    P1.setPoint(1,2);
//    P2.setPoint(3,4);
//    int *p;
//    p = &P1.getPoint()[0];
//    p3 = P1 + P2;
//    p3 = p3 + P1 + P2 - P1;
//    cout << p3 << P2 << ' ' << p[0] <<' ' << P1.getPoint()[0];

    return 0;
}

void fi(int *x){
//    cout << *x;
    char data[100000];
    int a = 0;
    string temp;

    // 以读模式打开文件
    ifstream infile;
//    infile.open("../files/naruto.json");
    infile.open("../files/personrelkg.txt");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;


    while(getline(infile,temp))
    {
//        infile >> temp;
//        cout << temp << endl;
        char m[100];
        strcpy(m, temp.c_str());

        for (int i = 0; i < 100; ++i) {
//            string n(m[0:i]);
            if (m[i] == ','){

                cout << temp[i] << endl;
            }
        }
    }

    // 关闭打开的文件
    infile.close();
}
