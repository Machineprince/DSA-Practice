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

struct node *insertion_start(struct node *head)
{
    struct node *temp;
    printf("enter the data:");
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;

    return head;
}

struct node *insertion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    printf("enter the data:");
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    tail->next=temp;
    tail=temp;
    temp->next=NULL;
}

struct node *insertion_middle(struct node *head)
{
    int i,index;
    struct node *temp,*temp2;
    printf("enter the element");
    temp2=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp2->data);
    printf("enter the position=");
    scanf("%d",&index);
    temp=head;
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp2->next=temp->next;
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
    //traversal(head);
    //head=insertion_start(head);
    //traversal(head);
    //tail=insertion_end(head,tail);
    //traversal(head);
    head=insertion_middle(head);
    traversal(head);

    return 0;

}
