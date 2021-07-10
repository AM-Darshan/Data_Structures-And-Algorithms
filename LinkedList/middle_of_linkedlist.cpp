#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Linkedlist
{
public:
    void insertTail(node *&head, int val)
    {
        node *n = new node(val);

        if (head == NULL)
        {
            head = n;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

node* middleNode(node* head)
{
    node* slow =head,*fast =head;
    while (fast != NULL && fast->next != NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}
int main()
{
    node *head = NULL;
    Linkedlist ll;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ll.insertTail(head, x);
    }
    node* ans= middleNode(head);
    cout<< ans->data;
    return 0;
}