#include<bits/stdc++.h>
using namespace std;

int multiple(int x, int res[],int size){
    int carry=0;
    for(int i=0;i<size;i++){
        int prod= res[i]*x + carry;
        res[i]= prod%10;
        carry= prod/10;
    }
    while(carry){
        res[size]= carry%10;
        carry= carry/10;
        size++;
    }
    return size;
}
vector<int> factorial(int n){
    int i,vsize=1;
    vector<int> ans;
    int res[10000];
    res[0]=1;
    for(i=2;i<=n;i++){
        vsize= multiple(i,res,vsize);
    }
    for(i=vsize-1;i>=0;i--){
        ans.push_back(res[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> vi= factorial(n);
    for(int i=0;i<vi.size();i++){
        cout<<vi[i];
    }
    return 0;
}