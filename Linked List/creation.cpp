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

/*takes head ptr as reference because we need 
to change the position of head in this finction*/
void insertAtTail(node * &head, int val)
{
    node * n=new node(val);
    if(head==nullptr)
    {
        head=n;
        return;
    }
    node * temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=n;
}

/*takes head ptr as reference because we need 
to change the position of head in this finction*/
void insertAtHead(node * &head,int val)
{
    node * n=new node(val);
    n->next=head;
    head=n;
}

/*does not take head as reference because we just
want to traverse in the list we dont want to change it*/
void display(node * head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}

/* traverse till one node before the required node
and set it next to next and delete the middle one */
void deletion(node* &head,int key)
{
    cout<<"yo\n";
    if(head==nullptr)
    {
        cout<<"underflow\n";
        return;
    }
    if(head->data==key)
    {
        node *tobedeleted=head;
        head=head->next;
        delete tobedeleted;
        return;
    }
    node *temp=head;
    while(temp->next!=nullptr)
    {
        if(temp->next->data==key)
        {
            node *tobedeleted = temp->next;
            if(tobedeleted->next!=nullptr)
            temp->next=tobedeleted->next;
            else temp->next=nullptr;
            delete tobedeleted;
            return;
            
        }
        temp=temp->next;
    }
    
    
}
//iterative approach to reverse a LL
node* iReverse(node* head)
{
    node *previous=nullptr;
    node *current=head;
    node *after ;

    //any other permutation of steps may cause serious problems
    while(current!=nullptr)
    {
        after=current->next;
        current->next=previous;

        previous=current;
        current=after;
    }
    return previous;

}

//recursive approach of reversal of a LL
node* rReverse(node* head)
{
    if(head==nullptr || head->next==nullptr)
    return head;

    node* newhead=rReverse(head->next);

    head->next->next=head;
    head->next=nullptr;

    return newhead;
} 

node* reverseKNodes(node* & head,int k)
{
    node* currentptr=head;
    node* previous=nullptr;
    node* nextptr;
    int count=0;
    while(currentptr!=nullptr && count<k)
    {
        nextptr=currentptr->next;
        currentptr->next=previous;
        previous=currentptr;
        currentptr=nextptr;
        count++;
    }

    if(nextptr!=nullptr)
    head->next = reverseKNodes(nextptr,k);

    return previous;
}

int main()
{
    
    node *head=nullptr;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtHead(head,4);
    display(head);
    
    head=reverseKNodes(head,2);
    display(head);

    
    
    return 0;
}