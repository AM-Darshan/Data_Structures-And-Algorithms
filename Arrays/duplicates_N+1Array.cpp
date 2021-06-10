#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        nums[nums[i] % n] = nums[nums[i] % n] + n;
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] / n > 1)
            return i;
    }
    return -1;
}
int findDuplicate1(vector<int> nums)
{
    int n = nums.size();
    // we go on negating the number at the position nums[i]
    // so, we should have a positive number at position nums[i] if we are seeing it for the first time
    // if we encounter a negative number at nums[i] position, it means that we have already seen the number nums[i] before.
    // so we return abs(nums[i]) since nums[i] can be negtive if number 'i' was seen before
    for (int i = 0; i < n; i++)
    {
        if (nums[abs(nums[i])] < 0)
        {
            return abs(nums[i]);
        }
        else
        {
            nums[abs(nums[i])] *= -1;
        }
    }

    // Non functional block of code
    // By pigeon hole principle, there must be a duplicate in the array
    // So, function will return somewhere in the loop
    return -1;
}
int findDuplicateoptimal(vector<int> nums)
{
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];
        do
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
} 

void duplicate(vector<int> &num)
{
    set<int> seenNumbers;
    for (auto a : num)
    {
        if (seenNumbers.find(a) != seenNumbers.end())
        {
            cout<<a;
            return;
        }
        else
        {
            seenNumbers.insert(a);
        }
    }
    cout<<-1;
}
int main()
{
    int n,temp;
    cin >> n;
    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    //duplicate(array);
    cout << "duplicate number=>" << findDuplicateoptimal(array) << endl;
    return 0;
}