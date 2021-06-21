#include<bits/stdc++.h>
using namespace std;

// Implement pow(x, n), which calculates x raised to the power n(i.e., x^n).
//-100.0 < x < 100.0
// - 2^31 <= n <= 2^31 - 1 
// - 10^4 <= xn <= 10^4 

double myPow(double x, int n)
{
    double ans=1.0;
    long long nn= n; //n value is reserved
    if(nn<0) 
        nn= -1*nn;
    while(nn){
        if(nn%2 == 1){
            ans= ans*x;
            nn= nn-1;
        }else{
            x= x*x;
            nn= nn/2;
        }
    }
    if(n<0) 
        ans= (double)(1.0)/ (double)(ans);
    return ans;
}
int main()
{
    double x;
    int n;
    cin>>x>>n;
    double res= myPow(x,n);
    cout<<res;
    return 0;
}