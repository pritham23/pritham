#include<stdio.h>
struct node
{
	int dist[20];
	int from[20];
}rt[10];
int main()
{
	int costmat[20][20];
	int n,i,j,k,count=1;
	printf("Enter no.of nodes:\n");
	scanf("%d",&n);
	printf("Enter cost matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&costmat[i][j]);
			costmat[i][i]=0;
			rt[i].dist[j]=costmat[i][j];
			rt[i].from[j]=j;
		}
	}
	do
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
				{
					if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
					{
						rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
						rt[i].from[j]=k;
					}
				}
			}
		}
		count++;
	}while(count<n);
	for(i=0;i<n;i++)
	{
		printf("Distance Routing table for router %c:\n",i+65);
		for(j=0;j<n;j++)
		{
			printf("Node %d via %d,Distance:%d\n",j,rt[i].from[j],rt[i].dist[j]);
		}
	}
}
