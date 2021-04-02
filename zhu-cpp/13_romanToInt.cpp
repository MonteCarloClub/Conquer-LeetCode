//
// Created by Ole on 2021/3/23 0023.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int getc(char i)
    {
        if(i=='I')
            return 1;
        if(i=='V')
            return 5;
        if(i=='X')
            return 10;
        if(i=='L')
            return 50;
        if(i=='C')
            return 100;
        if(i=='D')
            return 500;
        if(i=='M')
            return 1000;
        return 0;
    }
    int romanToInt(string s)
    {
        int r = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size()&&getc(s[i])<getc(s[i+1]))
                r-=getc(s[i]);
            else
                r+=getc(s[i]);
        }
        return r;
    }
};

int main()
{
    Solution s;
    string a = "LVIII";
    cout<<s.romanToInt(a)<<endl;
    return 1;
}