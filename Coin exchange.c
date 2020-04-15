/*C code for Coin exchange algorithm using greedy approach*/
/*Created by: SOUMYA BANERJEE*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,c[100],m,i,j,k,s[100],p,x=0;
    printf("\nEnter the value of n:\n");
    scanf("%d",&n);
    printf("\nEnter the coin values:\n");
    for(i=0;i<n;i++)
        scanf("%d",&c[i]);
    printf("\nEnter money to be returned:\n");
    scanf("%d",&m);
    while(m>0)
    {
        p=0;
        for(i=0;i<n;i++)
        {
            if(c[i]>p && c[i]<=m)
            {
                p=c[i];
                k=i;
            }
        }
        s[x++]=p;
        m=m-p;
        c[k]=0;
    }
    printf("\nThe solution set using greedy method:\n");
    for(i=0;i<x;i++)
        printf("%d ",s[i]);
    return 0;
}

OUTPUT :

Enter the value of n:
7

Enter the coin values:
200 100 100 50 50 20 10

Enter money to be returned:
180

The solution set using greedy method:
100 50 20 10
