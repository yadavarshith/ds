#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int size;
struct stack{
    int arr[MAX];
    int top;
    
};
void init_stk(struct stack *ptr)
{
    ptr->top=-1;
}
void push(struct stack *ptr,int num)
{
    if(ptr->top==size-1)
    {
        printf("stack is full\n");
        return;
    }ptr->top++;
    ptr->arr[ptr->top]=num;
    printf("inserted\n");
}

void pop(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        printf("empty\n");
        return ;
    }
    int num=ptr->arr[ptr->top];
    ptr->top--;
    printf("deleted element:%d\n",num);
}
void display(struct stack *ptr)
{
    for(int i=ptr->top;i>=0;i--)
    {
        printf("%d ",ptr->arr[i]);
    }
}
int main()
{
    struct stack ptr;
    init_stk(&ptr);
    int data;
    int choice;
    printf("enter choice");
    scanf("%d",&choice);
    while(1)
    {
        switch (choice)

        {
            case 1:
            printf("enter data\n");
            scanf("%d",data);
            push(&ptr,data);
            break;
            case 2:
            pop(&ptr);
            break;
           case 3:display(&ptr);
            break;
            default:
           exit(0);
           break;
        }
    }

}