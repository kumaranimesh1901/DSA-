#include<iostream>
#include<vector>
#include <string>
#include <algorithm>

using namespace std;
 bool isPalin(string s)
 {
    string s1=s;
    reverse(s1.begin(),s1.end());
    return s1==s;
 }
 
 void get_all_parts(string s,vector<string> &combination,vector<vector<string>>&ans)
 {
    if(s.size()==0)
    {
        ans.push_back(combination);
        return;
    }

    for(int i=0;i<s.size();i++)
    {
        string part=s.substr(0,i+1);

        if(isPalin(part))
        {
            combination.push_back(part);
            get_all_parts(s.substr(i+1),combination,ans);
            combination.pop_back();

        }
    }

 }
 vector<vector<string>> partition(string s) {

        vector<string> partitions;
        vector<vector<string>> ans;
        get_all_parts(s,partitions,ans);
        return ans;

    }



int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<vector<string>> result = partition(s);

    cout << "Palindrome partitions:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << "]\n";
    }
    return 0;
}