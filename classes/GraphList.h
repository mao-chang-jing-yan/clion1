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
    string name = "";
    int sum;
    struct EdgeListMap *thisNodeEdgeList;
}node, *node1;

typedef struct NodeListMap{
    struct Node *thisNode;
    struct NodeListMap *next;
}nodeListMap;
typedef struct EdgeListMap{
    struct Edge *thisEdge;
    struct EdgeListMap *next;
}edgeListMap;

class GraphList {
private:
    int sum;
    NodeListMap *NodeList = new NodeListMap;
    EdgeListMap *EdgeList = new EdgeListMap;

public:
    ~GraphList();
    GraphList();

    Node *addNode(const string &name, const basic_string<char> basicString, const basic_string<char> string1, int i);
    Node *getNode(const string &name);
    void deleteNode(const string &name);
    Edge *addNodesEdge(Node* node, Edge* edge);
    Edge *addEdge(const string& name, const string& nextName, const string& relationship, int weight);
    Edge *addEdge(const string& name, const string& nextName);
    Edge *getEdge(const string& name, const string& nextName, const string& relationship, int weight);
    Edge *getEdge(const string& name, const string& nextName);
    void deleteEdge(const string& name, const string& nextName, const string& relationship, int weight);
    void deleteEdge(const string& name, const string& nextName);
    void thisEdgeListAdd(const string& name, const string& nextName, const string& relationship, int weight);
    void thisNodeListAdd(const string& name);

    void createGraph();
//    void addNode(const string& name, const string& nextName, const string& relationship, int weight);
//    void addNode(const string& name, const string& nextName, int weight);
    void printGraph();
    void printNodeListMap();
    void printEdgeListMap();

};


#endif //UNTITLED_GRAPHLIST_H
