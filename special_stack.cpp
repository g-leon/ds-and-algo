#include <fstream>
#include <iostream>
#include <assert.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <climits>
using namespace std;

/*
Write a minPeak function for a stack (function that returns the minimum element in the stack).
*/

class mystack {

private:
    stack<int> st;
    stack<int> minst;

public:
    void push(int x);
    void pop();
    int top();
    int get_min();
    bool empty();
};

void mystack::push(int x) {
    st.push(x);
    if (minst.empty())
        minst.push(x);
    else if (x < minst.top())
        minst.push(x);
}

void mystack::pop() {
    if (st.empty()) {
        cout << "Stack underflow!";
        abort();
    }
    if (st.top() == minst.top())
        minst.pop();
    st.pop();
}

int mystack::top() {
    if (st.empty()) {
        cout << "Can't \"top()\" from empty stack!";
        abort();
    }
    return st.top();
}

int mystack::get_min() {
    if (st.empty()) {
        cout << "Can't \"get_min()\" from empty stack!";
        abort();
    }
    return minst.top();
}

bool mystack::empty() {
    return st.empty();
}

int main() {
    mystack *st = new mystack();
    st->push(2);
    st->push(1);
    st->push(3);
    cout << "Top: " << st->top() << endl;
    cout << "Min: " << st->get_min() << endl;
    cout << "Is empty: " << st->empty() << endl;
    st->pop();
    st->pop();
    cout << "Min: " << st->get_min() << endl;
    delete st;

    cout << st;
}
