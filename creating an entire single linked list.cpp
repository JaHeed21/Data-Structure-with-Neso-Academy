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

//adding a node at an intermediate position
void add_at_pos(struct node* head, int data, int pos)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    while(pos>1)
    {
        head=head->next;
        pos--;
    }
    temp->next=head->next;
    head->next=temp;
}

//deleting an intermediate node of the linked list
struct node* del_at_pos(struct node *head, int pos)
{
    struct node* temp=head;
    struct node* temp2=head;


    if(pos==1)
    {
        head=head->next;
        free(temp);
        temp=NULL;
        return head;
    }
    else
    {
        while(pos>2)
        {
            head=head->next;
            pos--;
        }
        temp=head->next;
        head->next=temp->next;
        free(temp);
        temp=NULL;
        return temp2;
    }
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

    add_at_end(head,40);
    add_at_end(head,50);

    cout<< "Before deletion: ";
    add_at_pos(head,30,2);
    print_list(head);
    cout<<endl;

    cout<< "After Deletion: ";
    head=del_at_pos(head, 1);
    print_list(head);
}
