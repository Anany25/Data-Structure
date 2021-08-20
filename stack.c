#include<stdio.h>
int stack[0];
int n;
int top=-1;
int isFull();
int isEmpty();
int push();
int pop();
int main()
{
int data;
int Case;
printf("Enter stack size: ");
scanf("%d",&n);
L:
printf("Enter 1 to push:\nEnter 2 to pop:\nEnter 3 to print top element:\n");
scanf("%d",&Case);
if(Case==1)
{
    printf("Enter value to push: ");
    scanf("%d",&data);
    push(data);
}
else if(Case==2)
{
    pop();
}
else if(Case==3)
{
    if(top==-1)
    {
        printf("Stack is empty,no elements found\n");
    }
    else
    {
        printf("Top element is: %d\n",stack[top]);
    }
}
goto L;
}
int isFull()
{
    if(top==n-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(int data)
{
    if(isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        top=top+1;
        stack[top]=data;
    }
}
int pop()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        top=top-1;
        printf("Top element popped\n");
    }
}
