#include<stdio.h>

int rear=-1,front=-1,n;
int A[];
int empty();
int enqueue();
void dequeue();

int main()
{
    int data;
    int choice;
    printf("Enter size for Queue: ");
    scanf("%d",&n);
    L:
    printf("\nEnter 1 to enqueue\nEnter 2 to Dequeue\nEnter 3 to display\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter data:\n");
        scanf("%d",&data);
        enqueue(data);
    }
    else if(choice==2)
    {
        dequeue();
    }
    else if(choice==3)
    {
        printf("Front value is %d",A[front]);
    }
    goto L;
}
int empty()
{
    if(front&&rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int enqueue(data)
{
    if((rear+1)%n==front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if(empty())
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%n;
        }
        A[rear]=data;
    }
}
void dequeue()
{
    if(empty())
    {
        printf("Queue is empty");
    }
    else
    {
        if(front==rear)
        {

            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%n;
        }
    }
}


