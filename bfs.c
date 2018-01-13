#include<stdio.h>
int graph[10][10],visited[10],n,queue[20],front=-1,rear=-1;
void Dfs(int v)
{
	int u,i,j;
	visited[v]=1;
	u=v;
	for(i=1;i<=n;i++)
	{
		if(graph[u][i]==1)
		{
			if(visited[i]==0){
			visited[i]=1;
			printf("->%d",i);
			Dfs(i);
			}
		}
	}


}
int main()
{
	int i,j,v;
	printf("Enter no of node\n");
	scanf("%d",&n);
	FILE *fp=fopen("file.txt","r");	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		fscanf(fp,"%d",&graph[i][j]);
	}
	/*printf("Adjancy matrix are\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",graph[i][j]);
		printf("\n");

	}*/
	printf("Enter the starting node:-\n");
	scanf("%d",&v);
	Dfs(v);
	return 0;
}
