#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) { Node* n = p->next; delete p; p = n; }
}
void LinkedList::push_front(int v) { head_ = new Node(v, head_); }
void LinkedList::remove_evens() {
     LinkedList odd_list; 
    Node* p = head_;
    while (p) {
        if (p->value % 2 == 1) { 
            odd_list.push_front(p->value);
        }
        p = p->next;
    }

    
    Node* new_head = nullptr;
    p = odd_list.head_;
    while (p) {
        new_head = new Node(p->value, new_head);
        p = p->next;
    }
    head_ = new_head;
}
std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
