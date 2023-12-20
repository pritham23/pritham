#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define N strlen(g)
char d[30],r[30],g[10];
int i,j,l;
void xr(){
	for(j=1;j<N;j++)r[j]=((r[j]==g[j])?'0':'1');
}
void crc(){
	for(i=0;i<N;i++)r[i]=d[i];
	do{
		if(r[0]=='1')xr();
		for(j=0;j<N-1;j++)r[j]=r[j+1];
		r[j]=d[i++];
	}while(i<=l+N-1);
}
void rec(){
	printf("enter the data to be received\n");
	scanf("%s",&d);
	printf("the data received is %s\n",d);
	crc();
	if(i<N-1)printf("error detected\n");
	else printf("no error detected\n");
}
int main(){
	printf("enter the data to be transmitted\n");
	scanf ("%s",d);
	printf("enter the polynomial\n");
	scanf("%s",g);
	l=strlen(d);
	for(i=l;i<l+N-1;i++)d[i]='0';
	printf("data padded with zero will be %s\n",d);
	crc();
	printf("the remainder is %s",r);
	for(i=l;i<l+N-1;i++)d[i]=r[i-l];
	printf("the final data to be sent is %s\n",d);
	rec();
}
