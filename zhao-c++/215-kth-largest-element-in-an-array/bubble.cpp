class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k<nums.size()/2) {
            for(int i = 0; i < k; i++) {
                for(int j = nums.size() - 1; j > i; j--) {
                    if(nums[j-1] < nums[j]) {
                        int temp = nums[j-1];
                        nums[j-1] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
            return nums[k-1];
        } else {
            for(int i = 0; i < k; i++) {
                for(int j = nums.size() - 1; j > i; j--) {
                    if(nums[j-1] > nums[j]) {
                        int temp = nums[j-1];
                        nums[j-1] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
            return nums[nums.size() - k];
        }
        
    }
};
