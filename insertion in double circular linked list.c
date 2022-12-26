#include<stdio.h>
#include<stdlib.h>
 struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void traversal(struct node *ptr)
{
    printf("%d",ptr->data);
    struct node *temp;
    temp=ptr->next;
    while(temp!=ptr)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

struct node *insertion_start(struct node *head,struct node *tail)
{
    struct node *temp;
    printf("enter the data:");
    temp=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    tail->next=head;
    head->prev=tail;

    return head;

}

struct node *insertion_end(struct node *head,struct node *tail)
{
    struct  node *temp;
    printf("enter the data:");
    temp=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    tail->next=head;
    head->prev=tail;

    return head;
}

struct node *insertion_middle(struct node *head,struct node *tail)
{
    struct node *temp,*temp1,*temp2;
    int i,index;
    printf("enter the data:");
    temp=head;
    temp1=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp1->data);
    printf("enter the index:");
    scanf("%d",&index);
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp1->next=temp2;
    temp2->prev=temp1;
    temp->next=temp1;
    temp1->prev=temp;

    return head;

}



int main()
{
    int choice=1;
    struct node *head=NULL,*tail,*newnode;
    while(choice==1)
    {
        printf("enter the data:");
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=head;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("enter 1 to add element and 0 to stop adding: ");
        scanf("%d",&choice);
    }
       tail->next=head;
       //traversal(head);
       //head=insertion_start(head,tail);
       //traversal(head);
       //head=insertion_end(head,tail);
       //traversal(head);
        head=insertion_middle(head,tail);
        traversal(head);


        return 0;

}
