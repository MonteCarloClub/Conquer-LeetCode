//
// Created by Oliver on 2021/9/26.
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
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]<=0||nums[i]>n)
                nums[i]=n+1;
        for(int i=0;i<n;i++)
            if(abs(nums[i])<=n)
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        for(int i=0;i<n;i++)
            if(nums[i]>=0)
                return i+1;
        return n+1;
    }
};
int main()
{
    vector<int>nums = {1,1};
    Solution s;
    int results = s.firstMissingPositive(nums);
    cout<<results;
    return 1;
}
