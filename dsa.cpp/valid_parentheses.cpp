#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
                st.push(str[i]);
            } else {
                if (st.size() == 0) return false;

                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                } else return false;
            }
        }
        return st.size() == 0;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string with parentheses: ";
    cin >> input;

    if (sol.isValid(input)) {
        cout << "The string is valid (balanced parentheses)." << endl;
    } else {
        cout << "The string is NOT valid (unbalanced parentheses)." << endl;
    }

    return 0;
}
