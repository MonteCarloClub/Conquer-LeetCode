//
// Created by Ole on 2021/3/23 0023.
//
#include <string>
#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string r;
        while(x)
        {
            r += (char)(x%10+'0');
            x/=10;
        }
        for(int i=0;i<r.length();i++)
            if(r[i]!=r[r.length()-i-1])
                return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout<isPalindrome(124124)<<endl;
    return 1;
}