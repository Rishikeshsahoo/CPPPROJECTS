#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    
    node(int val)
    {
        data=val;
        next=nullptr;
    }
};

void insertAtHead(node *head,int val)
{
    node* n=new node(val);
    if(head==nullptr)
    {
        n->next=n;
        head=n;
        return;
    }
    node *temp=head;
    while()

}

void inserAtTail(node* &head,int val)
{
    if(head==nullptr)
    {
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;
    while(temp->next=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
int main()
{
    
    return 0;
}