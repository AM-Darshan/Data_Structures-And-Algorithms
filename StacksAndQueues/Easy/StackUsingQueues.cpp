/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>
//https://leetcode.com/problems/implement-stack-using-queues/
//https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1
using namespace std;

class Stack1 {
	// Two inbuilt queues
	queue<int> q1, q2;

	// To maintain current number of
	// elements
	int curr_size;

public:
	Stack1()
	{
		curr_size = 0;
	}

	void push(int x)
	{
		curr_size++;

		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{

		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
		curr_size--;
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size()
	{
		return curr_size;
	}
};


class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ele= q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};


// Driver code
int main()
{
	MyStack s;
	s.push(1);
	s.push(2);
	s.push(3);

	// cout << "current size: " << s.size()
	// 	<< endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	// cout << "current size: " << s.size()
	// 	<< endl;
	return 0;
}

