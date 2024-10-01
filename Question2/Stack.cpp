#include "Stack.h"
#include <numeric>

// check if the stack is empty
bool Stack::isEmpty() const {
    return stack.empty();
}

// push an element onto the stack
void Stack::push(int value) {
    stack.push_back(value);
}

// pop the top element from the stack
void Stack::pop() {
    if (!isEmpty()) {
        stack.pop_back();
    }
    else {
        cout << "Stack is empty, cannot pop." << endl;
    }
}

// get the top element of the stack
int Stack::top() const {
    if (!isEmpty()) {
        return stack.back();
    }
    else {
        cout << "Stack is empty, no top element." << endl;
        return -1; // return an invalid value in case of empty stack
    }
}

// get the average of stack elements
double Stack::getAverage() const {
    if (!isEmpty()) {
        double sum = accumulate(stack.begin(), stack.end(), 0);
        return sum / stack.size();
    }
    else {
        cout << "Stack is empty, cannot calculate average." << endl;
        return 0.0;
    }
}

// display the stack
void Stack::display() const {
    cout << "Stack elements: ";
    for (int i : stack) {
        cout << i << " ";
    }
    cout << endl;
}
