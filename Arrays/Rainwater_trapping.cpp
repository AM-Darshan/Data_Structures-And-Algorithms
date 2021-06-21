#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &height) 
{
    if(height.size() <= 1)
        return 0;
    
    int size = height.size() - 1;

    // Let the first element be stored as
    // previous, we shall loop from index 1
    int prev = height[0];

    // To store previous wall's index
    int prev_index = 0;
    int water = 0;

    // To store the water until a larger wall
    // is found, if there are no larger walls
    // then delete temp value from water
    int temp = 0;
    for (int i = 1; i <= size; i++)
    {

        // If the current wall is taller than
        // the previous wall then make current
        // wall as the previous wall and its
        // index as previous wall's index
        // for the subsequent loops
        if (height[i] >= prev)
        {
            prev = height[i];
            prev_index = i;

            // Because larger or same
            // height wall is found
            temp = 0;
        }
        else
        {

            // Since current wall is shorter than
            // the previous, we subtract previous
            // wall's height from the current wall's
            // height and add it to the water
            water += prev - height[i];

            // Store the same value in temp as well
            // If we dont find any larger wall then
            // we will subtract temp from water
            temp += prev - height[i];
        }
    }

    // If the last wall was larger than or equal
    // to the previous wall then prev_index would
    // be equal to size of the array (last element)
    // If we didn't find a wall greater than or equal
    // to the previous wall from the left then
    // prev_index must be less than the index
    // of the last element
    if (prev_index < size)
    {

        // Temp would've stored the water collected
        // from previous largest wall till the end
        // of array if no larger wall was found then
        // it has excess water and remove that
        // from water variable
        water -= temp;

        // We start from the end of the array,
        // so previous should be assigned to
        // the last element
        prev = height[size];

        // Loop from the end of array up to the
        // previous index which would contain
        // the largest wall from the left
        for (int i = size; i >= prev_index; i--)
        {

            // Right end wall will be definitely
            // smaller than the 'previous index' wall
            if (height[i] >= prev)
            {
                prev = height[i];
            }
            else
            {
                water += prev - height[i];
            }
        }
    }

    // Return the maximum water
    return water;
}

int trap1(vector<int> &height) // extra space
{
    int n= height.size();
    int left[n],right[n];
    left[0]= height[0];
    for(int i=1;i<n;i++){
        left[i]= max(left[i-1],height[i]);
    }

    right[n-1]= height[n-1];
    for(int i=n-2;i>=0;i--){
        right[i]= max(right[i+1],height[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans+= min(left[i],right[i])- height[i];
    }
    return ans;
}
int main()
{
    int n, i;
    cin >>n;
    vector<int> arr;
    for (i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }
    cout<<trap1(arr);
    return 0;
}