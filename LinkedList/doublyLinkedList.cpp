#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

    //constructor
    Node(int d) {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }

    //destructor
    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data" << val << endl;
    }
};

//traversing a Linked List
void print(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next; 
    }
    cout << endl;
}

//finding length of linked list
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while(temp != NULL) {
        len++;
        temp = temp -> next; 
    }

    return len;
}

//insert new node at head
void insertAtHead(Node* &head, int d) {

        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
}

//insert at last of the linked list
void insertAtTail(Node* &tail, int d) {

        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
}

//insert node at given position
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {

     //insert at start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }
  
    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp -> next;
        cnt++;  
    }

    //inserting at last position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a new node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* &head) {

    //deleting starting or first node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        //deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main() {

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);

    //cout << getLength(head) << endl;

    insertAtHead(head, 11);
    print(head);

    insertAtTail(tail, 25);
    print(head);

    insertAtPosition(head, tail, 2, 100);
    print(head);

    insertAtPosition(head, tail, 1, 101);
    print(head);

    insertAtPosition(head, tail, 6, 103);
    print(head);

    deleteNode(6 , head);
    print(head);

    return 0;
}