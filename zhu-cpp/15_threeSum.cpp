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
        if(nums.size()<3)
            return r;
        map<int,int> m;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()&&nums[i]<=0;i++) {
            while(i>0&&i<nums.size()&&nums[i]==nums[i-1])
                i++;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                vector<int>t;
                if(nums[j]+nums[k]+nums[i]==0)
                {
                    cout<<"i:"<<i<<" j:"<<j<<" k:"<<k<<endl;
                    t.push_back(nums[i]);
                    t.push_back(nums[j]);
                    t.push_back(nums[k]);
                    r.push_back(t);
                    while(k>j&&nums[k]==nums[k-1])
                        k--;
                    k--,j++;
                }
                else if(nums[j]+nums[k]+nums[i]>0)
                {
                    k--;
                }
                else j++;
            }
        }
        return r;
    }
};
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>>r;
//        vector<int>tnums;
//        if(nums.size()<3)
//            return r;
//        map<int,int> m;
//        map<vector<int>,int> mv;
//        sort(nums.begin(),nums.end());
//        for(int i=0;i<nums.size();i++) {
//            if(m[nums[i]]<3)
//            {
//                tnums.push_back(nums[i]);
//                m[nums[i]]++;
//            }
//        }
//        for(int i=0;i<tnums.size()-1&&tnums[i]<=0;i++)
//            for(int j=i+1;j<tnums.size();j++)
//            {
//                vector<int> t;
//                m[tnums[i]]--;
//                m[tnums[j]]--;
//                if(tnums[j]<=-tnums[i]-tnums[j])
//                    if(m[-tnums[i]-tnums[j]]>0)
//                    {
//                        t.push_back(tnums[i]);
//                        t.push_back(tnums[j]);
//                        t.push_back(-tnums[i]-tnums[j]);
//                        if(!mv[t])
//                        {
//                            r.push_back(t);
//                            mv[t]=1;
//                        }
//                    }
//                m[tnums[i]]++;
//                m[tnums[j]]++;
//            }
//        return r;
//    }

int main()
{
    Solution s;
    int a[] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> aa;
    vector<vector<int>>r;
    for(int i=0;i<15;i++)
        aa.push_back(a[i]);
    r = s.threeSum(aa);
    for(int i=0;i<r.size();i++)
    {
        for(int j=0;j<r[i].size();j++)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
    return 1;
}
//a+b=-c;