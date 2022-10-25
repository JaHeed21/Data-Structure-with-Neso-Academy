#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
//adding first node at list
struct node *add_at_empty(struct node *tail, int data)
{
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next= temp;
    tail=temp;
    return tail;
}
//adding nodes at the beginning of the list
void add_at_beg(struct node *tail, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;

    temp->next=tail->next;
    tail->next=temp;
}

//adding nodes at intermediate position
struct node *add_at_pos(struct node *tail, int data, int pos)
{
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;

    struct node *head=tail->next;
    while(pos>2)
    {
        head=head->next;
        pos--;
    }
    temp->next=head->next;
    head->next=temp;
    if(head==tail)
    {
        tail=temp;
        return tail;
    }
    return tail;
}

//adding next and so on nodes on the list
struct node *add_at_end(struct node *tail, int data)
{
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;

    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return tail;
};

void print_list(struct node *tail)
{
    struct node* temp;
    temp=tail->next;
    do
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }while(temp!=tail->next);
}

int main()
{
    struct node *tail = NULL;
    int data,n,i;
    cout<< "Enter how many elements you want to add: ";
    cin>>n;
    if(n==0)
        cout<< "linked list is empty.";
    else if(n==1)
    {
        cout<<"Enter 1 no element: ";
        cin>> data;
        tail= add_at_empty(tail, data);
        print_list(tail);
    }
    else
    {
        cout<<"Enter the 1st element: ";
        cin>> data;
        tail= add_at_empty(tail, data);

        for(i=1;i<n;i++)
        {
            cout<<"Enter "<<i+1<<" no element: ";
            cin>>data;
            tail=add_at_end(tail,data);
        }
        print_list(tail);
    }

/*
    add_at_beg(tail,data);

    tail=add_at_pos(tail,data,3);
    tail=add_at_pos(tail,data,5);

    print_list(tail);

*/
    return 0;
}
