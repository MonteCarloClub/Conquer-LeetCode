//
// Created by Oliver on 2021/4/9.
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
    map<string,int>flag;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        int len = words[0].size();
        int start=0,end=0;
        while(end<s.length())
        {

        }
    }
};

int main()
{
    vector<string> aa = {"123","456"};
    vector<int> r;
    string a = "123";
    Solution s;
    r = s.findSubstring(a,aa);
    for(auto i:r)
        cout << i << endl;
    return 1;
}