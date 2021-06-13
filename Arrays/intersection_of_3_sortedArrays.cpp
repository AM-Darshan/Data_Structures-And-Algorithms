#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i;
    unordered_map<int,int> h1,h2,h3;
    vector<int> temp;
    for(i=0;i<n1;i++)   
        h1[A[i]]++;
    for (i = 0; i < n2; i++)    
        h2[B[i]]++;
    for (i = 0; i < n3; i++)
        h3[C[i]]++;
    for(i=0;i<n1;i++){
        if (h3[A[i]] and h1[A[i]] and h2[A[i]])
        {
            temp.push_back(A[i]);
            h1[A[i]]=0;
        }
    }
    return temp;
}
vector<int> commonEleOptimal(int A[],int B[],int C[],int n1,int n2,int n3)
{
    int i=0,j=0,k=0;
    vector<int> v;
    while(i<n1 and j<n2 and k<n3){
        if(A[i] == B[j] and B[j] == C[k]){
            v.push_back(A[i]);
            i++;
            j++;
            k++;
        }else if(A[i]<B[j]){
            i++;
        }else if(B[j]<C[k]){
            j++;
        }else{
            k++;
        }
        int x= A[i-1];
        while(A[i] == x) i++;
        int y= B[j-1];
        while(B[j]==y) j++;
        int z= C[k-1];
        while(C[k]==z) k++;
    }
    if(v.size() == 0) return {-1};
    return v;
}
int main()
{
    int n1,n2,n3,i;
    cin>>n1>>n2>>n3;
    int a[n1], b[n2], c[n3];
    for(i=0;i<n1;i++) cin>>a[i];
    for (i = 0;i < n2; i++) cin>>b[i];
    for(i=0;i<n3;i++) cin>>c[i];
    vector<int> ans= commonElements(a,b,c,n1,n2,n3);
    for(i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    ans= commonEleOptimal(a,b,c,n1,n2,n3);
    cout<<endl;
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}