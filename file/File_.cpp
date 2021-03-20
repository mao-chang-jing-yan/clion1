#include <iostream>
#include <string>
#include <utility>
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

void File_::read_csv() {
    cout << this->path_ << this->pattern_;
}
void File_::read_csv(string path, string pattern) {
    this->path_ = std::move(path);
    this->pattern_ = std::move(pattern);
    cout << this->path_ << this->pattern_;
}
