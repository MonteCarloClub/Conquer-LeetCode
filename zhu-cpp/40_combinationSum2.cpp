//
// Created by Oliver on 2021/9/18.
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
    void sbfs(vector<int>res,int sum,vector<int>& candidates,int i)
    {
        if(sum==0)
            results.push_back(res);
        else
        if(sum>0)
            for(;i<candidates.size();i++)
            {
                if(i>0&&candidates[i]==candidates[i-1])
                    continue;
                res.push_back(candidates[i]);
                bfs(res,sum-candidates[i],candidates,i);
                res.pop_back();
            }
    }
    void bfs(vector<int>res,int sum,vector<int>& candidates,int i)
    {
        if(sum==0)
            results.push_back(res);
        else
        if(sum>0)
            for(int j = i+1;j<candidates.size();j++)
            {
                if(j>i&&candidates[j]==candidates[j-1])
                    continue;
                res.push_back(candidates[j]);
                bfs(res,sum-candidates[j],candidates,j);
                res.pop_back();
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        sbfs(res,target,candidates,0);
        return results;
    }
};
int main()
{
    vector<int>nums = {10,1,2,7,6,1,5};
    Solution s;
    vector<vector<int>>results = s.combinationSum2(nums,8);
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
