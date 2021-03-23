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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>r;
        vector<int>tnums;
        if(nums.size()<3)
            return r;
        map<int,int> m;
        map<vector<int>,int> mv;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            if(m[nums[i]]<3)
            {
                tnums.push_back(nums[i]);
                m[nums[i]]++;
            }
        }
        for(int i=0;i<tnums.size()-1&&tnums[i]<=0;i++)
            for(int j=i+1;j<tnums.size();j++)
            {
                vector<int> t;
                m[tnums[i]]--;
                m[tnums[j]]--;
                if(tnums[j]<=-tnums[i]-tnums[j])
                    if(m[-tnums[i]-tnums[j]]>0)
                    {
                        t.push_back(tnums[i]);
                        t.push_back(tnums[j]);
                        t.push_back(-tnums[i]-tnums[j]);
                        if(!mv[t])
                        {
                            r.push_back(t);
                            mv[t]=1;
                        }
                    }
                m[tnums[i]]++;
                m[tnums[j]]++;
            }
        return r;
    }
};

int main()
{
    Solution s;
    cout<<s.threeSum(a)<<endl;
    return 1;
}
//a+b=-c;