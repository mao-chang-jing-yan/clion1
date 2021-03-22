#include<iostream>
#include<thread>
#include<mutex>
#include <deque>


using namespace std;
//
// Created by Xiao Shen on 2021/3/22.
//

#ifndef UNTITLED_MYTHREAD_H
#define UNTITLED_MYTHREAD_H


class MyThread: public thread{
private:
    deque<thread*> thread_list = deque<thread*>();
public:
    ~MyThread();
    MyThread();
//    MyThread(int thread_num, function<> *p, );
//    void join();



};


#endif //UNTITLED_MYTHREAD_H
