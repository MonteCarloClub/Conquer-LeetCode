//
// Created by Ole on 2021/4/24 0024.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> nums;
        if (s == "" || s == "（" || s == ")")
            return 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                nums.push_back(1);
            else
                nums.push_back(0);
        }
        while (1)
        {
            int flag =1;
            for(int i=0;i<nums.size()-1;i++)
            {
                if(nums[i]==1) {
                    int add = 2;
                    for (int j = i + 1; j < nums.size(); j++) {
                        if (nums[j] == 1) {
                            i = j - 1;
                            break;
                        } else if (nums[j] > 1)
                            add += nums[j];
                        else if (nums[j] == 0) {
                            flag = 0;
                            nums[i] = add;
                            for (int k = i + 1; k <= j; k++)
                                nums.erase(nums.begin() + i+1);
                            break;
                        }
                    }
                }
            }
            if(flag)
                break;
        }
        int maxn = 0;
        int t = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>1)
            {
                t+=nums[i];
                maxn = max(maxn,t);
            }
            else
                t = 0;
        }
        return maxn;
    }
};

int main()
{
    Solution s;
    cout<<s.longestValidParentheses("()(())");
    return 1;
}
