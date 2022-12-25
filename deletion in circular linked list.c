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

struct node *deletion_start(struct node *head,struct node *tail)
{
    struct nod *temp;
    temp=head->next;
    head=temp;
    tail->next=head;

    return head;

}

struct node *deletion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    temp=head;
    while(temp->next->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head;
    tail=temp;


    return head;

}

struct node *deletion_middle(struct node *head,struct node *tail)
{
    struct node *temp;
    int i,index;
    temp=head;
    printf("Enter the pos:");
    scanf("%d",&index);
    for(i=1;i<index-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;

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
    //head=deletion_start(head,tail);
    //traversal(head);
    //head=deletion_end(head,tail);
    //traversal(head);
    head=deletion_middle(head,tail);
    traversal(head);

    return 0;
}
