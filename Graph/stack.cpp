#include "stack.h"


void stack::print() {
    if (st.empty()) {
        cout << "STACK IS EMPTY" << endl;
        return;
    }
    for (auto it : st) {
        cout << it << " ";
    }
    cout << endl;
}

void stack::push(int n) {
    if (st.size() == st.max_size()) {
        cout << "STACK IS FULL" << endl;
        return;
    }
    st.push_front(n);
    //this->print();
}

int stack::pop() {
    if (st.empty()) {
        cout << "STACK IS EMPTY" << endl;
        return NULL;
    }
    int a = (int)st.front();
    st.pop_front();
    return a;
    //this->print();
}

int stack::top()
{
    return st.front();
}

bool stack::isEmpty() {
    if (st.empty()) {
        return true;
    }
    else {
        return false;
    }
}