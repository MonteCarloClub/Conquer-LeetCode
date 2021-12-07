#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int ans = 0;
    unordered_map<int, int> length;

    int longestConsecutive(vector<int> &nums)
    {
        for (auto i : nums)
        {
            if (!length.count(i))
            {
                auto left = i - 1;
                auto right = i + 1;
                int leftLength = 0;
                int rightLength = 0;
                if (length.count(left))
                {
                    leftLength = length[left];
                }
                if (length.count(right))
                {
                    rightLength = length[right];
                }
                int updatedLength = leftLength + 1 + rightLength;
                ans = max(ans, updatedLength);
                length[i - leftLength] = updatedLength;
                length[i] = updatedLength;
                length[i + rightLength] = updatedLength;
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