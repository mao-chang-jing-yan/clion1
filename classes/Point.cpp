//
// Created by Xiao Shen on 2021/3/20.
//

#include "Point.h"
#include <climits>
#include <iostream>
using namespace std;

void Point::setX(int x) {
    this->x = x;
}
void Point::setY(int y) {
    this->y = y;
}
void Point::setPoint(int x, int y) {
    this->x = x;
    this->y = y;
}
int Point::getX() {
    return this->x;
}
int Point::getY() {
    return this->y;
}
int* Point::getPoint() {
    int a[2]={this->x, this->y};
    static int *p;
    p=a;
    return p;
}
Point Point::operator+(const Point &point) {
    Point a;
    a.x = this->x + point.x;
    a.y = this->y + point.y;
    return a;
}
Point Point::operator-(const Point &point) {
    Point a;
    a.x = this->x - point.x;
    a.y = this->y - point.y;
    return a;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
Point::Point() {
    this->x = 0;
    this->y = 0;
}

//Point Point::friend ostream &operator<<( ostream &output,
//                            const point &D )
//{
//    output << "x : " << point.x << " y : " << point.y;
//    return output;
//}

ostream &operator<<(ostream &output, const Point &point) {
    output << "x=" << point.x << ",y=" << point.y;
    return output;
}
