#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data= val;
        next= NULL;
    }
};
void insertAthead(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    n->next= head;
    head = n;
}
void insertTail(node* &head,int val){
    node* n= new node(val);
   
    if(head==NULL){
        head=n;
        return;
    }

    node* temp= head;
    while(temp->next != NULL){
        temp= temp->next;
    }
    temp->next= n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp= temp->next;
    }
    return false;
}
int main()
{
    node* head= NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    display(head);
    insertAthead(head,4);
    display(head);
    cout<<search(head,4)<<endl;
    cout<<search(head,7)<<endl;
    return 0;
}