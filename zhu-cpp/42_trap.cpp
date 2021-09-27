//
// Created by Oliver on 2021/9/26.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=1,sum=0,part=0;
        for(;j<height.size();j++)
        {
            if(height[i]>height[j])
                part+=height[i]-height[j];
            else
            {
                sum+=part;
                part=0;
                i=j;
            }
        }
        int k=i;
        for(i=height.size()-1,part=0,j--;j>=k;j--)
        {
            if(height[i]>height[j])
                part+=height[i]-height[j];
            else
            {
                sum+=part;
                part=0;
                i=j;
            }
        }
        return sum;
    }
};
int main()
{
    vector<int>nums = {4,2,3};
    Solution s;
    int results = s.trap(nums);
    cout<<results;
    return 1;
}
