class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while(true) {
            int a = partition(nums, left, right);
            if(a+1 == k) {
                return nums[a];
            } else if (a < k) {
                left = a+1;
            } else {
                right = a-1;
            }

        }
    }

    int inline partition(vector<int>& nums, int left, int right) {
        int j = left;
        for(int i = left+1; i<=right; i++) {
            if(nums[i] >= nums[left]) {
                j++;
                if(j != i) {
                    swap(nums, j, i);
                }
            }
        }
        swap(nums, left, j);
        return j;
   } 
    void inline swap(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
};
