#include<iostream>
using namespace std;
int main()
{
	int m,n;	
	while(cin>>m>>n){
	int flag=0;
	int count=0;
	for(int i=m; i<=n; i++)
	{
		int baiwei=i/100;
		int shiwei=i/10%10;
		int gewei=i%10;
		if(i==baiwei*baiwei*baiwei+shiwei*shiwei*shiwei+gewei*gewei*gewei)
		{
			if(count>0)
			{
				cout<<" ";
			}
			count++;
			cout<<i;
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"no"; 
	}
	cout<<endl; 
}
	return 0;
}
