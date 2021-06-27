#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string result;
    cin>>result;
    int l1= s1.length();
    int l2= s2.length();
    int lr= result.length();
    if((l1+l2) != lr)
        cout<<"NO";
    else{
        int flag=0;
        int i=0,j=0,k=0;
        while(k<lr){
            if(i<l1 && s1[i]== result[k]) 
                i++;
            else if(j<l2 && s2[j] == result[k]) 
                j++;
            else{
                flag=1;
                break;
            }
            k++;
        }
        if(i<l1 or j<l2)
            cout<<"NO";
        else 
            cout<<"YES";
    }
    return 0;
}