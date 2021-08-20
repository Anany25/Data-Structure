#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;

void insertAtBeginning();
void insertAtEnd();
void insertInMiddle();
void deleteAtBeginning();
void deleteAtEnd();
void deleteInMiddle();
void display();

int main()
{
    int choice;
    L:
    printf("\nEnter 1 to Insert at Beginning\nEnter 2 to Insert at End\nEnter 3 to Insert in Middle\nEnter 4 to Delete at Beginning\nEnter 5 to Delete at End\nEnter 6 to Delete in Middle\nEnter 7 to Display the list\nEnter 8 to Exit\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        insertAtBeginning();
    }
    else if(choice==2)
    {
        insertAtEnd();
    }
    else if(choice==3)
    {
        insertInMiddle();
    }
    else if(choice==4)
    {
        deleteAtBeginning();
    }
    else if(choice==5)
    {
        deleteAtEnd();
    }
    else if(choice==6)
    {
        deleteInMiddle();
    }
    else if(choice==7)
    {
        display();
    }
    else if(choice==8)
    {
        return 0;
    }
    goto L;
}

void insertAtBeginning()
{
    struct node *newNode;
    int temp;
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp);
    if(head==NULL)
    {
        newNode->data=temp;
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->data=temp;
        newNode->next=head;
        head=newNode;
    }
}
void insertAtEnd()
{
    struct node *newNode,*ptr;
    int temp;
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp);
    if(head==NULL)
    {
        newNode->data=temp;
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
        newNode->data=temp;
        newNode->next=NULL;
    }
}
void insertInMiddle()
{
    struct node *newNode,*ptr;
    int temp,pos;
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp);
    printf("Enter position: ");
    scanf("%d",&pos);

    newNode->data=temp;
    newNode->next=NULL;
    ptr=head;
    for(int i=1;i<=pos-1;i++)
    {
        ptr=ptr->next;
        if(ptr==NULL)
        {
            break;
        }
    }
    if(ptr!=NULL)
    {
        newNode->next=ptr->next;
        ptr->next=newNode;
    }
    else
    {
        printf("Unable to insert data\n");
    }
}
void deleteAtBeginning()
{
    struct node *toDelete;
    if(head==NULL)
    {
        printf("List is already Empty\n");
    }
    else
    {
        toDelete=head;
        head=head->next;
        free(toDelete);
        printf("Node Deleted!\n");
    }
}
void deleteAtEnd()
{
    struct node *toDelete,*secondLastNode;
    if(head==NULL)
    {
        printf("List is already Empty\n");
    }
    else
    {
        toDelete=head;
        secondLastNode=head;
        while(toDelete->next!=NULL)
        {
            secondLastNode=toDelete;
            toDelete=toDelete->next;
        }
        if(toDelete==head)
        {
            head=NULL;
        }
        else
        {
            secondLastNode->next=NULL;
        }
        free(toDelete);
        printf("Node Deleted!\n");
    }
}
void deleteInMiddle()
{
    struct node *toDelete,*previousNode;
    int pos;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        printf("Enter position: ");
        scanf("%d",&pos);
        toDelete=head;
        previousNode=head;
        for(int i=2;i<=pos;i++)
        {
            previousNode=toDelete;
            toDelete=toDelete->next;
        }
        if(toDelete==head)
        {
            head=NULL;
        }
        previousNode->next=toDelete->next;
        free(toDelete);
        printf("Node Deleted!\n");
    }
}
void display()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

