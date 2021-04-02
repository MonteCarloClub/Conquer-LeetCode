//
// Created by Ole on 2021/3/23 0023.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    string getc(int i)
    {
        if(i==1)
            return "I";
        if(i==5)
            return "V";
        if(i==10)
            return "X";
        if(i==50)
            return "L";
        if(i==100)
            return "C";
        if(i==500)
            return "D";
        if(i==1000)
            return "M";
        if(i==4)
            return "IV";
        if(i==9)
            return "IX";
        if(i==40)
            return "XL";
        if(i==90)
            return "XC";
        if(i==400)
            return "CD";
        if(i==900)
            return "CM";
        return "";
    }
    string intToRoman(int num) {
        string r="";
        for(int i=0;i<num/1000;i++)
            r+=getc(1000);
        num%=1000;
        int ex = 1;
        if(num>=900)
        {
            r+=getc(900);
            num-=900;
        }
        else if(num>=500) {
            r += getc(500);
            num-=500;
        }
        else if(num>=400)
        {
            r+=getc(400);
            num-=400;
        }
        for(int i=0;i<num/100;i++)
            r += getc(100);
        num %= 100;
        if(num>=90)
        {
            r+=getc(90);
            num-=90;
        }
        else if(num>=50) {
            r += getc(50);
            num-=50;
        }
        else if(num>=40)
        {
            r+=getc(40);
            num-=40;
        }
        for(int i=0;i<num/10;i++)
            r += getc(10);
        num%=10;
        if(num>=9)
        {
            r+=getc(9);
            num-=9;
        }
        else if(num>=5) {
            r += getc(5);
            num-=5;
        }
        else if(num>=4)
        {
            r+=getc(4);
            num-=4;
        }
        for(int i=0;i<num;i++)
            r += getc(1);
        return r;
    }
};

int main()
{
    Solution s;
    int a =58;
    cout<<s.intToRoman(a)<<endl;
    return 1;
}