#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int num)
{
    if(top==SIZE-1)
    {
        printf("full");
        return;
    }top++;
    stack[top]=num;
}

void pop()
{
    if(top==-1)
    {
        printf("empty");
        return;
    }int num=stack[top];
    top--;
    printf("%d\n",num);
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d",stack[i]);
    }
}
void main()
{   
    int num;
    scanf("%d",&num);
    while(1)
    {
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            
            scanf("%d",&num);
            push(num);
            break;
        case 2:
            pop();
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