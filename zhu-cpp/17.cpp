//
// Created by Ole on 2021/3/24 0024.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> s;
        if(digits=="")
            return s;
        s.push_back("");
        return getbig(s,digits);
    }
    vector<string> getbig(vector<string> s,string digits) {
        vector<string> t;
        if(digits=="")
            return s;
        for(int i=0;i<s.size();i++) {
            switch (digits[0]) {
                case '2':
                    t.push_back(s[i] + 'a');
                    t.push_back(s[i] + 'b');
                    t.push_back(s[i] + 'c');
                    break;
                case '3':
                    t.push_back(s[i] + 'd');
                    t.push_back(s[i] + 'e');
                    t.push_back(s[i] + 'f');
                    break;
                case '4':
                    t.push_back(s[i] + 'g');
                    t.push_back(s[i] + 'h');
                    t.push_back(s[i] + 'i');
                    break;
                case '5':
                    t.push_back(s[i] + 'j');
                    t.push_back(s[i] + 'k');
                    t.push_back(s[i] + 'l');
                    break;
                case '6':
                    t.push_back(s[i] + 'm');
                    t.push_back(s[i] + 'n');
                    t.push_back(s[i] + 'o');
                    break;
                case '7':
                    t.push_back(s[i] + 'p');
                    t.push_back(s[i] + 'q');
                    t.push_back(s[i] + 'r');
                    t.push_back(s[i] + 's');
                    break;
                case '8':
                    t.push_back(s[i] + 't');
                    t.push_back(s[i] + 'u');
                    t.push_back(s[i] + 'v');
                    break;
                case '9':
                    t.push_back(s[i] + 'w');
                    t.push_back(s[i] + 'x');
                    t.push_back(s[i] + 'y');
                    t.push_back(s[i] + 'z');
                    break;
            }
        }
        return getbig(t,digits.substr(1,digits.size()-1));
    }
};
int main()
{
    Solution s;
    string a = "23";
    vector<string> r;
    r = s.letterCombinations(a);
    for(int i=0;i<r.size();i++)
        cout<<r[i]<<endl;
    return 1;
}