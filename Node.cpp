//
// Created by andrea on 12/14/18.
//

#include "Node.h"


Node::Node() {
    data = nullptr;
    next= nullptr;
}

Node::Node(User *) {
    this->data=data;
    next=0;
}

User* Node::getData() {
    return data;
}

void Node::setData(User * pdata) {
    data=pdata;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node * pNext) {
    next=pNext;
}

Node::~Node() {
    if(next)
        delete next;
    if(data)
        delete data;
}
