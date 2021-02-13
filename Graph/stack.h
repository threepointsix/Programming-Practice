#pragma once
#include <iostream>
#include <list>

using namespace std;

class stack {
    list<int> st;
public:
    void push(int n);
    int pop(); // I changed method void pop(), to int pop(), so that it returns a label of removed element
    int top();
    void print();
    bool isEmpty(); // I added method isEmpty()
};
