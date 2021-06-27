#include<bits/stdc++.h>
using namespace std;

int countSquares(int N){
    int a= sqrt(N);
    if(a*a == N)
        return a-1;
    else 
        return a;
}
int main()
{
    int n;
    cin>>n;
    cout<<countSquares(n);
    return 0;
}