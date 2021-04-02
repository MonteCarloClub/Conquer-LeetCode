//
// Created by Ole on 2021/3/28 0028.
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int len=1;
        int index=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                len++;
                nums[index++]=nums[i];
            }
        }
        return len;
    }
};