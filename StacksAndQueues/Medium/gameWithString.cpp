#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/game-with-string4100/1
int minValue(string s, int k)
{
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i]]++;
    }
    priority_queue<int> pq;
    for (auto m : mpp)
    {
        pq.push(m.second);
    }

    while (k)
    {
        int x = pq.top();
        pq.pop();
        x--;
        pq.push(x);
        k--;
    }

    int sum = 0;
    while (!pq.empty())
    {
        int d = pq.top();
        sum += (d * d);
        pq.pop();
    }
    return sum;
}

int main()
{
    string s = "aabcbcbcabcc";
    int k=3;
    cout<<minValue(s,k);
    return 0;
}