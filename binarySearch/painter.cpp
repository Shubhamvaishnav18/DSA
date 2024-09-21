#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int k, int mid) {

    int painterCount = 1;
    int bordSum = 0;

    for(int i=0; i<n; i++) {
        if(bordSum + arr[i] <= mid) {
            bordSum += arr[i];
        }
        else {
            painterCount++;
            if(painterCount > k || arr[i] > mid) {
                return false;
            }
            bordSum = arr[i];
        }
    }
    return true;
}

int allocateBords(int arr[], int n, int k) {

    int s = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while(s <= e) {

        if(isPossible(arr, n, k , mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid +1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main () {

    int arr[4] = {5,5,5,5};

    cout << allocateBords(arr, 4, 2) << endl;
}