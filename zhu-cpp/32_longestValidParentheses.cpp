//
// Created by Oliver on 2021/4/20.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0;
        int temp = 0;
        stack<char> stk;
        int maxlen = 0;
        for(auto c:s)
        {
            if(c=='(') {
                left++;
                stk.push(c);
            }
            else
            {
                right++;
                if(!stk.empty())
                    stk.pop();
                temp+=2;
                if(right<=left)
                    maxlen = max(right*2,maxlen);
                else
                    right = left = 0;
            }
        }
        return maxlen;
    }
};



int main()
{
    string str="()(()";
    Solution s;
    int r = s.longestValidParentheses(str);
    cout<<r;
    return 1;
}