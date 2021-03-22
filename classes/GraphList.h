#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <vector>

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
    struct Edge *nextParentEdge;
    struct Edge *nextNextEdge;
}edge, *edge1;
// 点
typedef struct Node{
    string name = "";
    int sum;
    struct Edge *edge;
}node, *node1;

struct Map{
//    struct Map *this_;
    struct Map *next;
    struct Map *parent;
    struct Node *node;
};

class GraphList {
private:
//    int sum;
    Map *NodeList;

public:
    ~GraphList();
    GraphList();

    void createGraph();
    void addNode(const string& name, const string& nextName, const string& relationship, int weight);
    void addNode(const string& name, const string& nextName, int weight);

    Node *searchNode(const string& name);
    Map *searchMap(const string& name);
    edge *searchParentEdge(const Node* search_node, const string& relationship);
    edge *searchNextEdge(const Node* search_node, const string& relationship);
    void printGraph();
};


#endif //UNTITLED_GRAPHLIST_H
