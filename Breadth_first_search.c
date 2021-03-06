/* Breadth-first search*/
/* Created by Soumya Banerjee on 3rd November,2019 */
/*Code in C :*/

#include <stdio.h>
#include <stdlib.h>
int *Q,cap,f,r,adj[10][10];
int color[100],prev[100],dist[100];
void enqueue(int v)
{
    if(r==cap-1)
    {
        printf("\nQueue is full");
        return;
    }
    if(f==-1)
        f=0;
    Q[++r]=v;
}
int dequeue()
{
    int v;
    if(f==-1)
    {
        printf("\nQueue is empty");
        return;
    }
    v=Q[f];
    if(f==r)
        f=r=-1;
    else
        f++;
    return v;
}
int main()
{
    //printf("Hello world!\n");
    int n,v,i,j,k,src,u;
    printf("\nEnter the number of vertexes :");
    scanf("%d",&n);
    cap=n;
    Q=(int *)malloc(cap*sizeof(int));
    f=r=-1;
    printf("\nEnter the adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\nEnter adj[%d][%d]=",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nThe adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",adj[i][j]);
        printf("\n");
    }
    for(i=0;i<n;i++)
    {
        color[i]=0;
        dist[i]=999;
        prev[i]=-1;
    }
    printf("\nEnter the source vertex :");
    scanf("%d",&src);
    color[src]=1;
    dist[src]=0;
    enqueue(src);
    printf("\nOrder in which graph vertexes are traversed using BFS :\n");
    while(f!=-1)
    {
        u=dequeue();
        printf("v%d  ",u);
        for(i=0;i<n;i++)
        {
            if(adj[u][i]==1)
            {
                if(color[i]==0)
                {
                    color[i]=1;
                    dist[i]=dist[u]+1;
                    prev[i]=u;
                    enqueue(i);
                }
            }
        }
        color[u]=2;
    }
    printf("\nDistance of each vertex from source v%d :",src);
    for(i=0;i<n;i++)
        printf("%d ",dist[i]);

    return 0;
}


OUTPUT :

Enter the number of vertexes :4

Enter the adjacency matrix :

Enter adj[0][0]=0

Enter adj[0][1]=1

Enter adj[0][2]=1

Enter adj[0][3]=0

Enter adj[1][0]=1

Enter adj[1][1]=0

Enter adj[1][2]=0

Enter adj[1][3]=1

Enter adj[2][0]=1

Enter adj[2][1]=0

Enter adj[2][2]=0

Enter adj[2][3]=0

Enter adj[3][0]=0

Enter adj[3][1]=1

Enter adj[3][2]=0

Enter adj[3][3]=0

The adjacency matrix :
0 1 1 0
1 0 0 1
1 0 0 0
0 1 0 0

Enter the source vertex :0

Order in which graph vertexes are traversed using BFS :
v0  v1  v2  v3
Distance of each vertex from source v0 :0 1 1 2

