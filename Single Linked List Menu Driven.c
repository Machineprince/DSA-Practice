#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traversal(struct node *head)
{
    while(head != NULL)
    {
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}

struct node *insertion_start(struct node *head)
{
    struct node *temp;
    printf("enter the element \n");
    temp = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&temp->data);

    temp->next = head;
    head = temp;
    //traversal(head);

    return head;

}
struct node *insertion_end(struct node *tail)
{
    struct node *temp;
    printf("enter the element \n");
    temp = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    tail->next = temp;
    tail = temp;
    return tail;

}
struct node *insertion_middle(struct node *head)
{
    struct node *temp,*temp_add;
    temp = head;
    int i,index;
    printf("enter the position to insert \n");
    scanf("%d",&index);
    for(i=1;i<index-1;i++)
    {
        temp = temp->next;
    }
    printf("enter the element \n");
    temp_add = (struct node *) malloc(sizeof(struct node));
    scanf("%d",&temp_add->data);
    temp_add->next = temp->next;
    temp->next = temp_add;

    return head;


}
struct node *deletion_start(struct node *head)
{
    head = head->next;
    return head;
}
struct node *deletion_end(struct node *head,struct node *tail)
{
    struct node *temp;
    temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;

    return tail;
}
struct node *deletion_middle(struct node *head)
{
    int index,i;
    struct node *temp = head;
    printf("enter the position to delete element \n");
    scanf("%d",&index);
    for (i=1;i<index-1;i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;

}

int main()
{
    int choice=1,i;
    struct node *head, *tail, *newnode;
    head = NULL;
    while(choice == 1)
    {
        printf("enter the element \n");
        newnode = (struct node *) malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }

        printf("Enter 1 to cotinue adding elements or 0 to stop \n");
        scanf("%d",&choice);
    }
    //choice = 1;
    printf("1.insertion\n2.deletion\n3.terminate\n4.display\n");
    printf("enter a number to perform operations on linked list \n");
    scanf("%d",&choice);
    while (choice!=3)
    {
        switch(choice)
        {
            case 1: printf("enter number to perform insertion operation \n");
                    printf("1.insertion at start\n2.insertion at end\n3.insertion at middle\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: head = insertion_start(head);
                                break;
                        case 2: tail = insertion_end(tail);
                                break;
                        case 3: head = insertion_middle(head);
                                break;
                        default:printf("INVALID INPUT");
                                break;
                    }
                    break;
            case 2: printf("enter number to perform deletion operation \n");
                    printf("1.deletion at start\n2.deletion at end\n3.deletion at middle\n");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                        case 1: head = deletion_start(head);
                                break;
                        case 2: tail = deletion_end(head,tail);
                                break;
                        case 3: head = deletion_middle(head);
                                break;
                        default:printf("INVALID INPUT");
                                break;
                    }
                    break;
            case 3: break;
            case 4: traversal(head);
                    break;
            default:printf("INVALID INPUT\n");
                    break;

        }
        printf("1.insertion\n2.deletion\n3.terminate\n4.display");
        printf("enter a number to perform operations on linked list \n");
        scanf("%d",&choice);

    }
    return 0;

}
