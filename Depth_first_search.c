/* C Code for graph traversal using depth-first-search algorithm */
/* Created by Soumya Banerjee on 19th November, 2019 */

Code :

#include <stdio.h>
#include <stdlib.h>
int color[20],prev[20],n,adj[20][20];
void DFS()
{
    int i,j,u;
    for(i=0;i<n;i++)
    {
        color[i]=0;
        prev[i]=-1;
    }
    for(i=0;i<n;i++)
    {
        if(color[i]==0)
            DFS_VISIT(i);
    }
}
void DFS_VISIT(int u)
{
    int i;
    if(color[u]==0)
        printf("v%d  ",u);
    color[u]=1;
    for(i=0;i<n;i++)
    {
        if(adj[u][i]==1)
        {
            if(color[i]==0)
            {
                prev[i]=u;
                DFS_VISIT(i);
            }
        }
    }
    color[u]=2;
}
int main()
{
    int i,j,k;
    printf("\nEnter the number of vertexes :");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\nEnter adj[%d][%d] = ",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nThe adjacency matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d  ",adj[i][j]);
        printf("\n");
    }
    printf("\nOrder in which the tree vertexes are traversed using DFS:\n");
    DFS();
    return 0;
}


OUTPUT :

Enter the number of vertexes :5

Enter the adjacency matrix :

Enter adj[0][0] = 0

Enter adj[0][1] = 1

Enter adj[0][2] = 1

Enter adj[0][3] = 1

Enter adj[0][4] = 0

Enter adj[1][0] = 1

Enter adj[1][1] = 0

Enter adj[1][2] = 0

Enter adj[1][3] = 1

Enter adj[1][4] = 1

Enter adj[2][0] = 1

Enter adj[2][1] = 0

Enter adj[2][2] = 0

Enter adj[2][3] = 1

Enter adj[2][4] = 0

Enter adj[3][0] = 1

Enter adj[3][1] = 1

Enter adj[3][2] = 1

Enter adj[3][3] = 0

Enter adj[3][4] = 1

Enter adj[4][0] = 0

Enter adj[4][1] = 1

Enter adj[4][2] = 0

Enter adj[4][3] = 1

Enter adj[4][4] = 0

The adjacency matrix :
0  1  1  1  0
1  0  0  1  1
1  0  0  1  0
1  1  1  0  1
0  1  0  1  0

Order in which the tree vertexes are traversed using DFS:
v0  v1  v3  v2  v4
