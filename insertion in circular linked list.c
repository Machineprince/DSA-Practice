#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
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
    printf("enter the data");
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
    tail->next=head;

    return head;

}

struct node *insertion_end(struct node *head,struct node *tail)
{
   struct node *temp;
   printf("Enter the data:");
   temp=(struct node *)malloc(sizeof(struct node));
   scanf("%d)",&temp->data);
   tail->next=temp;
   tail=temp;
   temp->next=head;

   return head;

}

struct node *insertion_middle(struct  node *head)
{
    struct node *temp,*temp1;
    int i,index;
    printf("enter the data");
    temp=head;
    temp1=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp1->data);
    printf("Enter the index of insertion:");
    scanf("%d",&index);
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp1->next=temp->next;
    temp->next=temp1;

        return head;

}



int main()
{
    int choice=1;
    struct node *head,*tail,*newnode;
    head=NULL;

    while(choice == 1)
    {
        printf("enter new element\n");
        newnode = (struct node *) malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next =head;

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }

        else
        {
            tail->next = newnode;
            tail = newnode;
        }

        printf("enter 1 to add another element or enter 0 to stop \n");
        scanf("%d",&choice);

    }
    tail->next=head;
    //traversal(head);
    //head=insertion_start(head,tail);
    //traversal(head);
    //head=insertion_end(head,tail);
    //traversal(head);
    head=insertion_middle(head);
    traversal(head);
    return 0;
}
