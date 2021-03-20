#include <iostream>
#include <climits>
//
// Created by Xiao Shen on 2021/3/20.
//

using namespace std;

#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H


class Point {
private:
    int x, y;



public:
    Point();
    Point(int x, int y);


    void setX(int x);
    void setY(int y);

    int getX();
    int getY();
    void setPoint(int x, int y);

    int* getPoint();
    Point operator+(const Point& point);
    Point operator-(const Point& point);


    friend ostream &operator<<( ostream &output,
                                const Point &D );

};


#endif //UNTITLED_POINT_H
