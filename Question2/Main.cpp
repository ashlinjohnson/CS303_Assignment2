#include "Stack.h"

int main() {
    Stack s;

    // check if stack is empty
    if (s.isEmpty()) {
        cout << "Stack is currently empty." << endl;
    }

    // insert some integer values onto the stack
    s.push(10);
    s.push(20);
    s.push(30);

    // display stack
    s.display();

    // check top element
    cout << "Top of the stack: " << s.top() << endl;

    // remove the top element
    s.pop();
    cout << "After pop, ";
    s.display();

    // check top element
    cout << "Top of the stack: " << s.top() << endl;

    // calculate the average of the elements
    cout << "Average of stack elements: " << s.getAverage() << endl;

    return 0;
}
