#include<bits/stdc++.h>
using namespace std;

int maxProfitbrute(vector<int> &prices)
{
    int min=0,profit=0;
    min=prices[0];
    for(int i=1;i<prices.size();i++){
        if(prices[i]-min<0){
            min= prices[i];
        }else{
            profit= max(profit, prices[i]- min);
        }
    }
    return profit;
}
int maxProfit(vector<int> &prices){

    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    return maxPro;
} 

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<maxProfitbrute(arr)<<endl;
    cout<<maxProfit(arr);
    return 0;
}