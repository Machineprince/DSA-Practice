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
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

struct node *insertion_start(struct node *head,struct node *tail)
{
    struct node *temp;
    printf("Enter the element:");
    temp=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=head;
    head->prev=tail;
    head=temp;
    head->prev=NULL;

    return head;
}

struct node *insertion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    printf("Enter the element:");
    temp=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    temp->next=NULL;

    return head;

}

struct node *insertion_middle(struct node *head)
{
    struct node *temp,*temp1;
    int i,index;
    printf("enter the data");
    temp1=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp1->data);
    printf("enter the position:");
    scanf("%d",&index);
    temp=head;
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next=temp1;
    temp1->prev=temp;
}

int main()
{
    int choice=1;
    struct node *head=NULL,*tail,*newnode;
    while(choice==1)
    {
        printf("enter the data");
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            head->prev=NULL;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("enter 1 to continue elements and 0 to stop adding");
        scanf("%d",&choice);
    }
    //traversal(head);
    //head=insertion_start(head,tail);
    //traversal(head);
    //head=insertion_end(head,tail);
    //traversal(head);
    tail=insertion_middle(head);
    traversal(head);
    return 0;
}
