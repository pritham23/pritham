#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N strlen(g)
int i,j,l;
char d[20],r[20],g[20];
void xr(){
	for(j=1;j<N;j++){
		if(r[j]==g[j]) 
			r[j]='0';
		else 
			r[j]='1';
	}
}
void crc(){
	for(i=0;i<N;i++)r[i]=d[i];
	do{
		if(r[0]=='1')xr();
		for(j=0;j<N-1;j++)r[j]=r[j+1];
		r[j]=d[i++];
	}while(i<=l+N-1);
}
int main(){
	printf("enter data: ");
	scanf("%s",d);
	printf("enter gen pol: ");
	scanf("%s",g);
	l=strlen(d);
	for(i=l;i<l+N-1;i++){
		d[i]='0';
	}
	printf("data after adding 0s: %s\n",d);
	crc();
	printf("the remainder is: %s\n",r);
	for(i=l;i<l+N-1;i++)d[i]=r[i-l];
	printf("the data recived is: %s\n",d);
	crc();
	if(i<N-1)printf("\nerror detected\n");
	else printf("\nno error");
	return 0;
}
