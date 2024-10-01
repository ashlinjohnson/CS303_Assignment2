#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> stack;  

public:
    bool isEmpty() const;
    void push(int value);
    void pop();
    int top() const;
    double getAverage() const;
    void display() const;
};
