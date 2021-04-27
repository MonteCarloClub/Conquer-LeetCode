//
// Created by Oliver on 2021/4/27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> weights;
    int D;
    int shipWithinDays(vector<int>& weights, int D) {
        this->D = D;
        this->weights = weights;
        int sum = 0;
        int minp = 0;
        for(auto i:weights)
            minp = max(i,minp);
        int maxp = minp*weights.size()/D+1;
        return findbest(minp,maxp);
    }
    int isOK(int maxp)
    {
        int i,tD,temp;
        for(i=0,tD=1,temp = 0;i<weights.size();i++)
        {
            if(temp+weights[i]>maxp)
            {
                tD++;
                temp = weights[i];
            }
            else temp += weights[i];
        }
        if(tD<=D)
            return maxp;
        else return 0;
    }
    int findbest(int minp,int maxp)
    {
        if(isOK(minp))
            return minp;
        int midp = (maxp+minp)/2;
        if(isOK(midp))
            return findbest(minp+1,midp);
        else
            return findbest(midp+1,maxp);
    }

};

int main()
{
    vector<int> nums = {10,50,100,100,50,100,100,100};
    int D = 5;
    Solution s;
    cout<<s.shipWithinDays(nums,5);
    return 0;
}