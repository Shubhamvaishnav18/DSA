#include<iostream>
using namespace std;

bool checkPlindrome(string str, int i, int j) {

    //base case
    if(i>j) {
        return true;
    }

    if(str[i] != str[j]) {
        return false;
    }
    else {
        //recursive call
        return checkPlindrome(str, i+1, j-1);
    }
}

int main() {

    string name = "bookkoob";

    bool isPalindrome = checkPlindrome(name, 0, name.length()-1);

    if(isPalindrome) {
        cout << "It's a palindrome" << endl;
    }
    else {
        cout << "It's not a palindrome" << endl;
    }

}