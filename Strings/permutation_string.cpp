#include<bits/stdc++.h>
using namespace std;

vector<string> find_permutation(string S)
{
    vector<string> ans;
    sort(S.begin(),S.end());
    ans.push_back(S);
    while(next_permutation(S.begin(),S.end())){
        ans.push_back(S);
    } 
    return ans;
}
void permute(string s, string answer)
{
    if (s.length() == 0)
    {
        cout << answer << "  ";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string rest = s.substr(0, i) + s.substr(i + 1);
        permute(rest, answer + ch);
    }
}
int main()
{
    string str;
    cin>>str;
    vector<string> ans= find_permutation(str);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    } 
    permute(str,"");
    return 0;
}