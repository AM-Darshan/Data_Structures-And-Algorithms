// C++ program to merge k sorted
// arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;
};

/* Function to print nodes in
a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"null";
}

Node* sMerge(Node *a,Node *b){
    Node *result= NULL;
    if(a==NULL){
        return b;
    }else if(b==NULL){
        return a;
    }
    if(a->data <= b->data){
        result= a;
        result->next = sMerge(a->next,b);
    }
    else{
        result= b;
        result->next= sMerge(a,b->next);
    }
    return result;
}
// The main function that
// takes an array of lists
// arr[0..last] and generates
// the sorted output
Node *mergeKLists(Node *arr[], int K)
{
    int i=0;
    int last= K-1;
    int j;
    while(last!=0){
        i=0;
        j=last;
        while(i<j){
            arr[i]= sMerge(arr[i],arr[j]);
            i++;
            j--;
            if(i>=j){
                last= j;
            }
        }
    }
    return arr[0];
}

// Utility function to create a new node.
Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Driver program to test
// above functions
int main()
{
    // Number of linked lists
    int k = 3;

    // Number of elements in each list
    int n = 4;

    // an array of pointers storing the
    // head nodes of the linked lists
    Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge all lists
    Node *head = mergeKLists(arr, k - 1);

    printList(head);

    return 0;
}
