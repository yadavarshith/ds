#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX], front=-1;
int rear=-1;
void enqueue(int num)
{
    if(rear==MAX-1)
    {
        printf("queue is full");
        return;
    }else
    {
        if(rear==-1)
            front=0;
        rear++;
        queue[rear]=num;
        printf("inserted\n");
    }
}
void dequeue()
{
    if(front=rear==-1)
        printf("queue is empty\n");
    else
    {
        printf("deleted element is %d \n",queue[front]);
        front++;
        if(front==rear)
            front=rear=-1;
    }
}
void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d",queue[i]);
    }
}
void main()
{
    int num,choice;
    while(1)
    {
        printf("enter choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case /* constant-expression */1:
        printf("enter num:");
        scanf("%d",&num);
        enqueue(num);
        break;
        case 2:
        dequeue();
        break;
        case 3:
        display();
        break;
        
        default:
        exit(0);
            break;
        }
    }
}