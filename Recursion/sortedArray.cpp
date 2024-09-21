#include<iostream>
using namespace std;

bool isSorted(int arr[], int size) {

    //base case
    if(size == 0 || size == 1) {
        return true;
    }

    if(arr[0] > arr[1]) {
        return false;
    }
    else {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}

int main() {

    int arr[5] = {2,9,8,9,12};
    int size = 5;

    bool ans = isSorted(arr, size);

    if(ans) {
        cout << "Array is sorted" << endl;
    }
    else {
        cout << "Array is unsorted" << endl;
    }

    return 0;
}