#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void lpsarray(char *pattern,int M,int *lps)
{
    int i=0; 
    int j=i+1;
    lps[0]=0;
    while(j<M)
    {
        if(pattern[j]==pattern[i])
        {
            i++;
            lps[j]=i;
            j++;
        }else{
            if(i!=0)
            {
                i=lps[i-1];
            }else
            {
                lps[j]=i;
                j++;
            }
        }
    }
}
void KMPsearch(char *text,char *pattern)
{
    int M=strlen(pattern);
    int N=strlen(text);
    int *lps=(int *)malloc(sizeof(int)*M);
    if(lps==NULL)
    {
        fprintf(stderr,"memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    lpsarray(pattern,M,lps);
    int i=0;
    int j=0;
    while(i<N)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==M)
        {
            printf("pattern found at index %d",i-j);
            j=lps[j-1];
        }else
        if(i<N && pattern[j]!=text[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }else
                i++;
        }
    }free(lps);
}
int main()
{
    char text[]="abcabdd";
    char pattern[]="abd";
    KMPsearch(text,pattern);
    return 0;
}