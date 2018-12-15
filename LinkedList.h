//
// Created by andrea on 12/14/18.
//

#ifndef EXAMEN2_ANDREAMENDOZA_LINKEDLIST_H
#define EXAMEN2_ANDREAMENDOZA_LINKEDLIST_H

#include "Node.h"
#include "User.h"

class LinkedList {
private:
    int start;
    Node* inicio;
    Node* last;

public:
    LinkedList();

    bool push(User*);

    int getStart() const;

    Node *getInicio() const;

    void setInicio(Node *inicio);
};


#endif //EXAMEN2_ANDREAMENDOZA_LINKEDLIST_H
