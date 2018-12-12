#include<iostream>
using namespace std;
int main()
{
	int sum(0);
	int a[40]={-1},b[40]={-1};
	int i=1;
	while(cin>>a[i]&&a[i]!=0)
	{
		b[i]=a[i];
		if(a[i]==1)
		sum+=1;
		else if(a[i]==2&&b[i-1]!=2)
		sum+=2;
		else if(a[i]==2&&b[i-1]==2)
		{
			a[i]=a[i-1]+2;
			sum+=a[i]; 
		} 
		i++;
	}
	cout<<sum;
	return 0;
} 
