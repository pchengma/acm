#include <iostream>
#include <string>
 
using namespace std;
 
/*
如22：twenty two，123：one hundred and twenty three。
说明：
数字为正整数，长度不超过九位，不考虑小数，转化结果为英文小写；
输出格式为twenty two；
非法数据请返回“error”；
关键字提示：and，billion，million，thousand，hundred。*/
 
string less1000(long num)
{
    string ret;
    string nums[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string twenty_ninety[8] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    string ten_nineteen[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    int b, t;
    if (num >= 100)
    {
        b = num / 100;
        num = num % 100;
        ret += (nums[b - 1] + " hundred");
        if(num > 0)
            ret += " and ";
    }
    if (num >= 20)
    {
        t = num / 10;
        num = num % 10;
//      if(!ret.empty())
//          ret += " and ";
        ret += twenty_ninety[t - 2];
        if(num > 0)
            ret += " ";
    }
    if (num >= 10)
    {
//      if (!ret.empty())
//          ret += " ";
        ret += ten_nineteen[num - 10];
        return ret;
    }
    if (num > 0)
    {
        ret += nums[num - 1];
    }
    return ret;
}
 
string parse(long num)
{
    if (num <= 0 || num > 999999999)
        return "error";
    int b, m, t;
    string ret;
    if (num >= 1000000000)
    {
        b = num / 1000000000;
        num = num % 1000000000;
        ret += (less1000(b) + " billion");
    }
    if (num >= 1000000)
    {
        m = num / 1000000;
        num = num % 1000000;
        if (!ret.empty())
            //  ret += " and ";
            ret += " ";
        ret += (less1000(m) + " million");
    }
    if (num >= 1000)
    {
        t = num / 1000;
        num = num % 1000;
        if (!ret.empty())
            //  ret += " and ";
            ret += " ";
        ret += (less1000(t) + " thousand");
    }
    if (num > 0)
    {
        if (!ret.empty())
        //ret += " and ";
            ret += " ";
        ret += less1000(num);
    }
 
    return ret;
}
 
int main()
{
    long num;
    while (cin >> num)
        cout << parse(num) << endl;
}

