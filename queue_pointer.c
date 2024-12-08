#include<stdio.h>
#include<stdlib.h>
struct q
{
    int data;
    struct q *next;
}*start=NULL;
void enqueue()
{
    struct q *p,*temp;
    temp=start;
    p=(struct q*)malloc(sizeof(struct q));
    printf("enter data:\n");
    scanf("%d",&p->data);
    if(start==NULL)
    {
        start=p;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }temp->next=p;
        
    }
}
void del()
{
    struct q*temp;
    int value;
    if(start==NULL)
    {
        printf("queue is empty\n");
        return ;

    }else
    {
        temp=start;
        value=temp->data;
        start=start->next;
        printf("%d is deleted\n",value);
        
        free(temp);
    }

}
void display()
{
    struct q*temp;
    temp=start;
    if(start==NULL)
    {
        printf("queue is empty\n");
        return ;
    }
    else
    {
        while(temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }printf("%d",temp->data);
    }

    
}
int main()
{
    int choice;
    while(1)
    {
        printf("enter choice\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            default:exit(0);
            break;
        }
        


    }
}