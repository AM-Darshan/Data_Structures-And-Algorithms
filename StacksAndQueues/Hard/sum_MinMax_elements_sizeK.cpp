#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

int SumOfKsubArray(int arr[],int n,int k){
    
    deque<int> dq_max,dq_min;
    int sum=0;
    
    for(int i=0;i<n;i++){

        if(!dq_min.empty() && dq_min.front() == i-k)
            dq_min.pop_front();
        
        if (!dq_max.empty() && dq_max.front() == i - k)
            dq_max.pop_front();
        
        while(!dq_min.empty() && arr[dq_min.back()] > arr[i])
            dq_min.pop_back();
        
        while(!dq_max.empty() && arr[dq_max.back()] < arr[i])
            dq_max.pop_back();
        
        dq_min.push_back(i);
        dq_max.push_back(i);

        if(i >= k-1){
            cout<<"min: "<<arr[dq_min.front()]<<" max: "<<arr[dq_max.front()]<<"\n";
            sum+= arr[dq_min.front()]+arr[dq_max.front()];
        }
    }
    return sum;
}
int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k);
    return 0;
}