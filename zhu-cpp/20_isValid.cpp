//
// Created by Ole on 2021/3/27 0027.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')'||s[0]==']'||s[0]=='}'||s.length()%2)
            return false;
        stack<char> st;
        int i=0;
        for(;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{') {
                st.push(s[i]);
            }
            else if(s[i]==(st.top()+1)||(s[i]==(st.top()+2)))
                st.pop();
            else break;
            if(st.empty())
                break;
        }
        return i==s.length()&&st.empty();
    }
};
int main()
{
    Solution s;
    cout<<s.isValid("(){}}{");
    return 1;
}