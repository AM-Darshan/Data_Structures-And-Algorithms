#include <bits/stdc++.h>
using namespace std;
#define LP(i, a, b) for (int i = a; i < b; i++)


struct Pair{
    int max;
    int min;
};

struct Pair getmaxmin(int arr[],int low,int high){
    
    struct Pair minmax ,m1,m2;
    int mid;
    if(low == high){
        minmax.min= arr[low];
        minmax.max= arr[low];
        return minmax;
    }
    else if(high == low+1){
        if(arr[low]>arr[high]){
            minmax.max= arr[low];
            minmax.min= arr[high];
        }else{
            minmax.min = arr[low];
            minmax.max = arr[high];
        }
        return minmax;
    }
    mid =(low+high)/2;
    m1= getmaxmin(arr,low,mid);
    m2= getmaxmin(arr,mid+1,high);

    if(m1.min < m2.min){
        minmax.min= m1.min;
    }else{
        minmax.min= m2.min;
    }

    if(m1.max > m2.max){
        minmax.max= m1.max;
    }else{
        minmax.max= m2.max;
    }
    return minmax;
}
void method2(int a[],int n){
    int max,min,i;
    if(n%2==0){
        if(a[0]>a[1]){
            max= a[0];
            min= a[1];
        }else{
            min= a[0];
            max=a[1];
        }
        i=2;
    }else{
        max=min=a[0];
        i=1;
    }
    while(i<n-1){
        if(a[i] > a[i+1]){
           if(a[i]>max){
               max=a[i];
           }
           if(a[i+1]<min){
               min= a[i+1];
           }
        }else{
            if(a[i+1]>max){
                max= a[i+1];
            }
            if(a[i]< min){
                min= a[i];
            }
        }
        i+=2;
    }
    cout<<"Max: "<<max<<"\nMin: "<<min<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    LP(i,0,n){
        cin>>a[i];
    }
    //method2(a,n);
    struct Pair p1;
    p1= getmaxmin(a,0,n-1);
    cout<<p1.max<<" "<<p1.min;
    
    return 0;
}