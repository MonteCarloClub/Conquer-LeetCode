//
// Created by Ole on 2021/3/23 0023.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool compare(char a,char b)
    {
        if(b == '.')
            return true;
        return a==b;
    }
    string calstr(string p)
    {
        string r;
        for(int i=0;i<p.length();) {
            r+=p[i];
            if (p[i] == '*') {
                int j = i+1;
                while(j+1<p.length()&&p[i-1]==p[j]&&p[j+1] == '*') {
                        j+=2;
                }
                i=j;
                continue;
            }
            i++;
        }
        return r;
    }
    string c1(string s)
    {
        return s.substr(1,s.length()-1);
    }
    string c2(string s)
    {
        return s.substr(2,s.length()-2);
    }
    bool isMatch(string s, string p) {
        p = calstr(p);
        int i=0;
        if(s==""&&p=="")
            return true;
        else if(s=="") {
            if(p.length()>1&&p[1]=='*')
                return isMatch(s,c2(p));
            return false;
        }
        if(compare(s[i],p[i])) {
            if (p[i + 1] == '*'&&p.length()>1)
                return isMatch(c1(s), p)||isMatch(c1(s),c2(p))||isMatch(s,c2(p));
            else
                return isMatch(c1(s),c1(p));

        }
        else if(p.length()>1&&p[i + 1] == '*')
            return isMatch(s,c2(p));
        return false;
    }

//    bool isMatch(string s, string p) {
//        p = calstr(p);
//        int i=0,j=0;
//        while(i<s.length()&&j<p.length())
//        {
//            if(p[j+1]=='*')
//            {
//                while(compare(s[i],p[j])&&i<s.length())
//                    i++;
//                j+=2;
//                continue;
//            }
//            else if(!compare(s[i],p[j]))
//                return false;
//            i++;
//            j++;
//        }
//        return i==s.length()&&j==p.length();
//    }

};

int main()
{
    Solution s;
    cout<<s.isMatch( "aaaaaaaaaaaaab","a*a*a*a*a*a*a*a*a*a*c")<<endl;//0
    cout<<s.isMatch( "a",".*..a*")<<endl;//0
    cout<<s.isMatch( "mississippi", "mis*is*p*.")<<endl;//0
    cout<<s.isMatch( "a", "ab*")<<endl;//1
    cout<<s.isMatch( "111", "1*11")<<endl;//1
    cout<<s.isMatch( "aa", "a*")<<endl;//1
    cout<<s.isMatch("aaa","ab*a*c*a")<<endl;//1
    cout<<s.isMatch( "12", ".*0")<<endl;//0
    cout<<s.isMatch( "aa", "a")<<endl;//0
    cout<<s.isMatch( "ab", ".*")<<endl;//1
    return 1;
}