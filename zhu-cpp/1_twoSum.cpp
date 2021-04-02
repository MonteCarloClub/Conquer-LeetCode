//
// Created by Ole on 2021/3/23 0023.
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> res;
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
            if(res[nums[i]])
            {
                ret.push_back(res[nums[i]]-1);
                ret.push_back(i);
                return ret;
            }
            else res[target-nums[i]]=i+1;
        return ret;
    }
};