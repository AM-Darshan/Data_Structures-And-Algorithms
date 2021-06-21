#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n)
{
    int a,b;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0){
            a= abs(arr[i]);
        }
        else{
            arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            b= i+1;
            break;
        }
    }
    int *v= new int[2];
    v[0]= a;
    v[1]= b;
    return v;
}
int *findTwoElement1(int *arr, int n)
{
        // Sum of first n natural numbers
        long long int len = n;
        long long int Sum_N = (len * (len + 1)) / 2, Sum_NSq = (len * (len + 1) * (2 * len + 1)) / 6;
        long long int missingNumber = 0, repeating = 0;

        for (int i = 0; i <n; i++)
        {
            Sum_N -= (long long int)arr[i];
            Sum_NSq -= (long long int)arr[i] * (long long int)arr[i];
        }

        missingNumber = (Sum_N + Sum_NSq / Sum_N) / 2;
        repeating = missingNumber - Sum_N;
        int *ans= new int[2];
        ans[0] = repeating;
        ans[1]= missingNumber;
        return ans;
}
int main()
{
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        auto ans = findTwoElement1(arr, n);
        cout << ans[0] << " " << ans[1]<<endl;
        auto ans1 = findTwoElement(arr, n);
        cout << ans1[0] << " " << ans1[1] << endl;
        return 0;
}