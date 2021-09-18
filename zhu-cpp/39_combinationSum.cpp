//
// Created by Oliver on 2021/6/16.
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
    vector<vector<int>>results;
    void bfs(vector<int>res,int sum,int target,vector<int>& candidates,int i)
    {
        if(sum==target)
            results.push_back(res);
        else
            if(sum<target)
            for(;i<candidates.size();i++)
            {
                res.push_back(candidates[i]);
                bfs(res,sum+candidates[i],target,candidates,i);
                res.pop_back();
            }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        bfs(res,0,target,candidates,0);
        return results;
    }
};
int main()
{
    vector<int>nums = {4,5,6,7,3,1,2};
    Solution s;
    vector<vector<int>>results = s.combinationSum(nums,10);
    for(vector<int>t:results)
    {
        for(int i:t)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 1;
}