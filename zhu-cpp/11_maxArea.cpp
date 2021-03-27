//
// Created by Ole on 2021/3/23 0023.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,max=0;
        while(i<j)
        {
            int t = min(height[i],height[j])*(j-i);
            max = max>t?max:t;
            if(height[i]>height[j])
                j--;
            else i++;
        }
        return max;
    }
//    int maxArea(vector<int>& height) {
//        int left[33333],right[33333];
//        int indexl=0,indexr=0;
//        int max =0,max_l=0,max_r=0;
//        for(int i=0;i<height.size();i++)
//            if(max<height[i])
//            {
//                max = height[i];
//                left[indexl++] = i;
//            }
//        max=0;
//        for(int i=height.size()-1;i>=0;i--)
//            if(max<height[i])
//            {
//                max = height[i];
//                right[indexr++]=i;
//            }
//        max=0;
//        for(int i=0;i<indexl;i++)
//            for(int j=0;j<indexr;j++)
//            {
//                int t = (right[j]-left[i])*min(height[right[j]],height[left[i]]);
//                if(t<0)
//                    break;
//                max = max>t?max:t;
//            }
//        return max;
//    }
};

