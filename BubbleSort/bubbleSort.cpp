#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    //for rount 1 to n-1
    for(int i=1; i<n-1; i++) {

        
        for(int j=0; j<n-i; j++) {
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int j = 0; j < n; j++) {
        cout << arr[j] << " "<<endl;
    }
}

int main () {

    int arr[6] = {10,1,7,6,14,9};

    bubbleSort(arr, 6);

    return 0;
}