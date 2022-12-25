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

struct node *deletion_start(struct node *head)
{
    struct node *temp;
    temp=head->next;
    head=temp;
    head->prev=NULL;

    return head;
}

struct node *deletion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    temp=tail->prev;
    tail=temp;
    tail->next=NULL;

    return tail;
}

struct node *deletion_middle(struct node *head)
{
    int i,index;
    struct node *temp,*temp1;
    printf("enter the index you want to remove:");
    scanf("%d",&index);
    temp=head;
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp1=temp->next->next;
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
    //head=deletion_start(head);
    //traversal(head);
    //tail=deletion_end(head,tail);
    //traversal(head);
    head=deletion_middle(head);
    traversal(head);
    return 0;
}
