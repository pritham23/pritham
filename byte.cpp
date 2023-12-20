#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char frame[50],str[50],destuff[50];
	char flag='f';
	char esc='e';
	int i,k=0;
	frame[k++]=flag;
	printf("Enter the string: ");
	fgets(str,50,stdin);
	for(i=0;i<strlen(str);i++){
		if(str[i]!=flag && str[i]!=esc){
			frame[k++]=str[i];
		}
		else{
			frame[k++]=esc;
			frame[k++]=str[i];
		}
	}
	frame[k++]=flag;
	k=0;
	printf("after stuffing: %s",frame);
	for(i=1;i<strlen(frame)-1;i++){
		if(frame[i]==esc){
			i++;
		}
		destuff[k++]=frame[i];
	}
	printf("\n\n");
	printf("After destufffing: %s",destuff);
	
}
