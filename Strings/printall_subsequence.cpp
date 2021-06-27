#include<bits/stdc++.h>
using namespace std;

void printSubsquence(string t,int i,int len,string s){
    if(i == len){
        cout<<t<<endl;
    }else{
        printSubsquence(t,i+1,len,s);
        t= t+s[i];
        printSubsquence(t,i+1,len,s);
    }
}
int main()
{
    string str;
    cin>>str;
    printSubsquence("",0,str.length(),str);
    return 0;
}