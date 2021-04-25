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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>r;
        int right = nums.size()-1;
        int left = 0;
        int index = bsearch(nums,target,left,right);
        if(!~index)
        {
            r.push_back(-1);
            r.push_back(-1);
            return r;
        }
        r.push_back(left_search(nums,target,left,index));
        r.push_back(right_search(nums,target,index,right));
        return r;
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
        if(nums[mid]<target)
            return bsearch(nums,target,mid+1,right-1);
        else return bsearch(nums,target,left+1,mid-1);
    }
    int left_search(vector<int>& nums,int target,int left,int right)
    {
        if(nums[right]!=target)
            return right+1;
        int mid = (left+right)/2;
        if(nums[left]==target)
            return left;
        else if(nums[mid]==target)
            return left_search(nums,target,left+1,mid-1);
        else return left_search(nums,target,mid+1,right-1);
    }
    int right_search(vector<int>& nums,int target,int left,int right)
    {
        if(nums[left]!=target)
            return left-1;
        int mid = (left+right)/2;
        if(nums[right]==target)
            return right;
        else if(nums[mid]==target)
            return right_search(nums,target,mid+1,right-1);
        else return right_search(nums,target,left+1,mid-1);
    }
};


int main()
{
    vector<int>nums = {5,7,7,8,8,10};
    Solution s;
    for(int i:s.searchRange(nums,8))
        cout<<i<<endl;
    return 1;
}