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


node* MergeBoth(node* first, node* second){
     node* ans= NULL;
     
    if(!first)
        return second;
    else if(!second)
        return first;
    
    if(first->data <= second->data){
        ans= first;
        ans->next= MergeBoth(first->next, second);
    }
    else{
        ans= second;
        ans->next= MergeBoth(first,second->next);
    }
    return ans;
}
void FindMiddle(node* cur,node** first,node** second){
    node *slow = cur, *fast = cur->next;
    while(fast!=NULL){
        fast= fast->next;
        if(fast!=NULL){
            slow= slow->next;
            fast= fast->next;
        }
    }
    *first= cur;
    *second= slow->next;
    slow->next= NULL;

}
void MergeSorting(node** head)
{
    node* cur= *head;
    node* first;
    node* second;
    if(!cur || !cur->next)
        return;

    FindMiddle(cur,&first,&second);

    MergeSorting(&first);
    MergeSorting(&second);
    *head= MergeBoth(first,second);
}
node *mergeSort(node *head)
{
    MergeSorting(&head);
    return head;
}
int main()
{
    node *head = NULL;
    Linkedlist ll;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ll.insertTail(head, x);
    }
    head = mergeSort(head);
    ll.display(head);
    return 0;
}