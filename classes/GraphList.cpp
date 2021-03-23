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
    int a = 0;
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

        cout << a << " - - - " << endl;
        a++;
    }

}

void GraphList::printGraph() {
    NodeListMap *pNodeListMap = this->NodeList;
    EdgeListMap *thisNodeEdgeList, **t;
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
        t = &thisNodeEdgeList;
        if ((*t)) {
            while ((*t)->next) {
                (*t) = (*t)->next;
                cout
                        << " parent->name = "
                        << (*t)->thisEdge->parent->name
                        << " next->name = "
                        << (*t)->thisEdge->next->name
                        << " relationship = "
                        << (*t)->thisEdge->relationship
                        << " weight = "
                        << (*t)->thisEdge->weight
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
    EdgeListMap *pEdgeListMap = this->EdgeList, **t;
    auto *p = new EdgeListMap();
    t = &pEdgeListMap;
    (*t)->next = (*t)->next;
    Edge *e = new Edge();
    e->relationship = relationship;
    e->weight = weight;
    e->nextName = nextName;
    e->parentName = name;
    p->thisEdge = e;
    pEdgeListMap->next = pEdgeListMap->next;

    this->thisNodeListAdd(name);
    this->thisNodeListAdd(nextName);

    while ((*t)->next) {
        (*t) = (*t)->next;

        if (
                (*t)->thisEdge->parentName == name and
                (*t)->thisEdge->nextName == nextName and
                (*t)->thisEdge->relationship == relationship and
                (*t)->thisEdge->weight == weight
                ) {
            return;
        }
    }
    (*t)->next = p;


}

void GraphList::thisNodeListAdd(const string &name) {
    NodeListMap *pNodeListMap = this->NodeList, **t;
    auto *nodeListMap1 = new NodeListMap();
    t = &pNodeListMap;
    (*t)->next = (*t)->next;
    Node *node = new Node();
    node->thisNodeEdgeList = new EdgeListMap();
    node->name = name;
    node->sum = 0;
    nodeListMap1->thisNode = node;

    while ((*t)->next) {
        (*t) = (*t)->next;
//        try {
        if ((*t)->thisNode->name == name) {
            return;
        }
//        } catch (exception &e1){
//            cout << &e1<< e1.what() << endl;
//            return;
//        }

    }
    (*t)->next = nodeListMap1;

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
    NodeListMap **t = &pNodeListMap;
    while ((*t)->next) {
        (*t) = (*t)->next;
        if ((*t)->thisNode->name == name) {
            return (*t)->thisNode;
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
    if (node == NULL){
        return NULL;
    }

    EdgeListMap *pEdgeListMap = node->thisNodeEdgeList, **t;
    auto *thisEdgeListMap = new EdgeListMap();
    thisEdgeListMap->thisEdge = edge;

    t = &pEdgeListMap;
    (*t)->next = (*t)->next;
//    if (!pEdgeListMap or !pEdgeListMap->next) {
//        pEdgeListMap = new EdgeListMap;
//    }
    while ((*t)->next) {
        (*t) = (*t)->next;
        if ((*t) and (*t)->thisEdge == edge) {
            return (*t)->thisEdge;
        }
    }
    (*t)->next = thisEdgeListMap;
    node->sum += 1;
    return (*t)->next->thisEdge;
}


