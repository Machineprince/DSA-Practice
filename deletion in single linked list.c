#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
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
    temp=head;
    head=head->next;
    temp->next=NULL;

    return head;
}

struct node *deletion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;

}

struct node *deletion_middle(struct node *head)
{
    int i,index;
    struct node *temp,*temp2;
    printf("enter the position=");
    scanf("%d",&index);
    temp=head;
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp2=temp->next->next;
    temp->next=temp2;
    return head;

}
int main()
{
    int choice=1;
    struct node*head,*tail,*newnode;
    head=NULL;
    while(choice==1)
    {
        printf("enter the data");
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        printf("enter 1 to add another element or 0 to stop");
        scanf("%d",&choice);
    }
    //head=deletion_start(head);
    //traversal(head);
    //tail=deletion_end(head,tail);
    //traversal(head);
    head=deletion_middle(head);
    traversal(head);

    return 0;

}
