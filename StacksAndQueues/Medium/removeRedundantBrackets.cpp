#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/

bool checkRedundancy(string &str)
{
    // create a stack of characters
    stack<char> st;

    // Iterate through the given expression
    for (auto &ch : str)
    {

        // if current character is close parenthesis ')'
        if (ch == ')')
        {
            char top = st.top();
            st.pop();

            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;

            while (!st.empty() and top != '(')
            {

                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;

                // Fetch top element of stack
                top = st.top();
                st.pop();
            }

            // If operators not found
            if (flag == true)
                return true;
        }

        else
            st.push(ch); // push open parenthesis '(',
                         // operators and operands to stack
    }
    return false;
}

// Function to check redundant brackets
void findRedundant(string &str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}


void func(string s){
    
    stack<char> st;
    int i;
    
    for(i=0;i<s.length();i++){
        if(s[i]!=')')
            st.push(s[i]);
        else{
            if(st.top() == '('){
                cout<<"YES\n";
                break;
            }
            else{
                while(st.top()!='(')
                    st.pop();
                st.pop();
            }
        }
    }

    if(i==s.length())
        cout<<"NO\n";
}
int main()
{
    string str = "((b*c)*(a/b))";
    cout << str << endl;
    findRedundant(str);
    func(str);

    str = "((a+b))";
    cout << str<<endl;
    findRedundant(str);
    func(str);

    str = "(a+(b)/c)";
    cout << str << endl;
    findRedundant(str);
    func(str);

    str = "(a+b*(c-d))";
    cout << str << endl;
    findRedundant(str);
    func(str);

    return 0;
}