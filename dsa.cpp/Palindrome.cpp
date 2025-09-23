#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) {
    int ans = 0;
    int n = x;

    if (x < 0) return false;

    while (x != 0) {
        int remainder = x % 10;
        x /= 10;

        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && remainder > 7)) 
            return false;

        ans = ans * 10 + remainder;
    }

    return n == ans;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPalindrome(number))
        cout << number << " is a palindrome." << endl;
    else
        cout << number << " is not a palindrome." << endl;

    return 0;
}
