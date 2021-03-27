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
    int threeSumClosest(vector<int>& nums, int target) {
        int r=nums[0]+nums[1]+nums[2];
        int min=abs(r-target);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            while(i>0&&i<nums.size()&&nums[i]==nums[i-1])
                i++;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                int t = nums[j]+nums[k]+nums[i];
                if(t==target)
                    return target;
                if(abs(t-target)<min) {
                    r=t;
                    min = abs(t - target);
                }
                t>target?k--:j++;
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    int a[] = {1,2,4,8,16,32,64,128};
    vector<int> aa;
    int r;
    aa.assign(a,a+8);
    r = s.threeSumClosest(aa,82);
    cout<<r;
    return 1;
}
//a+b=-c;