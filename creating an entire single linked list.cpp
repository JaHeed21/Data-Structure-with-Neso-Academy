#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
//adding element in an empty list
struct node *add_at_empty(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
        head=temp;
    return head;
}

//adding element at the end of the list
void add_at_end(struct node *head,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    while(head->next!=NULL)
    {
        head=head->next;
    }

    head->next=temp;
}

//adding a node at the beginning of the list
struct node* add_at_beg(struct node *head, int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    temp->next=head;
    head=temp;
    return head;

}

//printing entire list
void print_list(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<< " ";
        head=head->next;
    }
}

int main()
{
    struct node *head=NULL;

    head= add_at_empty(head,20);

    head=add_at_beg(head,10);

    add_at_end(head,30);
    add_at_end(head,40);


    print_list(head);

}
