#include<iostream>
#include<string.h>
using namespace std;

int reciever(string s2){
	cout<<"Sent by sender: "<<"\n";
	cout<<s2<<"\n";
	string s3;
	cout<<"at receiver: "<<"\n";
	cin>>s3;
	int n=5;
	string s4="0";
	for(int i=0;i<5;i++){
		if(s3[i]==s4[0]){
			n=i;
			break;
		}
	}
	return n;
}

int main(){
	string s1;
	cout<<"Enter string: ";
	cin>>s1;
	int i=0;
	int n=0;
	string s2;
	while(i<s1.length()){
		if(i+5<s1.length()){
			s2=s1.substr(i,5);
		}
		else{
			s2=s1.substr(i,s1.length()-i);
		}
		n=reciever(s2);
		i=i+n;
	}
}
