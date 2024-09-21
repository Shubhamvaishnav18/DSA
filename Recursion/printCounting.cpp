#include<iostream>
using namespace std;

void print(int n) {

    //base condition
    if(n == 0) {
        return;
    } 

    //processing
    cout << n << endl;

    //recursive relation
    print(n-1);
}

int main() {

    int n;
    cin>>n;

    print(n);

    return 0;
}