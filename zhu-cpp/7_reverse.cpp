//
// Created by Ole on 2021/3/23 0023.
//

class Solution {
public:
    int reverse(int x) {
        int t = 0;
        int flag = 1;
        if(x<0)
            flag = 0;
        while(x!=0)
        {
            if(flag)
            {
                int mid = INT_MAX-x%10;
                if(mid%10 == 0)
                {
                    if(t>=mid/10)
                        return 0;
                }
                else
                if(t>mid/10)
                    return 0;
            }
            else
            {
                int mid = INT_MIN-x%10;
                if(mid%10 == 0)
                {
                    if(t<=mid/10)
                        return 0;
                }
                else
                if(t<mid/10)
                    return 0;
            }
            t = t*10+x%10;
            x/=10;
        }
        return t;
    }
};