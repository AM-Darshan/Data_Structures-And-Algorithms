#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/special-stack/1
//https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
//https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

class specialStack{

int minn = 99999;
stack<int> s;

public:
void push(int a){
	if(s.empty()){
	    minn = a;
	    s.push(a);
	}
	else{
	    int x = a;
	    if(a < minn){
	        x = a + (a - minn);
	        minn = a;
	    }
	    s.push(x);
	}
}

bool isFull(int n){
	if(s.size() == n) return true;
	else return false;
}

bool isEmpty(){
	if(s.empty()) return true;
	else return false;
}

int pop(){
	int val= s.top();
	if(val < minn){
	    int y = 2*minn - val;
	    minn = y;
	    s.pop();
        return val;
	}
	else{
	    s.pop();
        return val;
    }
}

int getMin(){
	return minn;
}
};
int main()
{   
    specialStack sp;
    sp.push(2);
    sp.push(5);
    cout<<sp.getMin();
    sp.push(1);
    sp.push(6);
    cout<<sp.getMin();
    sp.pop();
    sp.pop();
    sp.push(0);
    cout<<sp.getMin();
    return 0;
}