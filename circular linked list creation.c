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
    traversal(head);


    return 0;
}
