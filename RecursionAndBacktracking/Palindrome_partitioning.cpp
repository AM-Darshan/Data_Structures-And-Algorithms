#include<bits/stdc++.h>
using namespace std;

class SolutionDP
{
public:
    vector<vector<string>> partition(string s)
    {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>> &result, string &s, int start, vector<string> &currentList, vector<vector<bool>> &dp)
    {
        if (start >= s.length())
            result.push_back(currentList);
        for (int end = start; end < s.length(); end++)
        {
            if (s[start] == s[end] && (end - start <= 2 || dp[start + 1][end - 1]))
            {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, currentList, dp);
                currentList.pop_back();
            }
        }
    }
};

class SolutionBacktrack
{
    public:
        vector<vector<string>> partition(string s)
        {
            vector<vector<string>> res;
            vector<string> path;
            func(0, s, path, res);
            return res;
        }
        void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
        {
            if (index == s.size())
            {
                res.push_back(path);
                return;
            }
            for (int i = index; i < s.size(); i++)
            {
                if (isPalindrome(s, index, i))
                {
                    path.push_back(s.substr(index, i - index + 1));
                    func(i + 1, s, path, res);
                    path.pop_back();
                }
            }
        }
        bool isPalindrome(string s, int start, int end)
        {
            while (start <= end)
            {
                if (s[start++] != s[end--])
                    return false;
            }
            return true;
        }
};





int main()
{
    string str;
    cin>>str;
    SolutionBacktrack s;
    SolutionDP sdp;
    //vector<vector<string>> ans= s.partition(str);
    vector<vector<string>> ans = sdp.partition(str);
    cout << "{ ";
    for (auto const &string_vec : ans){
        cout<<"[";
        for (auto const &s : string_vec){
            cout <<"'"<< s <<"' ";
        }
        cout << "], ";
    }
    cout << "}";
    return 0;
}