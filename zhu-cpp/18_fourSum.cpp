//
// Created by Ole on 2021/3/24 0024.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums,int target) {
        vector<vector<int>>r;
        if(nums.size()<4)
            return r;
        sort(nums.begin(),nums.end());
        for(int l = 0;l < nums.size() - 1 ;l++) {
            while (l >= 1 && l < nums.size() && nums[l] == nums[l - 1])
                l++;
            for (int i = l + 1; i < nums.size() ; i++) {
                while (i > l + 1 && i < nums.size() && nums[i] == nums[i - 1])
                    i++;
                int j = i + 1, k = nums.size() - 1;
                while (j < k) {
                    vector<int> t;
                    if (nums[j] + nums[k] + nums[i] + nums[l] == target) {
                        t.push_back(nums[l]);
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[k]);
                        r.push_back(t);
                        while (k > j && nums[k] == nums[k - 1])
                            k--;
                        k--, j++;
                    } else if (nums[j] + nums[k] + nums[i] + nums[l] > target) {
                        k--;
                    } else j++;
                }
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    int a[] = {5,5,3,5,1,-5,1,-2};
    vector<int> aa;
    vector<vector<int>> r;
    aa.assign(a,a+8);
    r = s.fourSum(aa,4);
    for(int i=0;i<r.size();i++) {
        for (int j = 0; j < r[0].size(); j++)
            cout << r[i][j] << " ";
        cout<<endl;
    }

    return 1;
}
//a+b=-c;