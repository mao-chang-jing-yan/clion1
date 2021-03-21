#include <iostream>
#include <string>
#include <utility>
#include <fstream>

using namespace std;
//
// Created by Xiao Shen on 2021/3/20.
//

#include "File_.h"

File_::File_() {
    this->path_ = "";
    this->pattern_ = "";
}

File_::File_(string path, string pattern) {
    this->path_ = std::move(path);
    this->pattern_ = std::move(pattern);
}
File_::File_(string path) {
    this->path_ = std::move(path);
    this->pattern_ = "";
};

deque<deque<std::__1::string>> File_::read_csv() {
//    cout << this->path_ << this->pattern_;

    string temp;

    // 以读模式打开文件
    ifstream infile;
    infile.open(this->path_);

    deque<deque<string>> res =  deque<deque<string>>();
    while(getline(infile,temp))
    {
        deque<string> weee = split(temp, ",");
        res.push_back(weee);
//        for (auto & i : weee) {
//            cout << " - ";
//            cout << i;
//        }
//        cout << endl;

    }

    // 关闭打开的文件
    infile.close();
    return res;
}
deque<deque<std::__1::string>> File_::read_csv(string path, string pattern) {
    this->path_ = std::move(path);
    this->pattern_ = std::move(pattern);
    string temp;

    // 以读模式打开文件
    ifstream infile;
    infile.open(this->path_);
    deque<deque<string>> res =  deque<deque<string>>();

    while(getline(infile,temp))
    {
        deque<string> weee = split(temp, ",");
        res.push_back(weee);
//        for (auto & i : weee) {
//            cout << " - ";
//            cout << i;
//        }
//        cout << endl;

    }

    // 关闭打开的文件
    infile.close();
    return res;
}

deque<string> File_::split(const string &str,const string &pattern)
{
    //const char* convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    std::deque<std::string> resultVec;
    char* tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != nullptr)
    {
        resultVec.emplace_back(tmpStr);
        tmpStr = strtok(nullptr, pattern.c_str());
    }

    delete[] strc;

    return resultVec;
}


