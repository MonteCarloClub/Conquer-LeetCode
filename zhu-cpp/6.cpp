//
// Created by Ole on 2021/3/23 0023.
//

class Solution {
public:
    string convert(string s, int numRows) {
        string lines[1111];
        int y = numRows*2-2;
        if(numRows == 1)
            return s;
        for(int i=0;i<s.length();i++)
        {
            if(i%y==0)
                lines[0]+=s[i];
            else if(i%y == numRows-1)
                lines[numRows-1]+=s[i];
            else
            {
                if(i%y>numRows-1)
                    lines[y-(i%y)]+=s[i];
                else lines[i%y]+=s[i];
            }
        }
        string r="";
        for(int i=0;i<numRows;i++)
            r+=lines[i];
        return r;
    }
};

//3 4
//4 6
//5 8
//x y= 2*x-2