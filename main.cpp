#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include<mutex>
#include "classes/Point.h"
#include "file/File_.h"
#include "classes/GraphList.h"

#include<ctime>
int SUM = 0;
clock_t start_time,end_time;
mutex mu;

using namespace std;


void fi();
void thread_tu();
void graphList_tu();
void point_test();
void add_point(GraphList *g, const deque<deque<string>>& de);
vector<string> split(const string &str,const string &pattern);
int main() {
    start_time = clock();

//读取csv文件并输出
//    fi();
//    开启多线程，读取csv文件，构建知识图谱并输出
    thread_tu();
//    读取csv文件，构建知识图谱并输出
//    graphList_tu();
//    测试点类
//    point_test();

    end_time = clock();
    double endtime=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    cout <<endl << endl <<"Total time:"<<endtime << "s"<<endl;		//s为单位
    cout<<"Total time:"<<endtime*1000<<"ms"<<endl;	//ms为单位
//    system("pause");

    return 0;
}
void point_test(){
    Point P1, P2, p3(1,2);
    P1.setPoint(1,2);
    P2.setPoint(3,4);
    int *p;
    p = &P1.getPoint()[0];
    p3 = P1 + P2;
    p3 = p3 + P1 + P2 - P1;
    cout << p3 << P2 << ' ' << p[0] <<' ' << P1.getPoint()[0];
    string str;
    str = "qwqewe,weqw,we ,";

    vector<std::string> resultVec;
    resultVec = split(str, " ");

    cout << resultVec[0];
}
void graphList_tu(){
    File_ f("../files/personrelkg.csv");
    deque<deque<string>> a = f.read_csv();

    GraphList graphList;
    graphList.addNode("mao", "amo23", "we", 354);
    graphList.addNode("mao122", "amo23", "we", 32);
    graphList.addNode("mao122", "amo23df", "we", 32);
    graphList.addNode("mao122", "amo23ge", "we", 14324);
    graphList.addNode("mao122", "amo23222", "we", 45);
    graphList.printGraph();
}

void thread_tu(){
    File_ f("../files/personrelkg.csv");
    deque<deque<string>> a = f.read_csv();

    GraphList graphList;
    int si = a.size();
    si = 100;

    int thread_num = 30;
    deque<thread*> thread_list = deque<thread*>();
    for (int j = 0; j < thread_num; ++j) {
        int m;
        int n;
        int l = si / thread_num;
        m = j * l;
        n = m + l;
        if(j == thread_num - 1){
            n = si;
        }
//        cout << m << " - " << n << endl;

        deque<deque<string>> b;
        for (int i = m; i < n; ++i) {
            b.push_back(a[i]);
        }
        auto* t = new thread(add_point, &graphList, b);
        thread_list.push_back(t);
    }

    for (auto & k : thread_list) {
        if (k->joinable())
        {
            k->join();
            delete k;
        }
//        cout << k->get_id() << endl;
//        k->join();
    }
    thread_list.empty();
    graphList.printGraph();

}

void add_point(GraphList *g, const deque<deque<string>>& de){
    for (int i = 0; i < de.size(); ++i) {
        if(!mu.try_lock()){
            mu.lock();
        };
//        mu.lock();
        cout << SUM << " --- ";
        SUM++;

        g->addNode(de[i][3], de[i][0], de[i][2], 0);

        for (int j = 0; j < de[0].size(); ++j) {
            cout << " - " << de[i][j];
        }
        cout << endl;
        mu.unlock();
//        g->printGraph();

    };
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


void fi(){
    char data[100000];
    int a = 0;
    string temp;

    // 以读模式打开文件
    ifstream infile;
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
