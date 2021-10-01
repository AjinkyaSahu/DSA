#include<stdio.h>
void main()
{
	printf("Kindly enter the number of vertices  ");
	int v,e,x,y;
	scanf("%d",&v);
	int a[v][v];
	int i=0,j;
	for(i;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			a[i][j]=0;
		}
	}
	printf("\nPlease enter the number of edges  ");
	scanf("%d",&e);
	for(j=1;j<=e;j++)
	{
		printf(" Enter the origin vertex of %d edge         ",j);
		scanf("%d",&x);
		printf(" Enter the destination vertex of %d edge    ",j);
		scanf("%d",&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	printf("\n The Adjacency Matrix is :\n");
	printf("   ");
	for(i=0;i<v;i++)
	   printf("%d  ",i);
	for(i=0;i<v;i++)
	{
		printf("\n%d ",i);
		for(j=0;j<v;j++)
		{
			printf(" %d ",a[i][j] );
		}
	}
}
