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

int main()
{
    node *head=nullptr;
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,7);
    insertAtTail(head,9);
    insertAtTail(head,19);
    display(head);
    deletion(head,3);
    display(head);
    return 0;
}