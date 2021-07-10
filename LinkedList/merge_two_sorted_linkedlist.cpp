#include <bits/stdc++.h>
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

node *mergeTwoLists(node *l1, node *l2)
{
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    if(l1->data > l2->data){
        swap(l1,l2);
    }
    node* res= l1;
    while(l1!=NULL && l2!=NULL){
        node* temp =NULL;
        while(l1!=NULL && l1->data<=l2->data){
            temp= l1;
            l1= l1->next;       
        }
        temp->next= l2;
        swap(l1,l2);
    }
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
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        ll.insertTail(head2, x);
    }
    node *ans= NULL;
    ans= mergeTwoLists(head1,head2);
    ll.display(ans);
    return 0;
}