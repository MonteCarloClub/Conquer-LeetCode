//
// Created by Oliver on 2021/4/20.
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
    bool cmp(int a,int b)
    {
        return a<b;
    }
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2,j=0;
        for(;i>=0;i--)
        {
            for(j=nums.size()-1;j>i;j--)
                if(nums[i]<nums[j])
                {
                    swap(nums[i],nums[j]);
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
        }
        if(i==-1&&j==0)
            sort(nums.begin(),nums.end());
    }
};

void printn(vector<int> nums)
{
    Solution s;
    s.nextPermutation(nums);
    for(auto i:nums)
    {
        cout<<i<<endl;
    }
    cout<<endl;
}
int main()
{
    vector<int> nums1 = {1,3,2};
    vector<int> nums2 = {1,3,2};
    printn(nums1);
    //printn(nums2);
    return 1;
}

