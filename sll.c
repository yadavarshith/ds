#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
    int data;
    struct node *next;
}*head,*newn,*trav;
void createlist()
{
    struct node *temp;
    int value;
    temp=head;
    newn=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&value);
    newn->data=value;
    if(head==NULL)
    {
        head=newn;
        head->next=NULL;
        count++;
    }else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }temp->next=newn;
        newn->next=NULL;
        count++;
    }
    printf("node inserted\n");
}
void insert_at_begin()
{
    newn=(struct node *)malloc(sizeof(struct node));
    int value;
    printf("enter data\n");
    scanf("%d",&value);
    newn->data=value;
    if(head==NULL)
    {
        head=NULL;
        head->next=NULL;
        count++;
    }
    else
    {
        newn->next=head;
        head=newn;
        count++;
    }printf("node inserted\n");
}
void insert_at_end()
{
    struct node *temp;
    temp=head;
    int value;
    printf("enter value:\n");
    scanf("%d",&value);
    newn=(struct node *)malloc(sizeof(struct node));
    newn->data=value;
    if(head==NULL)
    {
        head=newn;
        head->next=NULL;
        count++;
    }else{
        while(temp->next!=NULL)
        {
            temp=temp->next;

        }temp->next=newn;
        newn->next=NULL;
        count++;
    }printf("node inserted\n");
}
void delete_front()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("no elements to delete\n");
        return;
    }
    else
    {
        printf("%d is deleted\n",head->data);
        if(head->next==NULL)
        {
            head=NULL;
        }else
        {
            head=temp->next;
            temp->next=NULL;
        }count--;
        free(temp);
    }
}
void delete_end()
{
    struct node *temp,*var;
    temp=head;
    if(head==NULL)
    {
        printf("empty\n");
        return;
    }
    else
    {
        if(temp->next==NULL)
        {
            head=NULL;
        }else
        {
            while(temp->next!=NULL)
            {
                var=temp;
                temp=temp->next;
            }var->next=NULL;
        }printf("%d is deleted\n",temp->data);
        free(temp);
        count--;
    }

}
void display()
{
    struct node *trav;
    trav=head;
    if(trav==NULL)
    {
        printf("empty\n");
        return;
    }
    else
    {
        while(trav!=NULL)
        {
            printf("%d->",trav->data);
            trav=trav->next;
        }
    }
}
void insert_at_middle()
{
   
    if(count>=2)
    {
        struct node *temp;
        int loc,value;
        printf("enter at which location do you want to insert:");
        scanf("%d",&loc);
        printf("enter the value to be inserted\n");
        scanf("%d",&value);
        newn=(struct node *)malloc(sizeof(struct node));
        newn->data=value;
        temp=head;
        while(temp->data!=loc)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                printf("no element found\n");
                return;
            }
        }
        newn->next=temp->next;
        temp->next=newn;
        count++;
        printf("node inserted\n");
    }
}
void delete_from_middle()
{
    if(count>=2)
    {
        struct node *temp,*var;
        int value;
        temp=head;
        printf("enter the value to be deleted\n");
        scanf("%d",&value);
        while(temp->data!=value)
        {
            var=temp;
            temp=temp->next;
            if(temp==NULL)
            {
                printf("no element found\n");
                return;
            }
        }
        if(temp==head)
            head=temp->next;
        else{
            var->next=temp->next;
        temp->next=NULL;
        }count--;
        printf("%d is deleted\n",value);
        free(temp);
    }
}
int main()
{
    head=NULL;
    int choice,ch;
    while(1)
    {
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                do{
                    createlist();
                    display();
                    printf("do you want to insert more y/n\n");
                    getchar();
                    scanf("%c",&ch);
                }while(ch=='y'||ch=='Y');
                break;
            }case 2:
                insert_at_begin();
                display();
                break;
            case 3:
                insert_at_end();
                display();
                break;
            case 4:insert_at_middle();
            display();
            break;
            case 5:
            delete_front();
            display();
            break;
            case 6:
            delete_end();
            display();
            break;
            case 7:
            delete_from_middle();
            display();
            break;
            case 8:
            display();
            break;
            default:exit(0);
        }

    }
    return 0;
}