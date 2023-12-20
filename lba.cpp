#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,b,r;
	int loss,trans,left=0;
	printf("Input bucket size: ");
	scanf("%d",&b);
	printf("Input rate of transmission: ");
	scanf("%d",&r);
	int c=1;
	do{
		printf("Input # of packets: ");
		scanf("%d",&n);
		n=n+left;
		if(n<=b){
			if(n<=r){
				loss=0;
				trans=n;
				left=0;
			}
			else{
				trans=r;
				left=n-trans;
				loss=0;
			}
		}
		else{
			loss=n-b;
			trans=r;
			left=n-trans-loss;
		}
		printf("packets lost: %d\npackets transmitted: %d\nspace left: %d\n",loss,trans,b-left);
		printf("\n\n to continue : 1 else 0, Input: ");
		scanf("%d",&c);
	}while(c==1);
	
	
}
