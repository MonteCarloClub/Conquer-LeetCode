class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        while(true) {
            int pivot = partition(nums, left, right);
            if(pivot+1 == k) {
                return nums[pivot];
            } else if (pivot < k) {
                left = pivot+1;
            } else {
                right = pivot-1;
            }
        }
    }

    inline int partition(vector<int>& nums, int left, int right) {
        randomChoose(nums, left, right);
        int j = left;
        for(int i = left+1; i<=right; i++) {
            if(nums[i] > nums[left] && ++j!=i){
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[left], nums[j]);
        return j;
    } 

    inline void randomChoose(vector<int>& nums, int left, int right) {
        srand((unsigned)time(NULL));
        int index = (rand() % (right-left+1))+ left;
        swap(nums[left], nums[index]);
    }

};