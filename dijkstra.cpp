#include<stdio.h>
#include<stdlib.h>

int main(){
	int node,source,i,j,k,n,min;
	int visit[10],cost[10][10],dist[10],path[10];
	printf("Input # of nodes: ");
	scanf("%d",&n);
	printf("Input cost function: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cost[i][j]);
		}
	}
	printf("Input source node: ");
	scanf("%d",&source);
	for(i=0;i<n;i++){
		visit[i]=0;
		path[i]=source;
		dist[i]=cost[source][i];
	}
	dist[source]=0;
	for(k=1;k<n;k++){
		min=999;
		node=0;
		for(i=0;i<n;i++){
			if(visit[i]!=1){
				if(min>dist[i]){
					min=dist[i];
					node=i;
				}
			}
		}
		visit[node]=1;
		for(i=0;i<n;i++){
			if(visit[i]!=1){
				if(dist[i]>(min+cost[node][i])){
					dist[i]=min+cost[node][i];
					path[i]=node;
				}
			}
		}
	}
	printf("\nVertex\tDistance\tpath\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t",i,dist[i]);
		j=i;
		printf("%d",i);
		do{
			printf("-->%d",path[j]);
			node=path[j];
			j=node;
		}while(node!=source);
		printf("\n");
	
	}
	
}
