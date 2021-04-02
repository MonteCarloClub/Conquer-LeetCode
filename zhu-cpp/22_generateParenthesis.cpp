//
// Created by Ole on 2021/3/27 0027.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return { "()" };
        vector<vector<string>>dp(n+1);
        dp[0] = {""};
        dp[1]= {"()"};
        for(int i=2;i<=n;i++)
            for(int j=0;j<i;j++)
                for(string q:dp[i-j-1])
                    for(string p:dp[j])
                        dp[i].push_back("("+q+")"+p);
        return dp[n];
    }
};

int main()
{
    int a[1] = {1};
    int b[1] = {2};
    Solution s;
    vector<string> t = s.generateParenthesis(3);
    for(int i=0;i<t.size();i++)
        cout<<t[i]<<" "<<endl;
    return 1;
}
