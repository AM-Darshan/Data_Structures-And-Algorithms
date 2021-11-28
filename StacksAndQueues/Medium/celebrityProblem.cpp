#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

//O(n^2),O(n)
int celebrity_bf(vector<vector<int>> &mat,int n){
    int in[n]={0};
    int out[n]= {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1){
                in[j]++;
                out[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(in[i] == n-1 && out[i] == 0){
            return i;
        }
    }
    return -1;
}


#define N 8

// Person with 2 is celebrity
bool MATRIX[N][N] = {{0, 0, 1, 0},
                    {0, 0, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).

//O(n),O(n)
int findCelebrity(int n)
{
    // Handle trivial 
    // case of size = 2
    stack<int> s;

    // Celebrity
    int C; 

    // Push everybody to stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Extract top 2
 

    // Find a potential celebrity
    while (s.size() > 1)
    {   int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B))
        {
          s.push(B);
        }
        else
        {
          s.push(A);
        }
    }
    // If there are only two people 
    // and there is no
    // potential candicate
    if(s.empty())
        return -1;
  
  
    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually
    // a celebrity or not
    for (int i = 0; i < n; i++)
    {
        // If any person doesn't 
        // know 'C' or 'C' doesn't 
        // know any person, return -1
        if ( (i != C) &&
                (knows(C, i) || 
                 !knows(i, C)) )
            return -1;
    }

    return C;
}

int celebrity2(int n)
{
        // This function returns the celebrity
        // index 0-based (if any)

        int i = 0, j = n - 1;
        while (i < j) {
            if (MATRIX[j][i] == 1) // j knows i
                j--;
            else // j doesnt know i so i cant be celebrity
                i++;
        }
        // i points to our celebrity candidate
        int candidate = i;

        // Now, all that is left is to check that whether
        // the candidate is actually a celebrity i.e: he is
        // known by everyone but he knows no one
        for (i = 0; i < n; i++) {
            if (i != candidate) {
                if (MATRIX[i][candidate] == 0
                    || MATRIX[candidate][i] == 1)
                    return -1;
            }
        }
        // if we reach here this means that the candidate
        // is really a celebrity
        return candidate;
}

//O(n),O(1)
int celebrity(vector<vector<int>> &mat,int n){
    int c= 0;
    for(int i=1;i<n;i++){
        if(mat[c][i] == 1){
            c = i;
        }
    }

    for(int i=0;i<n;i++){
        if(i!=c && (mat[c][i] == 1 || mat[i][c] == 0))
            return -1;
    }
    return c;
}
int main()
{
    vector<vector<int>> mat={
                            {0,1,0},
                            {0,0,0},
                            {0,1,0}};
    cout<<celebrity(mat,3)<<endl;
    cout<<findCelebrity(4)<<endl;
    cout<<celebrity2(4);
    return 0;
}