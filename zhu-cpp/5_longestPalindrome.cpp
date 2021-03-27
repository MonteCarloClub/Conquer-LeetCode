//
// Created by Ole on 2021/3/23 0023.
//

class Solution {
public:
    string findchar(string s,int a,int b)
    {
        string r = s.substr(a,b-a+1);
        int start=a-1,end=b+1;
        while(start>=0&&end<s.length())
        {
            if(s[start]!=s[end])
                break;
            r = s[start]+r+s[end];
            start--;
            end++;
        }
        return r;
    }
    string longestPalindrome(string s) {
        int len = s.length();
        int start,end;
        string r = "";
        for(int i=0;i<len;i++)
        {
            string t = "";
            int j =i;
            while(s[j]==s[i])
                j++;
            t = findchar(s,i,j-1);
            if(t.length()>r.length())
                r=t;
        }
        return r;
    }
};