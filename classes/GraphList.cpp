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

}

void GraphList::printGraph() {

    Map* pMap=this->NodeList;
    if(pMap==NULL)
        return ;
    else
    {
        cout << "node - " <<pMap->node->name <<endl;
        Edge *pEdge = pMap->node->edge;
        cout
        << " parentName - "
        << pEdge->parentName
        << " nextName - "
        << pEdge->nextName
        << " relationship - "
        << pEdge->relationship
        << " weight - "
        << pEdge->weight
        << endl;

        while (pEdge->nextNextEdge!=NULL)
        {
            pEdge = pEdge->nextNextEdge;
            cout
                    << " parentName - "
                    << pEdge->parentName
                    << " nextName - "
                    << pEdge->nextName
                    << " relationship - "
                    << pEdge->relationship
                    << " weight - "
                    << pEdge->weight
                    << endl;
        }


        while(pMap->next!=NULL)
        {
            pMap = pMap->next;
            pEdge = pMap->node->edge;
            cout
                    << " parentName - "
                    << pEdge->parentName
                    << " nextName - "
                    << pEdge->nextName
                    << " relationship - "
                    << pEdge->relationship
                    << " weight - "
                    << pEdge->weight
                    << endl;

            while (pEdge->nextNextEdge!=NULL)
            {
                pEdge = pEdge->nextNextEdge;
                cout
                        << " parentName - "
                        << pEdge->parentName
                        << " nextName - "
                        << pEdge->nextName
                        << " relationship - "
                        << pEdge->relationship
                        << " weight - "
                        << pEdge->weight
                        << endl;
            }
        }
    }

}

void GraphList::addNode(const string& name, const string& nextName,const string& relationship, int weight) {
    Node *node = new Node();
    Edge *edge = new Edge();
    Map *map = new Map();
    Map *this_map = this->searchMap(name);
    Map *next_map = this->searchMap(nextName);
    Edge *this_edge = this->searchParentEdge(this_map->node, relationship);
    Edge *next_edge = this->searchNextEdge(next_map->node, relationship);

    edge->parentName = name;
    edge->nextName = name;
    edge->parent = node;
    edge->relationship = relationship;
    edge->weight = weight;

    node->name = name;
    node->sum = 1;
    node->edge = edge;

    map->node = node;

    Map* pMap=this->NodeList;
    if (pMap==NULL){
        pMap = map;
        pMap->node = node;
    } else{
        int a[] = {0,0,0,0};
        if (this_map){
            a[0] = 1;
        }
        if (next_map){
            a[1] = 1;
        }
        if (a[0]==0 and a[1] == 0){
            map->next = pMap;
            this->NodeList = map;
        }
        if(a[0]==1 and a[1] == 0 and this_map){
            if (!this_edge){
                edge->parent = this_map->node;
                edge->nextNextEdge = this_map->node->edge;
                this_map->node->edge = edge;
            }
        }
        if (a[0] == 0 and a[1] ==1 and next_map){
//            edge->parent = next_map->node;
            if(!this->searchNextEdge(next_map->node, relationship)){
                edge->nextNextEdge = next_map->node->edge;


            }
        }
    }

}

void GraphList::addNode(const string &name, const string &nextName, int weight) {

}

Node *GraphList::searchNode(const string &name) {
    Map* pMap=this->NodeList;
    if(pMap!=NULL){
        if (pMap->node->name == name){
            return pMap->node;
        }
        while (pMap->next!=NULL){
            pMap = pMap->next;
            if (pMap->node->name == name){
                return pMap->node;
            }
        }
    }
    return nullptr;
}

Map *GraphList::searchMap(const string &name) {
    Map* pMap=this->NodeList;
    if(pMap!=NULL){
        if (pMap->node->name == name){
            return pMap;
        }
        while (pMap->next!=NULL){
            pMap = pMap->next;
            if (pMap->node->name == name){
                return pMap;
            }
        }
    }
    return nullptr;
}

edge *GraphList::searchParentEdge(const Node *search_node, const string& relationship) {
    Edge *pEdge = search_node->edge;
    if (pEdge!=NULL){
        if (pEdge->relationship == relationship and pEdge->parent->name == search_node->name){
            return pEdge;
        }
        while (pEdge->nextParentEdge){
            pEdge = pEdge->nextParentEdge;
            if (pEdge->relationship == relationship and pEdge->parent->name == search_node->name){
                return pEdge;
            }
        }
    }

    return nullptr;
}

edge *GraphList::searchNextEdge(const Node *search_node, const string &relationship) {
    Edge *pEdge = search_node->edge;
    if (pEdge!=NULL){
        if (pEdge->relationship == relationship and pEdge->next->name == search_node->name){
            return pEdge;
        }
        while (pEdge->nextNextEdge){
            pEdge = pEdge->nextNextEdge;
            if (pEdge->relationship == relationship and pEdge->next->name == search_node->name){
                return pEdge;
            }
        }
    }
    return nullptr;
}


