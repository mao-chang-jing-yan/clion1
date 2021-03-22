#include <iostream>
#include <cstdio>
#include <string>
#include <deque>

using namespace std;

//
// Created by Xiao Shen on 2021/3/21.
//

#ifndef UNTITLED_GRAPHLIST_H
#define UNTITLED_GRAPHLIST_H


// 边
typedef struct Edge{
    string nextName = "";
    string parentName = "";
    string relationship = "";
    int weight = 0;
    struct Node *next;
    struct Node *parent;
}edge, *edge1;
// 点
typedef struct Node{
    string Name = "";
    int sum;
    struct deque<Edge> EdgeList;
}node, *node1;


class GraphList {
private:
    int sum;
    deque<Node> NodeList = deque<Node>();

public:
    ~GraphList();
    GraphList();

    void createGraph();
    void addNode(const string& name, const string& nextName, const string& relationship, int weight);
    void addNode(const string& name, const string& nextName, int weight);
    void printGraph();
};


#endif //UNTITLED_GRAPHLIST_H
