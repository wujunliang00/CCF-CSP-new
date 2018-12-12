#include<iostream>
#include<cmath> 
using namespace std;
//筛选法求得必要的素数，然后用试探法求解可分解的个数
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
			for(j=i+i; j<n; j+=i)   //进行筛选 
			    p[j]=0;
		}
	}
}

int main()
{
    int p[MAX+1];
	int num;
    sieveofe(p,MAX);
    while(cin>>num&&num!=0)
    {
    	int count=0;
		for(int i=2;i<=num/2; i++){
    		if(p[i]&&p[num-i])
    		if(i!=num-i)
    		   count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
