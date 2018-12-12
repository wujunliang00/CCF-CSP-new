#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	int min;
	min=abs(a[0]-a[1]);
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1;j<n; j++)
		{
			int temp=abs(a[i]-a[j]);
			if(temp<min)
			   min=temp;
		}
	}
	cout<<min;
	return 0;
} 
