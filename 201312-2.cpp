#include<bits/stdc++.h>
using namespace std;
int main()
{
	char data[13];
	cin>>data;
	int data1[10];
	int j(0),sum(0);
	for(int i=0; i<12; i++)
	{
		if(data[i]!='-')
		{
			data1[j]=data[i]-'0';
			j++;
		}
	 } 
	for(int i=0; i<j; i++)
	{
		sum+=data1[i]*(i+1);
		
	 } 
	sum=sum%11;
	if(sum!=10)
	{
		if(sum==data[12]-'0')
		cout<<"Right";
		else 
		{
			for(int i=0; i<12; i++)
			cout<<data[i];
			cout<<sum;
		}
	 } 
	else 
	{
		if(data[12]=='X')
		cout<<"Right";
		else 
		{
			for(int i=0; i<12; i++)
			cout<<data[i];
			cout<<"X";
		}
	 } 
	return 0;
}
