#include<stdio.h>

struct node
{
    int data;
    struct node*next;
}*head=NULL;

int main()
{
    int newData;
    int choice;
    L:
    printf("\nEnter 1 to push\nEnter 2 to pop\nEnter 3 to display\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter data: ");
        scanf("%d",&newData);
        push(newData);
    }
    else if(choice==2)
    {
        pop();
    }
    else if(choice==3)
    {
        display();
    }
    goto L;
}
void push(newData)
{
    struct node *newNode,*temp;
    newNode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        newNode->data=newData;
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->data=newData;
        newNode->next=NULL;
    }
    printf("Element added!\n");

}

void pop()
{
    struct node *toDelete,*secondLastNode;
    if(head==NULL)
    {
        printf("Stack is Empty\n");
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
        printf("Element popped!\n");
        free(toDelete);
    }
}

void display()
{
    struct node *display;
    display=head;
    if(head==NULL)
    {
        printf("Stack in Empty!\n");
    }
    else
    {
        while(display!=NULL)
        {
            printf("%d\t",display->data);
            display=display->next;
        }
    }
}

