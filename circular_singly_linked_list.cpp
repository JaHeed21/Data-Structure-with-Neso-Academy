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
    tail= add_at_empty(tail, 35);

    tail=add_at_end(tail,55);
    tail=add_at_end(tail,75);

    print_list(tail);

}
