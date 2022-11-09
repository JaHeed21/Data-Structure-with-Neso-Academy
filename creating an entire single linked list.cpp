//#include<bits/stdc++.h>
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

//deleting the first node of the linked list
struct node *delFirst(struct node *head)
{
    if (head==NULL)
    {
        cout<<"Linked list is empty. There is no node to be deleted."<<endl;
        return head;
    }
    else
    {
        struct node *temp;
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
        return head;
    }
};

//deleting the last node of the linked list
void delLast(struct node *head)
{
    while(head->next->next!=NULL)
    {
        head=head->next;
    }
    struct node *temp;
    temp=head->next;
    head->next=NULL;
    free(temp);
    temp=NULL;

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

void count_node(struct node* head)
{
    if(head==NULL)
    {
        cout<<"There is no node in the list"<<endl;
    }
    int cnt=1;
    while(head->next!=NULL)
    {
        head=head->next;
        cnt++;
    }
    cout<<"There are "<< cnt <<" nodes in the list"<<endl;
}



//printing entire list
void print_list(struct node *head)
{
    if(head==NULL)
        cout<<"There is no node in the list."<<endl;
    else
    {
        while(head!=NULL)
        {
            cout<<head->data<< " ";
            head=head->next;
        }
        cout<<endl;
    }
}

int main()
{
    struct node *head=NULL;
//adding data dynamically by users:
    int x;
    int data;
    cout<< "Enter how many node you want to add: ";
    cin>>x;
    if(x==0)
        print_list(head);
    else if(x==1)
    {
        cout<< "Enter data for first node: ";
        cin>> data;
        head=add_at_empty(head, data);
        print_list(head);
    }
    else
    {
        int i=1;
        cout<< "Enter data for first node: ";
        cin>> data;
        head=add_at_empty(head, data);
        while(i<x)
        {
            cout<< "Enter data for "<<i+1<<" node: ";
            cin>> data;
            add_at_end(head,data);
            i++;
        }
        print_list(head);
    }

    while(1)
    {
        cout<< "1. Add element at front."<<endl
            << "2. Add element at particular function."<<endl
            << "3. Add element at last."<<endl
            << "4. Count the nodes of the list."<<endl
            << "5. Delete element at last."<<endl
            << "0. Quit"<<endl;
        cout<< "Enter your Choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<< "Enter the value you want to add: ";
            cin>>data;
            head=add_at_beg(head,data);
            cout<<endl;
            print_list(head);
            break;

        case 2:
            cout<< "Enter data you want to add: ";
            int pos;
            cin>>data;
            cout<< "After which position you want to add: ";
            cin>>pos;
            add_at_pos(head,data, pos);
            cout<<endl;
            print_list(head);
            break;

        case 3:
            cout<< "Enter data you want to add: ";
            cin>> data;
            add_at_end(head,data);
            cout<<endl;
            print_list(head);
            break;

        case 4:
            count_node(head);
            break;

        case 5:
            delLast(head);
            cout<<endl;
            print_list(head);
            break;

        case 0:
            exit(1);
            break;

        default:
            cout<< "You Entered  wrong choice."<<endl;
        }

    }

    return 0;
}





