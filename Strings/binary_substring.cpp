#include<bits/stdc++.h>
using namespace std;

int maxsubstr(string s){
    int n= s.size();
    int count=0, c0=0,c1=0;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            c0++;
        }else if(s[i] == '1'){
            c1++;
        }
        if(c1 == c0){
            count++;
        }
    }
    if(count==0){
        return -1;
    }else {
        return count;
    }
}
int main()
{
    string str;
    cin>>str;
    cout<<maxsubstr(str);   
    return 0;
}