#include <iostream>
#include <stdexcept>

using namespace std;

// node struct
template <typename Item_Type>
struct Node {
    Item_Type data;
    Node* next;

    Node(const Item_Type& data_item) : data(data_item), next(nullptr) {}
};

// Single_Linked_List class
template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();

    Item_Type& front();
    Item_Type& back();

    bool empty() const;
    size_t size() const;

    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;

    void printList() const;  
};

// constructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// destructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

// push_front
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* newNode = new Node<Item_Type>(item);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    num_items++;
}

// push_back
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* newNode = new Node<Item_Type>(item);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

// pop_front
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        throw runtime_error("List is empty.");
    }
    Node<Item_Type>* temp = head;
    head = head->next;
    delete temp;
    num_items--;
    if (empty()) {
        tail = nullptr;
    }
}

// pop_back
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        throw runtime_error("List is empty.");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node<Item_Type>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// front
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::front() {
    if (empty()) {
        throw runtime_error("List is empty.");
    }
    return head->data;
}

// back
template <typename Item_Type>
Item_Type& Single_Linked_List<Item_Type>::back() {
    if (empty()) {
        throw runtime_error("List is empty.");
    }
    return tail->data;
}

// empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

// size
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// insert
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        index = num_items;
    }
    if (index == 0) {
        push_front(item);
    }
    else if (index == num_items) {
        push_back(item);
    }
    else {
        Node<Item_Type>* newNode = new Node<Item_Type>(item);
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        num_items++;
    }
}

// remove
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    }
    else {
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node<Item_Type>* toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete == tail) {
            tail = current;
        }
        delete toDelete;
        num_items--;
    }
    return true;
}

// find
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}

// print list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::printList() const {
    Node<Item_Type>* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
