#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct node *p,*q,*root=NULL;
    int n;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->left=NULL;
        p->right=NULL;
        if(i==0)
            root=p;
        else
        {
            q=root;
            while(1)
            {
                if(p->data>q->data)
                {
                    if(q->right==NULL){
                        q->right=p;
                        break;
                    }
                    else
                    {
                        q=q->right;
                    }
                }
                else{
                    if(q->left==NULL)
                    {
                        q->left=p;
                        break;
                    }
                    else
                    {
                        q=q->left; 
                    }
                }
            }
        }
    }inorder(root);
    return 0;
}    

