//
// Created by Xiao Shen on 2021/3/21.
//
#include <iostream>
#include <utility>
#include "GraphList.h"

using namespace std;


GraphList::GraphList() {

}

GraphList::~GraphList() {

}

void GraphList::createGraph() {
    EdgeListMap *pEdgeListMap = this->EdgeList;
    NodeListMap *pNodeListMap = this->NodeList;
    Node *parentNode, *nextNode;
    Edge *thisEdge;
    while (pEdgeListMap->next) {
        pEdgeListMap = pEdgeListMap->next;

        thisEdge = pEdgeListMap->thisEdge;
        parentNode = getNode(pEdgeListMap->thisEdge->parentName);
        nextNode = getNode(pEdgeListMap->thisEdge->nextName);
        thisEdge->next = nextNode;
        thisEdge->parent = parentNode;
        addNodesEdge(parentNode, thisEdge);
        addNodesEdge(nextNode, thisEdge);
    }

}

void GraphList::printGraph() {
    NodeListMap *pNodeListMap = this->NodeList;
    EdgeListMap *thisNodeEdgeList;
    while (pNodeListMap->next) {
        pNodeListMap = pNodeListMap->next;
        cout
                << "NodeListMap - "
                << " name="
                << pNodeListMap->thisNode->name
                << " sum="
                << pNodeListMap->thisNode->sum
                << endl;
        thisNodeEdgeList = pNodeListMap->thisNode->thisNodeEdgeList;
        if (thisNodeEdgeList){
            while (thisNodeEdgeList->next) {
                thisNodeEdgeList = thisNodeEdgeList->next;
                cout
                        << " parent->name = "
                        << thisNodeEdgeList->thisEdge->parent->name
                        << " next->name = "
                        << thisNodeEdgeList->thisEdge->next->name
                        << " relationship = "
                        << thisNodeEdgeList->thisEdge->relationship
                        << " weight = "
                        << thisNodeEdgeList->thisEdge->weight
                        << endl;
            }
        }

    }
}


Node *GraphList::addNode(const string &name, const basic_string<char> basicString, const basic_string<char> string1,
                         int i) {
    return nullptr;
}

void GraphList::deleteNode(const string &name) {

}

Edge *GraphList::addEdge(const string &name, const string &nextName, const string &relationship, int weight) {
    return nullptr;
}

Edge *GraphList::addEdge(const string &name, const string &nextName) {
    return nullptr;
}

void GraphList::deleteEdge(const string &name, const string &nextName, const string &relationship, int weight) {

}

void GraphList::deleteEdge(const string &name, const string &nextName) {

}

void GraphList::thisEdgeListAdd(const string &name, const string &nextName, const string &relationship, int weight) {
    EdgeListMap *pEdgeListMap = this->EdgeList;
    auto *p = new EdgeListMap();
    Edge *e = new Edge();
    e->relationship = relationship;
    e->weight = weight;
    e->nextName = nextName;
    e->parentName = name;
    p->thisEdge = e;

    this->thisNodeListAdd(name);
    this->thisNodeListAdd(nextName);

    while (pEdgeListMap->next) {
        pEdgeListMap = pEdgeListMap->next;
        if (
                pEdgeListMap->thisEdge->parentName == name and
                pEdgeListMap->thisEdge->nextName == nextName and
                pEdgeListMap->thisEdge->relationship == relationship and
                pEdgeListMap->thisEdge->weight == weight
                ) {
            return;
        }
    }
    pEdgeListMap->next = p;


}

void GraphList::thisNodeListAdd(const string &name) {
    NodeListMap *pNodeListMap = this->NodeList;
    auto *nodeListMap1 = new NodeListMap();
    Node *node = new Node();
    node->thisNodeEdgeList = new EdgeListMap();
    node->name = name;
    node->sum = 0;
    nodeListMap1->thisNode = node;

    while (pNodeListMap->next) {
        pNodeListMap = pNodeListMap->next;
        if (pNodeListMap->thisNode and pNodeListMap->thisNode->name == name) {
            return;
        }
    }
    pNodeListMap->next = nodeListMap1;
}

void GraphList::printNodeListMap() {
    NodeListMap *pNodeListMap = this->NodeList;
    while (pNodeListMap->next) {
        pNodeListMap = pNodeListMap->next;
        cout
                << "NodeListMap - "
                << " name="
                << pNodeListMap->thisNode->name
                << " sum="
                << pNodeListMap->thisNode->sum
                << endl;
    }
}

void GraphList::printEdgeListMap() {
    EdgeListMap *pEdgeListMap = this->EdgeList;
    while (pEdgeListMap->next) {
        pEdgeListMap = pEdgeListMap->next;
        cout
                << "EdgeListMap - "
                << " parentName="
                << pEdgeListMap->thisEdge->parentName
                << " nextName="
                << pEdgeListMap->thisEdge->nextName
                << " relationship="
                << pEdgeListMap->thisEdge->relationship
                << " weight="
                << pEdgeListMap->thisEdge->weight
                << endl;
    }
}

Node *GraphList::getNode(const string &name) {
    NodeListMap *pNodeListMap = this->NodeList;
    while (pNodeListMap->next) {
        pNodeListMap = pNodeListMap->next;
        if (pNodeListMap->thisNode->name == name) {
            return pNodeListMap->thisNode;
        }
    }
    return nullptr;
}

Edge *GraphList::getEdge(const string &name, const string &nextName, const string &relationship, int weight) {
    EdgeListMap *pEdgeListMap = this->EdgeList;
    while (pEdgeListMap->next) {
        pEdgeListMap = pEdgeListMap->next;
        if (
                pEdgeListMap->thisEdge->parentName == name and
                pEdgeListMap->thisEdge->nextName == nextName and
                pEdgeListMap->thisEdge->relationship == relationship and
                pEdgeListMap->thisEdge->weight == weight
                ) {
            return pEdgeListMap->thisEdge;
        }
    }

    return nullptr;
}

Edge *GraphList::getEdge(const string &name, const string &nextName) {
    EdgeListMap *pEdgeListMap = this->EdgeList;
    while (pEdgeListMap->next) {
        pEdgeListMap = pEdgeListMap->next;
        if (
                pEdgeListMap->thisEdge->parentName == name and
                pEdgeListMap->thisEdge->nextName == nextName
                ) {
            return pEdgeListMap->thisEdge;
        }
    }
    return nullptr;
}

Edge *GraphList::addNodesEdge(Node *node, Edge *edge) {
    EdgeListMap *pEdgeListMap = node->thisNodeEdgeList;
    auto *thisEdgeListMap = new EdgeListMap;
    thisEdgeListMap->thisEdge = edge;
//    if (!pEdgeListMap or !pEdgeListMap->next) {
//        pEdgeListMap = new EdgeListMap;
//    }
    while (pEdgeListMap->next) {
        pEdgeListMap = pEdgeListMap->next;
        if (pEdgeListMap->thisEdge == edge) {
            return pEdgeListMap->thisEdge;
        }
    }
    pEdgeListMap->next = thisEdgeListMap;
    node->sum += 1;
    return pEdgeListMap->next->thisEdge;
}


