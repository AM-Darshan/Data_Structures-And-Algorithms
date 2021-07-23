#include<bits/stdc++.h>
using namespace std;


int main()
{
    //binary serach function
    int a[]= {1,4,5,8,9,9};
    int n = sizeof(a)/sizeof(a[0]);
    bool res= binary_search(a,a+n,3); //0
    cout<<res<<"\n";
    cout<<binary_search(a, a + n, 4)<<endl;   //1

    //lower_bound, returns index of the 1st occurance of element
    // else if not found return next index value
    cout<<"lower_bound";
    int ind= lower_bound(a,a+n,4) - a; //1
    cout<<ind<<endl;
    cout<<lower_bound(a,a+n,7) - a<<"\n"; //3
    cout<<lower_bound(a, a + n, 10) - a<<"\n";  //6

    vector<int> a1={1,4,5,8,9,9};
    ind= lower_bound(a1.begin(),a1.end(),5) - a1.begin();  //2
    cout<<ind<<endl;

    //upper bound, returns index+1(next index) of the 1st occurance of element
    // else if not found return next index value
    cout<<"upper_bound";
    ind = upper_bound(a, a + n, 4) - a; //2
    cout << ind << endl;
    cout << upper_bound(a, a + n, 7) - a << "\n";  //3
    cout << upper_bound(a, a + n, 10) - a << "\n"; //6

    cout<<upper_bound(a1.begin(), a1.end(), 5) - a1.begin()<<endl; //3

    //TC: log(n)-> lower and upper bound functions

    //find the first occurrence of a X in a sorted array.
    //If it does not exist, print -1
    cout<<"first occurance"<<endl;
    int A[]= {1,4,4,4,4,9,9,10,11};
    int n1 = sizeof(A) / sizeof(A[0]);
    int x= 4; //4->1, 2->-1, 10->-1
    int find= lower_bound(A,A+n1,x) - A;

    if(ind!=n && a[find] == x)
        cout<<find<<endl;
    else
        cout<<-1<<endl;

    //Find the last occurance of a X in a sorted array
    //else print -1
    cout<<"last occurance"<<endl;
    x=4;
    find= upper_bound(A,A+n1,x)- A;
    find--;
    if(ind>=0 && A[find] == x)
        cout << find << endl;
    else
        cout << -1 << endl;

    //Find the largest number smaller then X in a sorted array
    //if no number exists print -1
    cout<<"largest no. smaller than X"<<endl;
    x=9;
    find= lower_bound(A,A+n1,x)-A;
    find--;
    if(find>=0)
        cout<<A[find]<<endl;
    else    
        cout<<-1<<endl;

    //Find the smallest number greater then X in a sorted array
    //if no number exists print -1
    cout << "samllest no. greater than X" << endl;

    x=10;
    find= upper_bound(A,A+n1,x)-A;

    if(find<n1)
        cout<<A[find]<<endl;
    else
        cout<<-1<<endl;
    return 0;
}