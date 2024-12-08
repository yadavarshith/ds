#include<stdio.h>
void quicksort(int [],int,int);
void main()
{
    int low,high,pivot,n,a[10];
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    low=0;
    high=n-1;
    quicksort(a,low,high);
    printf("after sorting the array elements are:\n");
    for(int i=0;i<n;i++)
        printf("%d",a[i]);
}

void quicksort(int a[],int low,int high)
{
    int pivot,i,j;
    if(low<high)
    {
        pivot=a[low];
        i=low+1;
        j=high;
        while(1)
        {
            while(pivot>a[i] && i<=high)
                i++;
            while(pivot<a[j] && j>=low)
                j--;
            if(i<j)
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }else   break;
        }a[low]=a[j];
        a[j]=pivot;
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}