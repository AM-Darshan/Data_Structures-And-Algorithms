#include<bits/stdc++.h>
using namespace std;

int rotate(string s1,string s2){
    if(s1.length()!=s2.length()){
        return 0;
    }
    string temp = s1+s1;
    return (temp.find(s2) != string::npos);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<rotate(s1,s2);
    return 0;
}