#include<bits/stdc++.h>
using namespace std;

void insert_bottom(stack<int>& st,int ele){
    if (st.size() == 0)
    {
        st.push(ele);
        return;
    }
    //Hypothesis
    int val = st.top();
    st.pop();
    insert_bottom(st, ele);
    //Induction
    st.push(val);
}
int main()
{
    stack<int> s;
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        s.push(rand() % 10 + 1);
        cout << s.top() << " ";
    }
    cout << endl;
    insert_bottom(s,20);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}