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
       traversal(head);

        return 0;

}

