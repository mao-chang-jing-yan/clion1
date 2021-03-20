#include <iostream>
#include <string>
#include <climits>

using namespace std;
//
// Created by Xiao Shen on 2021/3/20.
//

#ifndef UNTITLED__FILE_H
#define UNTITLED__FILE_H

class File_{
private:
    string path_, pattern_;
public:
    File_();
    File_(string path, string pattern);
    void read_csv(string path, string pattern);
    void read_csv();
};


#endif //UNTITLED__FILE_H
