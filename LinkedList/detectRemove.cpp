#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
    }
};

void insertAtHead(Node* &head, int d) {

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void insertAtPosition(Node* &head,Node* &tail, int position, int d) {
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
    temp -> next = nodeToInsert;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(int position, Node* &head) {

    //deleting starting or first node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start node
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

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

//funtion for detect loop in linked list
bool detectLoop(Node* head) {

    if(head == NULL) {
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "present of element :" << temp -> data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    return false;
}

//detect loop by floyd algoritham
Node* floydDetectLoop(Node* head) {
    
    if(head == NULL) {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout << "present at" << " " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
} 

//function for finding first element in a loop of linked list
Node* getStartingNode(Node* head) {

    if(head == NULL) {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

//function for remove loop from a linked list
void removeLoop(Node* head) {

    if(head == NULL) {
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    }

    temp -> next = NULL;
}

int main() {
    
    Node* node1 = new Node(10);

    //head pointed to node1
    Node* head = node1;
    Node* tail = head;
    // print(head);

    insertAtTail(tail, 12);
    // print(head);

    insertAtTail(tail, 15);
    // print(head);

    insertAtPosition(head, tail, 4, 22);
    // print(head);

    // deleteNode(3, head);
    // print(head);

    tail -> next = head -> next;

    cout << "head" << " " << head -> data << endl;
    cout << "tail" << " " << tail -> data << endl;

    if(floydDetectLoop(head)) {
        cout << "cycle is present" << endl;
    }
    else {
        cout << "cycle is not present" << endl;
    }

    Node* loop = getStartingNode(head);

    cout << "loops starts at" << " " << loop -> data << endl;

    removeLoop(head);
    print(head);

    // if(detectLoop(head)) {
    //     cout << "cycle is present" << endl;
    // }
    // else {
    //     cout << "cycle is not present" << endl;
    // }

    return 0;
}