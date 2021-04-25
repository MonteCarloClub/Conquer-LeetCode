//
// Created by Oliver on 2021/4/25.
//

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for(;i<nums.size();i++)
            if(nums[i]>=target)
                return i;
        return i;
    }
};