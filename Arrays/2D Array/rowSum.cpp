#include <iostream>
using namespace std;

//to print row wise sum
void printSum(int arr[][3], int i, int j) {
    cout << "Printing sum : " << endl;
    for(int i=0; i<3; i++) {
        int sum = 0;
        for(int j=0; j<3; j++) {
            sum += arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int main() {
    
    int arr[3][3];
    
    //taking input row wise
    cout << "Enter the elements" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }
    
    //print array
    cout << "Printing the array " << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    printSum(arr, 3, 3);

    return 0;
}