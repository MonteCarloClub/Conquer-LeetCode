//
// Created by Oliver on 2021/5/13.
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
    int add(int a,int b)
    {
        return (a+b)%1000000007;
    }
    int numWays(int steps, int arrLen) {
        if(steps == 0||steps == 1||arrLen == 1)
            return 1;
        int s[251]={1,1};
        int t[251]={1,1};
        if(arrLen>251)
            arrLen = 251;
        for(int i=2;i<steps;i++)
        {
            t[0] = add(s[0],s[1]);
            for(int j=1;j<arrLen-1;j++)
                t[j] = add(add(s[j-1],s[j]),s[j+1]);
            t[arrLen-1] = add(s[arrLen-1],s[arrLen-2]);
            for(int j=0;j<arrLen;j++)
                s[j] = t[j];
        }
        return add(t[0],t[1]);
    }
};

int main()
{
    Solution s;
    cout<<s.numWays(4,3);
    return 1;
}