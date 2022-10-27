#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
//adding the first node at the list
struct node *add_at_empty(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
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

    head= add_at_empty(head,10);

    print_list(head);

}
