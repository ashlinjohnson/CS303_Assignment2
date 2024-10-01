#include "Single_Linked_List.h"

int main() {
	Single_Linked_List<int> list;

    // test push_back
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    cout << "List after push_back operations: ";
    list.printList();

    // test push_front 
    list.push_front(5);
    cout << "List after push_front(5): ";
    list.printList();

    // test pop_front 
    list.pop_front();
    cout << "List after pop_front(): ";
    list.printList();

    // test pop_back 
    list.pop_back();
    cout << "List after pop_back(): ";
    list.printList();

    // test insert
    list.insert(1, 15);
    cout << "List after insert(1, 15): ";
    list.printList();

    // test remove 
    list.remove(1);
    cout << "List after remove(1): ";
    list.printList();

    // test find
    size_t pos = list.find(20);
    if (pos < list.size()) {
        cout << "Found 20 at index: " << pos << endl;
    }
    else {
        cout << "20 not found" << endl;
    }

    return 0;
}
