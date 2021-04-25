//
// Created by Oliver on 2021/4/25.
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        return bsearch(nums,target,left,right);
    }
    int bsearch(vector<int>& nums,int target,int left,int right)
    {
        if(left>right)
            return -1;
        int mid = (left+right)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[left]==target)
            return left;
        if(nums[right]==target)
            return right;
        if(nums[mid]>nums[left])
        {
            if(target>nums[left]&&target<nums[mid])
                return bsearch(nums,target,left+1,mid-1);
            else
                return bsearch(nums,target,mid+1,right-1);
        }
        else {
            if(target>nums[mid]&&target<nums[right])
                return bsearch(nums,target,mid+1,right-1);
            else return bsearch(nums,target,left+1,mid-1);
        }
    }
};


int main()
{
    vector<int>nums = {4,5,6,7,0,1,2};
    Solution s;
    cout<<s.search(nums,3);
    return 1;
}