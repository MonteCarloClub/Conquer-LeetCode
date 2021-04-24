//
// Created by Ole on 2021/4/19 0019.
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
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> nums;
        map<string,int> flag;
        map<string,int> flag_has;
        int size = words[0].size();
        if(!words.size())
            return nums;
        int wsize = words[0].size();
        for(int i=0;i<words.size();i++)
            flag_has[words[i]]++;
        if(s.size()<wsize)
            return nums;
        for(int i=0;i<wsize;i++)
        {
            flag.clear();
            for(int i=0;i<words.size();i++)
                flag[words[i]]++;
            vector<string>sub;
            for(int k=i;k+wsize<s.size();k+=wsize)
            {
                sub.push_back(s.substr(k,wsize));
            }
            int start = 0;
            int result = 0;

            for(int end=0;end<sub.size();end++)
            {
                if(flag[sub[end]])
                {
                    flag[sub[end]]--;
                    result++;
                    if(result==words.size())
                        nums.push_back(i+start*wsize);
                }
                else if(!flag_has[sub[end]])
                {
                    start = end+1;
                    result = 0;
                    for(int i=0;i<words.size();i++)
                        flag[words[i]]++;
                }
                else
                    while(flag[sub[end]]==0&&start<=end)
                    {
                        result--;
                        flag[sub[start]]++;
                        start++;
                    }
            }
        }
        return nums;
    }
};


int main()
{
    string s = "barfoofoobarthefoobarman";
    vector<string>words;
    words.push_back("bar");
    words.push_back("foo");
    words.push_back("the");
    Solution ss;
    for(auto i: ss.findSubstring(s,words))
    {
        cout<<i<<endl;
    }
    return 1;
}