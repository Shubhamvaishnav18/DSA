#include<iostream>
#include<map>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        //constructor
        Node(int d) {
            this -> data = d;
            this -> next = NULL;
        }

        //destructor
    ~Node() {
        int val = this -> data;
        if(this -> next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << val << endl;
    }
};

void insertNode(Node* &tail, int element, int d) {

    //Empty list 
    if (tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
       //Non empty list
       //assuming that the element is present in the list

       Node* curr = tail;

       while(curr -> data != element) {
        curr = curr -> next;
       }

       //Element found -> curr is representing element wala node
       Node* temp = new Node(d);
       temp -> next = curr -> next;
       curr -> next = temp;
    }
}

void print(Node* tail) {

    Node* temp = tail;

    //empty 
    if(tail == NULL) {
        cout << "Linked list is empty" << endl;
        return;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    }
    while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value) {

    //Empty list 
    if(tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    else {
        //Non-empty
        //Asuming that value is present in list

        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 node linked list
        if(tail == prev) {
            tail = NULL;
        }

        //>=2 node linked list
        if(tail == curr) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

//function for linked list circular or not
bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head) {
        temp = temp -> next;
    }

    if(temp = head) {
        return true;
    }

    return false;
}

int main() {

    Node* tail = NULL;

    //when list is empty
    insertNode(tail, 5, 3);
    print(tail);

    //when list is not empty
    insertNode(tail, 3, 5);
    print(tail);

    // insertNode(tail, 5, 7);
    // print(tail);

    // insertNode(tail, 7, 9);
    // print(tail);

    // insertNode(tail, 5, 6);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    if(isCircularList(tail)) {
        cout << "Linked List is circular" << endl;
    }
    else {
        cout << "Linked List is not circular" << endl;
    }

    return 0;
}