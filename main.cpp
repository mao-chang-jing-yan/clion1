#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "classes/Point.h"
#include "file/File_.h"


using namespace std;


void fi(int *x);
vector<string> split(const string &str,const string &pattern);
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
//    string str;
//    str = "qwqewe,weqw,we ,";
//
//    vector<std::string> resultVec;
//    resultVec = split(str, " ");
//
//    cout << resultVec[0];

    File_ f;
    f.read_csv("213", "21");
    f.read_csv();


    return 0;
}

vector<string> split(const string &str,const string &pattern)
{
    //const char* convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    std::vector<std::string> resultVec;
    char* tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != NULL)
    {
        resultVec.emplace_back(tmpStr);
        tmpStr = strtok(NULL, pattern.c_str());
    }

    delete[] strc;

    return resultVec;
};


void fi(int *x){
//    cout << *x;
    char data[100000];
    int a = 0;
    string temp;

    // 以读模式打开文件
    ifstream infile;
//    infile.open("../files/naruto.json");
    infile.open("../files/personrelkg.csv");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;


    while(getline(infile,temp))
    {
        a++;
        cout << a;
        vector<string> weee = split(temp, ",");
        for (auto & i : weee) {
            cout << " - ";
            cout << i;
        }
        cout << endl;

    }

    // 关闭打开的文件
    infile.close();
}
