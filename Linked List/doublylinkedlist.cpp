#include<bits/stdc++.h>
using namespace std;

// the class consists of one extra pointer previous
class node
{
    public:
    int data;
    node* next;
    node*prev;

    node(int val)
    {
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
void insertAtHead(node* &head,int val)
{
    node *temp=new node(val);
    temp->next=head;
    if(head!=nullptr)
    head->prev=temp;
    head=temp;
}

void insertAtTail(node* &head,int val)
{

    if(head==nullptr)
    {
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node*temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;

}

void deletion(node* &head,int pos)
{
    node *toBeDeleted,*temp=head;
    int count=1;
    while(temp!=nullptr)
    {
        if(count==pos)
        {
            toBeDeleted=temp;
        }
        temp=temp->next;
        count++;
    }
    if(toBeDeleted==head)
    {
        head=head->next;
        head->prev=nullptr;
        delete toBeDeleted;
    }
    toBeDeleted->prev->next=toBeDeleted->next;
    if(toBeDeleted->next!=nullptr)
    toBeDeleted->next->prev=toBeDeleted->prev;
}
void display(node* head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"->NULL\n";
}
int length(node *head)
{
    node *temp=head;
    int count=0;
    while(temp!=nullptr)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

node* appendKNodes(node* &head,int k)
{
    int len=length(head);
    node* newHead;
    node* newtail;
    node* tail=head;
    int count=1;
    k=k%len;
    while(tail->next!=nullptr)
    {
        if(count==len-k)
        {
            newtail=tail;
            newHead=tail->next;
        }
        count++;
        tail=tail->next;
    }
    newtail->next=nullptr;
    tail->next=head;

    return newHead;
}

int main()
{
    node *head=nullptr;
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,7);
    insertAtTail(head,9);
    insertAtTail(head,19);
    
    
    display(appendKNodes(head,3));


    return 0;
}