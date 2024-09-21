#include<iostream>
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

int main() {

    return 0;
}