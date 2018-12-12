#include<iostream>
#include<cmath>
#include<stdio.h> 
using namespace std;
#define MAX 10000
void sieveofe(int p[],int n)
{
	int i,j;
	p[0]=0;
	p[1]=0;
	p[2]=1;
	for(i=3;i<=n; i++)
	{
		p[i++]=1;
		p[i]=0;
	}
	int max=sqrt(n);
	for(i=3;i<=max;i++){
		if(p[i]){
			for(j=i+i; j<n; j+=i)   //½øÐÐÉ¸Ñ¡ 
			    p[j]=0;
		}
	}
}
int main()
{
	int p[MAX+1];
	sieveofe(p,MAX);
	int num;
	int sushu1,sushu2;
	while(scanf("%d",&num)!=EOF)
	{
		for(int i=2;i<=num/2; i++)
		{
    		if(p[i]&&p[num-i])
    		   {
    		   	sushu1=i;
    		   	sushu2=num-i;
			   }
		}
		cout<<sushu1<<" "<<sushu2<<endl;
	}
	return 0;
}
