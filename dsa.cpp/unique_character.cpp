#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        queue<int> q;

        for(int i=0;i<s.size();i++) {
            if(m.find(s[i])==m.end()) {
                q.push(i);
            }
            m[s[i]]++;

            while(!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    int index = sol.firstUniqChar(s);

    if(index == -1)
        cout << "No unique character found" << endl;
    else
        cout << "First unique character: '" << s[index] 
             << "' at index " << index << endl;

    return 0;
}
