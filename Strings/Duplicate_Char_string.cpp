#include<bits/stdc++.h>
using namespace std;

void printDuplicate(string s){
    int i,n=s.size();
    unordered_map<char,int> count;
    for(i=0;i<n;i++)
        count[s[i]]++;
    for(auto it : count){
        if(it.second >1)
            cout<<it.first<<" "<<it.second<<"\n";
    }
}
int main()
{
    string s;
    cin>>s;
    printDuplicate(s);
    return 0;
}