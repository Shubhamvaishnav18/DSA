#include<iostream>
using namespace std;

void insertionSort(int arr[], int n) {

    for(int i=1; i<n; i++) {
        int key = arr[i]; // The element to be inserted in the sorted part
        int j = i-1;  // Start comparing with the previous element

        // Move elements that are greater than the key to one position ahead
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        // Insert the key in its correct position
        arr[j+1] = key;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[7] = {10,1,7,4,8,2,11};

    insertionSort(arr, 7);

    return 0;
}