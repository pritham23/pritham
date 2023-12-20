#include<stdio.h>
#include<string.h>

int main(){
    int bits[100];
    int bl,i,k,j=0;
    int stuff[100],destuff[100];
    int c;
    printf("Input # of bits:");
    scanf("%d",&bl);
    printf("Input bits: ");
    for(i=0;i<bl;i++){
        scanf("%d",&bits[i]);
    }
    for(i=0;i<bl;i++){
        if(bits[i]==1){
        	c=1;
        	stuff[j++]=bits[i];
        	for(k=i+1;bits[i]==1 && k< bl&& c<5;k++){
        		stuff[j++]=bits[k];
        		c++;
        		if(c==5){
        			stuff[j++]=0;
				}
				i=k;
			}
		}
		else{
			stuff[j++]=bits[i];
		}
    }
    
    i=0;
    printf("Stuffed data: ");
    while(i<j){
        printf("%d",stuff[i]);
        i++;
    }
    printf("\nDestuffed data: ");
    
    k=0;
    int h;
    for(i=0;i<j;i++){
    	if(stuff[i]==1){
    		c=1;
    		destuff[k++]=stuff[i];
    		for(h=i+1;stuff[h]==1 && h<j && c<5;h++){
    			destuff[k++]=stuff[h];
    			c++;
    			if(c==5){
    				h++;
				}
				i=h;
			}
		}
		else{
			destuff[k++]=stuff[i];
		}
    }
    i=0;
    while(i<k){
        printf("%d",destuff[i]);
        i++;
    }
}
