#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
const int WINDOW_SIZE=4;
int n,flag;
struct packet
{
 int data;
 string ack;
}packet[100];
void send_packets()
{
 cout<<"Enter no of pacekts\n";
 cin>>n;
 for(int i=0;i<n;i++)
 {
 cout<<"Enter the packet "<<i+1<<" data : ";
 cin>>packet[i].data;
 packet[i].ack="YES";
 }
}
void receive_ack(int base)
{
 int r=rand()%n;
 int i;
 int flag=0;
 cout<<"FRAME\tDATA\tACK\n";
 for(i=base;i<min(base+WINDOW_SIZE,n);i++)
 {
 cout<<i+1<<"\t\t"<<packet[i].data<<"\t\t";
 if(i==r)
 {
 packet[i].ack="NO";
 flag=1;
 }
 cout<<packet[i].ack<<endl;
 }
 if(flag==1)
 {
 cout<<"NACK received for packet "<<r+1<<endl;
 cout<<"Retransmitting the packet "<<r+1<<endl;
 cout<<"ACK of packet "<<r+1<<endl;
 packet[r].ack="YES";
 cout<<r+1<<"\t\t"<<packet[r].data<<"\t\t"<<packet[r].ack<<endl;
 }
 cout<<"________________________________\n";
 if(i<n)
 receive_ack(i);
 
}
int main()
{
 send_packets();
 
 receive_ack(0);
 return 0;
}
