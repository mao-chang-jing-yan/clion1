#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread>
#include<mutex>
#include "classes/Point.h"
#include "file/File_.h"
#include "classes/GraphList.h"
#include "classes/Li.h"


#include<ctime>
int SUM = 0;
clock_t start_time,end_time;
mutex mu;

using namespace std;


void fi();
void Li_test();
void gra_test();
void thread_tu();
void add_point(GraphList *g, const deque<deque<string>>& de);
vector<string> split(const string &str,const string &pattern);
int main() {
    start_time = clock();
//    gra_test();
//读取csv文件并输出
    fi();
//    开启多线程，读取csv文件，构建知识图谱并输出
//    thread_tu();
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
void gra_test(){
    GraphList graphList;
    graphList.thisEdgeListAdd("12", "12", "12", 1);
    graphList.thisEdgeListAdd("123", "12", "12", 1);
    graphList.thisEdgeListAdd("123", "12", "12", 1);
    graphList.thisEdgeListAdd("123", "12", "12", 1);
    graphList.thisEdgeListAdd("12gy3", "12", "12", 1);
    graphList.thisEdgeListAdd("12", "12", "12", 1);
    graphList.thisEdgeListAdd("13", "jkj", "12", 1);
    graphList.thisEdgeListAdd("1ew23", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123we", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12ww3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12wqe3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12we3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12wqe3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12wqe3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12wqe3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12wqe3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123wqe", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123wqe", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123we", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
    graphList.thisEdgeListAdd("12rwer3", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123vxc", "jcxbkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkvfdvfj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkfsvdj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkjds", "12", 1);
    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkdsfj", "12", 1);
    graphList.thisEdgeListAdd("123", "jkdfj", "12", 1);
    graphList.thisEdgeListAdd("123", "12ds", "12", 1);
    graphList.thisEdgeListAdd("123", "uuh", "12", 1);
//    graphList.addNode("232");
//    graphList.printEdgeListMap();
//    graphList.printNodeListMap();
    graphList.createGraph();
    graphList.printGraph();



}

void thread_tu(){
    File_ f("../files/personrelkg.csv");
    deque<deque<string>> a = f.read_csv();

    GraphList graphList;
    int si = a.size();
    cout << si << endl;
    si = 100;

    int thread_num = 3;
    deque<thread*> thread_list = deque<thread*>();
    deque<deque<string>> b = deque<deque<string>>();
    for (int j = 0; j < thread_num; ++j) {
        int m;
        int n;
        int l = si / thread_num;
        m = j * l;
        n = m + l;
        if(j == thread_num - 1){
            n = si;
        }
        cout << m << " - " << n << endl;

        b.empty();
        for (int i = m; i < n; ++i) {
            b.push_back(a[i]);
        }
        auto* t = new thread(add_point, &graphList, b);
        t->join();
//        delete t;
//        thread_list.push_back(t);
    }

//    for (auto & k : thread_list) {
//        if (k->joinable())
//        {
//            k->join();
//            delete k;
//        }
////        cout << k->get_id() << endl;
////        k->join();
//    }
//    thread_list.empty();
    graphList.printGraph();

}
void add_point(GraphList *g, const deque<deque<string>>& de){
    for (int i = 0; i < de.size(); ++i) {
//        if(!mu.try_lock()){
//            mu.lock();
//        };
//        mu.lock();
        cout << SUM << " --- ";
        SUM++;

        g->thisEdgeListAdd(de[i][3], de[i][0], de[i][2], 0);

        for (int j = 0; j < de[0].size(); ++j) {
            cout << " - " << de[i][j];
        }
        cout << endl;
        mu.native_handle();
//        mu.unlock();
//        g->printGraph();

    };
}


void Li_test(){
    Li c;
    c.add_li("1");
    c.add_li("1");
    c.add_li("2");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("3253234");
    c.add_li("1");
    c.add_li("1");
    c.add_li("435345");
    c.add_li("1");
    c.add_li("43");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");
    c.add_li("1");

    c.print_li();

    cout<<" ====== " <<endl;
    c.delete_li("2");
//    c.delete_li("5");
    c.delete_li("43");
    c.print_li();
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
//    infile >> data;
//
//    // 在屏幕上写入数据
//    cout << data << endl;
//
//    // 再次从文件读取数据，并显示它
//    infile >> data;
//    cout << data << endl;

//
    GraphList graphList;
//    graphList.thisEdgeListAdd("12", "12", "12", 1);
//    graphList.thisEdgeListAdd("123", "12", "12", 1);
//    graphList.thisEdgeListAdd("123", "12", "12", 1);
//    graphList.thisEdgeListAdd("123", "12", "12", 1);
//    graphList.thisEdgeListAdd("12gy3", "12", "12", 1);
//    graphList.thisEdgeListAdd("123", "12", "12", 1);
//    graphList.thisEdgeListAdd("123", "jkj", "12", 1);
//    graphList.thisEdgeListAdd("123", "12", "12", 1);
//    graphList.thisEdgeListAdd("123", "uuh", "12", 1);
////    graphList.addNode("232");
////    graphList.printEdgeListMap();
////    graphList.printNodeListMap();
//    graphList.createGraph();
//    graphList.printGraph();

    string A = "",B = "",C = "";
    while(getline(infile,temp))
    {
        if (a>21000){
            break;
        }
        a++;
        cout << a;
        int k=0;
        vector<string> weee = split(temp, ",");
        for (auto & i : weee) {
            cout << " - ";
            cout << i;
            if (k == 0){
                B = i;
            }
            if (k == 3){
                A = i;
            }
            if (k == 1){
                C = i;
            }

            k++;
        }
        graphList.thisEdgeListAdd(A, B, C, 1);
        cout << endl;

    }
    cout << 10 << endl;
    // 关闭打开的文件
    infile.close();
    graphList.createGraph();
    graphList.printGraph();
}
