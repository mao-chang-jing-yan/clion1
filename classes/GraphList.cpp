//
// Created by Xiao Shen on 2021/3/21.
//
#include <iostream>
#include <utility>
#include "GraphList.h"
using namespace std;


GraphList::GraphList() {
    this->sum = 0;
    this->NodeList = deque<Node>();
}

GraphList::~GraphList() {
    for (int i = 0; i < sum; ++i){
        Node tmp = NodeList[i];

        for (int j = 0; j < tmp.sum; ++j) {
            tmp.EdgeList.clear();
        }
        NodeList.clear();
    }
}

void GraphList::createGraph() {

}

void GraphList::printGraph() {
    for (auto & i : this->NodeList) {
        if (1 == 1){

        cout << "node - " << i.Name << " " <<i.sum <<endl;
            for (auto & j : i.EdgeList) {
                cout
                << "parentName : "
                << j.parent->Name
                << " nextName : "
                << j.next->Name
                << " relationship : "
                << j.relationship
                << " weight : "
                << j.weight
                << " parent->sum : "
                << j.parent->sum
//                << "  -  "
//                << &i
//                << "  "
//                << &j.parent
//                << "  "
//                << (&i == &j.parent)
                << endl;
            }
        }

    }


}

void GraphList::addNode(const string& name, const string& nextName,const string& relationship, int weight) {
    auto *node = new Node();
    auto *nextNode = new Node();
    auto *edge1 = new Edge();
    node->Name = name;
//    node->sum = 1;
    nextNode->Name = nextName;
    nextNode->sum = 0;
    edge1->nextName = nextName;
    edge1->parentName = name;
    edge1->weight = weight;
    edge1->parent = node;
    edge1->next = nextNode;
    edge1->relationship = relationship;

    int flag[] = {0, 0, 0, 0};
    for (auto & i : this->NodeList) {
        for (auto & j : i.EdgeList) {
            if(i.Name == name){
                flag[0] = 1;
            }
            if(j.next->Name == nextName){
                flag[1] = 1;
            }
            if(j.relationship == relationship){
                flag[2] = 1;
            }
            if(j.weight == weight){
                flag[3] = 1;
            }
        }

        if(i.EdgeList.size()>1){
            i.EdgeList[0].parent = &i;
        }


    }

    if(flag[0] == 1 and flag[1] == 1){
        delete node;
        delete edge1;
        delete nextNode;
        return;
    }
//    for (auto & i : this->NodeList) {
//        cout << flag[0] << "  " <<flag[1] <<"  "<< i.Name  << "  " << name <<endl;
//    }
    if(flag[0] == 0 and flag[1] == 0){
        node->EdgeList.push_back(*edge1);
        node->sum = node->EdgeList.size();
        this->NodeList.push_back(*node);
        this->NodeList.push_back(*nextNode);
        this->sum = this->NodeList.size();
        return;
    }
    if(flag[0] == 1 and flag[1] == 0){
        for (auto & i : this->NodeList) {
            if (i.Name == name){
                edge1->parentName = i.Name;
                edge1->parent = &i;
                i.EdgeList.push_back(*edge1);
                i.sum = i.EdgeList.size();
                this->NodeList.push_back(*nextNode);
                this->sum = this->NodeList.size();
                return;
            }
        }
    }
    if(flag[0] == 0 and flag[1] == 1){
        for (auto & i : this->NodeList) {
            if (i.Name == nextName){
                edge1->next = &i;
                edge1->nextName = i.Name;
                edge1->parent->sum = 1;
                node->EdgeList.push_back(*edge1);
//                node->sum = 1;
                this->NodeList.push_back(*node);
                this->sum = this->NodeList.size();
                return;
            }
        }
    }


}

void GraphList::addNode(const string &name, const string &nextName, int weight) {

}


