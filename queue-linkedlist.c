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
    printf("\nEnter 1 to enqueue\nEnter 2 to dequeue\nEnter 3 to display\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter data: ");
        scanf("%d",&newData);
        enqueue(newData);
    }
    else if(choice==2)
    {
        dequeue();
    }
    else if(choice==3)
    {
        display();
    }
    goto L;
}
void enqueue(newData)
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

void dequeue()
{
    struct node *toDelete;
    if(head==NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        toDelete=head;
        head=head->next;
        printf("Element deleted!\n");
        free(toDelete);
    }
}

void display()
{
    struct node *display;
    display=head;
    if(head==NULL)
    {
        printf("Queue in Empty!\n");
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


