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

/* detecte weather a cycle is present
 in a LL or not*/
bool detectionOfCycle(node* head)
{
    node* slow=head;
    node* fast=head;

    while(fast!=nullptr && fast->next!=nullptr)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        return true;
    }
    return false;
}

//creates a cyclic LL at a perticular point
void makeCycle(node *head,int pos)
{
    int count=0;
    node *cycleStart,*temp=head;
    while(temp->next!=nullptr)
    {
        if(count==pos)
        {
            cycleStart=temp;
        }
        count++;
        temp=temp->next;
    }
    temp->next=cycleStart;
}
//function that removes cycle from a LL
void removeCycle(node* &head)
{
    node *slow=head,*fast=head;
    if(!detectionOfCycle(head))
    {
        
        cout<<"cycle not present";
    }
    else
    {
        do
        {
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        fast=head;
        while(slow->next!=fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=nullptr;
    }
}


//this function return the length of LL
int length(node *head)
{
    int count=0;
    while(head!=nullptr)
    {
        count++;
        head=head->next;
    }
    return count;
}

//this fuction gives the position of intersection in 2 LL
int intersectionDetection(node *head1,node *head2)
{
    int l1=length(head1);
    int l2=length(head2);
    node *ptr1,*ptr2;
    if(l1>l2)
    {
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        ptr1=head2;
        ptr2=head1;
    }
    int d=abs(l1-l2);
    while(d)
    {
        ptr1=ptr1->next;
        d--;
        if(ptr1->next==nullptr)
        return -1;
    }
    while(ptr1!=nullptr && ptr2!=nullptr)
    {
        if(ptr1==ptr2)
        return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}

//this function makes an intersection
//between 2 LL at a perticular point
void makeIntersection(node* &head1,node* &head2,int pos)
{
    pos--;
    node* temp1=head1;
    node* temp2=head2;
    while(pos)
    {
        temp1=temp1->next;
        pos--;
    } 
    while(temp2->next!=nullptr)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

//merging 2 sorted LL
node* mergeLinkedList(node* &head1,node* &head2)
{
    node* ptr1=head1;
    node* ptr2=head2;
    node* trashNode=new node(-1);
    node *ptr3=trashNode;
    while(ptr1!=nullptr && ptr2!=nullptr)
    {
        if(ptr1->data<ptr2->data)
        {
            ptr3->next=ptr1;
            ptr1=ptr1->next;
        }
        else
        {
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
        
    }
    while(ptr1!=nullptr)
    {
        ptr3->next=ptr1;
        ptr1=ptr1->next;
        ptr3=ptr3->next;
    }
    while(ptr2!=nullptr)
    {
        ptr3->next=ptr2;
        ptr2=ptr2->next;
        ptr3=ptr3->next;
    }
    
    return trashNode->next;

}

//merger LL recursive
node* mergeRecursive(node* head1,node*head2)
{
    if(head1==nullptr)
    {
        return head2;
    }
    if(head2==nullptr)
    {
        return head1;
    }
    

    node* result;
    if(head1->data<head2->data)
    {
        result = head1;
        result->next=mergeRecursive(head1->next,head2);
    }

    else
    {
        result = head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}

int main()
{
    
    node *head=nullptr;
    node *head2=nullptr;
    insertAtTail(head,1);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,9);

    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,5);
    insertAtTail(head2,8);
    insertAtTail(head2,10);

    
    display(mergeRecursive(head,head2));
    
    return 0;
}