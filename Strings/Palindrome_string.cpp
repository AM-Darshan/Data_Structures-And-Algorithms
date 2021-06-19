#include<bits/stdc++.h>
using namespace std;

int isPlaindrome(string s)
{
    int n= s.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        if(s[low] != s[high]){
            return 0;
        }
        low++;
        high--;
    }
    return 1;
}
int main()
{
    string str;
    cin>>str;
    cout<<isPlaindrome(str);
    return 0;
}