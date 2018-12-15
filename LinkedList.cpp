//
// Created by andrea on 12/14/18.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    inicio = nullptr;
    last = nullptr;

}

bool LinkedList::push(User* object) {
    Node* newNode = new Node(object);
    last->setNext(newNode);
    last = newNode;
    return true;
}

int LinkedList::getStart() const {
    return start;
}

Node *LinkedList::getInicio() const {
    return inicio;
}

void LinkedList::setInicio(Node *inicio) {
    LinkedList::inicio = inicio;
}
