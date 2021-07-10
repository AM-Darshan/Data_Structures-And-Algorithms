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

node* removeNthFromEnd(node* head, int n)
{
    node* start = new node(0); // dummy node
    start->next =head;
    node* fast= start;
    node* slow= start;
    for(int i=1;i<=n;i++){
        fast= fast->next;
    }
    while (fast->next != NULL)
    {
       fast= fast->next;
       slow= slow->next;
    }
    node* del= slow->next;
    slow->next= slow->next->next;
    delete(del);
    return start->next;
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
    cin >> k;
    head= removeNthFromEnd(head,k);
    ll.display(head);
    return 0;
}