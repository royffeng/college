#include <iostream>
using namespace std;
#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    if (cpy.head == nullptr) {
        head = nullptr;
        tail = nullptr;
    } else if (cpy.head->next == nullptr) {
        head = new IntNode(cpy.head->data);
        tail = head;
    } else {
        IntNode *current = cpy.head; 
        while (current) {
            this->push_back(current->data);
            current = current->next;
        } 
    }
}

IntList::~IntList() {
    IntNode* current = this->head;
    while (current) {
        IntNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::pop_front() {
    if (head == nullptr) {
        return;
    } else if (tail == head) {
        delete head;
        head = tail = nullptr;
    } else {
        IntNode *temp = head;
        delete head;
        head = temp->next;
    }
}

void IntList::clear(){
    IntNode *current = this->head;
    while (current) {
        IntNode* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::selection_sort() {
    if (head == nullptr)
        return;
    IntNode *tempNode = nullptr;
    for (IntNode* i = head; i->next; i = i->next) {
        int min = i->data;
        tempNode = i;
        for (IntNode* j = i->next; j; j = j->next) {
            if (min > j->data) {
                min = j->data;
                tempNode = j;
            }
        }
        tempNode->data = i->data;
        i->data = min;
    }
}

void IntList::insert_ordered(int value) {
    IntNode *newNode = new IntNode(value);
    IntNode *current = head;
    if (head == nullptr) { //if there is no node
        head = newNode;
        tail = newNode;
    } else if (head == tail) { //if there is 1 node
        if (head->data < newNode->data) {
            head->next = newNode;
            tail = newNode;
        } else if (head->data > newNode->data) {
            newNode->next = head;
            head = newNode;
        }
    } else {
        if (head->data > newNode->data) { //if head data is > value
            newNode->next = head;
            head = newNode;
            return;
        } 
        while (current) {
            if (current->next != nullptr) { //to prevent segmentation error
                if (current->next->data > newNode->data) {
                    newNode->next = current->next;
                    current->next = newNode;
                    return;
                } 
            } else if (current == tail) { //if index reaches end of linkedlist
                tail->next = newNode;
                tail = newNode;
                return;
            }
            current = current->next;
        }
    }
}

void IntList::remove_duplicates() {
    IntNode *previous = nullptr;
    if (head == nullptr) {
        return;
    } else if (head == tail) {
        return;
    } else {
        for (IntNode *i = head; i; i = i->next) {
            previous = i; //to keep track of previous node
            for (IntNode *j = i->next; j; j = previous->next) {
                if (j->data == i->data) { //if duplicate found
                    if (j->next == nullptr) { //if duplicate is found at the end
                        delete j;
                        tail = previous;
                        tail->next = 0;
                        if (head == tail)
                            return;
                    } else {
                        previous->next = j->next;
                        delete j;
                    }
                } else {
                    previous = previous->next;
                }
            }
        }
    }
}

bool IntList::empty() const {
    if (head == nullptr)
        return true;
    return false;
}

const int &IntList::front() const {
    return head->data;
}

const int &IntList::back() const {
    return tail->data;
}

ostream &operator<<(ostream &out, const IntList &list) {
    IntNode *current = list.head;
    while (current) {
        if (current == list.tail) {
            out << current->data;
        }
        else {
            out << current->data << " ";
        }
        current = current->next;
    }
    return out;    
}

IntList &IntList::operator=(const IntList &rhs) {
    if (this != &rhs) { //prevent self-assignment
        clear();
        if (rhs.head == nullptr) {
            head = nullptr;
            tail = nullptr;
        } else if (rhs.head->next == nullptr) {
            head = new IntNode(rhs.head->data);
            tail = head;
        } else {
            IntNode *current = rhs.head;
            while (current) {
                this->push_back(current->data);
                current = current->next;
            } 
        }
    }
    return *this;
}
