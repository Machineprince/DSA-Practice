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

struct node *deletion_start(struct node *head,struct node *tail)
{
    struct node *temp;
    temp=head->next;
    temp->prev=head;
    head=temp;
    tail->next=head;
    head->prev=tail;
};

struct node *deletion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    temp=tail->prev;
    tail=temp;
    tail->next=head;
    head->prev=tail;

    return head;

};

struct node *deletion_middle(struct node *head,struct node *tail)
{
    struct node *temp=head,*temp1;
    int i,index;
    printf("enter the index:");
    scanf("%d",&index);
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp1=temp->next->next;
    temp->next=temp1;
    temp1->prev=temp;

    return head;
};

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
       //head=deletion_start(head,tail);
       //traversal(head);
       //head=deletion_end(head,tail);
       //traversal(head);
       head=deletion_middle(head,tail);
       traversal(head);
        return 0;

}

