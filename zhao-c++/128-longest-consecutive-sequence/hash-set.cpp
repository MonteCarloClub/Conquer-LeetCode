#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int ans = 0;
    unordered_set<int> set;

    int longestConsecutive(vector<int> &nums)
    {
        for (auto i: nums)
        {
            set.emplace(i);
        }

        for (auto i: nums)
        {
            if (!set.count(i -1))
            {
                int temp = i;
                while (set.count(temp + 1))
                {
                    ++temp;
                }
                ans = max(ans, 1 + temp);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution solution{};
    cout << solution.longestConsecutive(nums);
}