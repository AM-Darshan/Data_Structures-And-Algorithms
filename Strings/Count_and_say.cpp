#include<bits/stdc++.h>
using namespace std;



string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    if (n == 2)
    {
        return "11";
    }
    string result = countAndSay(n - 1);
    string newresult = "";
    int count = 1;
    for (int i = 1; i < result.size(); ++i)
    {
        if (result[i] != result[i - 1])
        {
            newresult.push_back('0' + count);
            newresult.push_back(result[i - 1]);
            count = 1;
        }
        else
        {
            count++;
        }
        if (i == result.size() - 1)
        {
            newresult.push_back('0' + count);
            newresult.push_back(result[i]);
        }
    }
    return newresult;
}
string countAndSay1(int n)
{
    if(n == 1)
        return "1";
    if(n == 2)
        return "11";
    string s="11";
    for(int i=3;i<=n;i++){
        string t="";
        s= s + '&';
        int c=1;
        for(int j=1;j<s.length();j++){
            if(s[j] != s[j-1]){
                t= t + to_string(c);
                t= t+ s[j-1];
                c=1;
            }else{
                c++;
            }
        }
        s=t;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    cout<<countAndSay(n);
    return 0;
}