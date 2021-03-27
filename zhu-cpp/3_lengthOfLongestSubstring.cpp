//
// Created by Ole on 2021/3/23 0023.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "")
            return 0;
        int i = 0;
        int j = 1;
        int flag[222];
        for(int i=0;i<222;i++)
            flag[i]=0;
        int maxlen = 1;
        int len = 1;
        flag[s[i]] = 1;
        while(j<s.length())
        {
            while(flag[s[j]])
            {
                flag[s[i]] = 0;
                len--;
                i++;
            }
            flag[s[j]] = 1;
            len++;
            if(len>maxlen)
                maxlen = len;
            j++;
        }
        return maxlen;
    }
};