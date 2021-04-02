class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int> > a;
        for(auto i: nums) {
            a.push(i);
        }
        for(int i = 1; i < k; i++) {
            a.pop();
        }
        return a.top();
    }
};
