//
// Created by Ole on 2021/3/23 0023.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long a = 0;
        int flag = 1;
        int i = 0;
        s = " " + s;
        while (s[i] ==' ' && i < s.length())
            i++;
        if(s[i]=='-'&&s[i+1]>='0'&&s[i+1]<='9') {
            flag = 0;
            i++;
            a = -s[i++]+'0';
        }
        else if(s[i]=='+'&&s[i+1]>='0'&&s[i+1]<='9')
            i++;
        while ((s[i] >= '0' && s[i] <= '9') && i < s.length())
        {
            if(flag)
                a = a*10+s[i]-'0';
            else a = a*10-s[i]+'0';
            i++;
            if(a>INT_MAX)
                return INT_MAX;
            if(a<INT_MIN)
                return INT_MIN;
        }
        if(s[i-1] == '-')
            a = -a;
        int c = a;
        return a;
    }
};
int main()
{
    Solution s;
    cout<<s.myAtoi("+1")<<endl;
    cout<<s.myAtoi("- -419ddd3 with words")<<endl;
    cout<<s.myAtoi("-4193 with words")<<endl;
    cout<<s.myAtoi("- -419ddd3 with words")<<endl;
    return 1;
}
