#include<stdio.h>
#include<conio.h>
int main(){
	int tsize,hsize,mtu,total,msize,fsize,n,ex,id,t=0,mf=1,m,l=0;
	printf("enter total size of datagram: ");
	scanf("%d",&tsize);
	printf("enter identification of datagram: ");
	scanf("%d",&id);
	printf("enter the header size: ");
	scanf("%d",&hsize);
	printf("enter mtu of network: ");
	scanf("%d",&mtu);
	msize=tsize-hsize;
	fsize=mtu-hsize;
	while(fsize%8!=0){
		fsize=fsize-1;
	}
	if(msize%fsize==0){
		n=(msize/fsize);
	}
	else{
		n=(msize/fsize)+1;
	}
	printf("total no of fragments is: %d\n",n);
	m=msize;
	printf("fnumber		id 		length		offset		mf\n");
	while(1){
		l++;
		if((m-fsize)>=0){
			printf("%d		%d		%d		%d		%d		\n",l,id,fsize,t/8,mf);
			m=m-fsize;
			t=t+fsize;
		}
		else{
			mf=0;
			printf("%d		%d		%d		%d		%d		\n",l,id,m,t/8,mf);
			break;
		}
    }	
}
