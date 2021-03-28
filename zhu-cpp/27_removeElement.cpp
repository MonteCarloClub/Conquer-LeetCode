//
// Created by Ole on 2021/3/29 0029.
//

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 1;
        while(!nums.empty()&&nums[0]==val)
            nums.erase(nums.begin());
        if(nums.empty())
            return 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=val)
                nums[++]=nums[i];
        }
        return index;
    }
};
