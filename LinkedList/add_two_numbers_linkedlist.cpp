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

//leetcode
node* addTwoLists(node *first, node *second)
{
    node *dummy = new node(0);
    node* temp= dummy;
    node* add= NULL;
    int carry=0;
    while(first!=NULL || second!=NULL){
        int sum=0;
        if(first!=NULL){
            sum+= first->data;
            first= first->next;
        }
        if(second!=NULL){
            sum+= second->data;
            second= second->next;
        }
        sum+= carry;
        carry= sum/10;
        add= new node(sum%10);
        temp->next= add;
        temp= temp->next;
    }
    if (carry > 0)
    {
        temp->next = new node(carry);
    }
    return dummy->next;
}


//GFG
node *reverse1(node *cur)
{
    node *prev = NULL;
    node *nex;
    while ((cur) != NULL)
    {
        nex = (cur)->next;
        (cur)->next = prev;
        prev = (cur);
        (cur) = nex;
    }
    (cur) = prev;
    return cur;
}
node* addTwoListsgfg(node *first, node *second)
{
    first = reverse1(first);
    second = reverse1(second);
    int c = 0;
    int s = 0;
    node *temp;
    node *res = NULL;
    node *cur = NULL;
    while (first != NULL || second != NULL)
    {
        s = c + (first ? first->data : 0) + (second ? second->data : 0);
        c = (s >= 10) ? 1 : 0;
        s = s % 10;
        temp = new node(s);
        if (res == NULL)
            res = temp;
        else
            cur->next = temp;
        cur = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (c > 0)
    {
        temp = new node(c);
        cur->next = temp;
        cur = temp;
    }
    res = reverse1(res);
    return res;
}


int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    Linkedlist ll;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ll.insertTail(head1, x);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        ll.insertTail(head2, x);
    }
    node *ans = NULL;
    //ans = addTwoLists(head1, head2);
    ans= addTwoListsgfg(head1,head2);
    ll.display(ans);
    return 0;
}