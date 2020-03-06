#include "IntList.h"
#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
       head = new IntNode(val);
   }else {
       IntNode *temp = new IntNode(val);
       temp->next = head;
       head = temp;
   }
}

ostream & operator<<(ostream &output, const IntList &list) {
    output << list.head;
    
    return output;
}

bool IntList::exists(int val) const {
   return exists(head, val);
}

bool IntList::exists(IntNode *node, int val) const{
    //base case
    if (node == nullptr) {
        return false;
    }else if (node->data == val) {
        return true;
    }
    
    //implicit else statement
    return exists(node->next, val);
}

ostream & operator<<(ostream &output, IntNode *node) {
    //base case
    if (node == nullptr) {
        return output;
    }else if (node->next == nullptr) {
        output << node->data;
    }else {
        output << node->data << " ";
    }
    
    //implicit else statement
    return output << node->next;
}
