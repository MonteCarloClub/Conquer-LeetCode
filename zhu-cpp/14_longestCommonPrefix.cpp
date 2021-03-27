//
// Created by Ole on 2021/3/24 0024.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        string r ="";
        int min_size = INT_MAX;
        for(int i=0;i<strs.size();i++)
            min_size=min_size<strs[i].size()?min_size:strs[i].size();
        for(int i=0;i<min_size;i++) {
            for (int j = 1; j < strs.size(); j++)
                if(strs[j][i]!=strs[0][i])
                    return r;
            r+=strs[0][i];
        }
        return r;
    }
};

int main()
{
    Solution s;
    string a = "LVIII";
    string b = "LV123";
    vector<string> strs;
    strs.push_back(a);
    strs.push_back(b);
    cout<<s.longestCommonPrefix(strs)<<endl;
    return 1;
}