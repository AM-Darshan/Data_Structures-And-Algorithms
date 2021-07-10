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

class Linkedlist{
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

node* reverselist(node* head){
    node *newhead= NULL;
    while(head != NULL){
        node* nextnode= head->next;
        head->next= newhead;
        newhead= head;
        head= nextnode;
    }
    return newhead;
}

node* reverse_rec(node* head){
    if(head == NULL || head->next==NULL)
        return head;
    node* temp= reverse_rec(head->next);
    head->next->next= head;
    head->next= NULL;
    return temp;
}
int main()
{
    node *head = NULL;
    Linkedlist ll;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ll.insertTail(head,x);
    }
    //head= reverselist(head);
    head= reverse_rec(head);
    ll.display(head); 
    return 0;
}