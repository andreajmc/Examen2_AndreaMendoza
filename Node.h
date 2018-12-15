//
// Created by andrea on 12/14/18.
//

#ifndef EXAMEN2_ANDREAMENDOZA_NODE_H
#define EXAMEN2_ANDREAMENDOZA_NODE_H


#include "User.h"

class Node {
private:
    User* data;
    Node* next;
public:
    //constructores
    Node(User*);
    Node();
    //data
    User* getData();
    void setData(User*);
    //node
    void setNext(Node*);
    Node* getNext();
    //destructor

    ~Node();
};


#endif //EXAMEN2_ANDREAMENDOZA_NODE_H
