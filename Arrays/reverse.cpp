#include <bits/stdc++.h>
using namespace std;
#define LP(i,a,b) for(int i=a;i<b;i++)

string reverseWord(string str)
{
    int low = 0, high = str.size() - 1;
    while (low < high)
    {
        char c = str[low];
        str[low] = str[high];
        str[high] = c;
        low++;
        high--;
    }
    return str;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    s= reverseWord(s);
    cout<<s;
    return 0;
}
