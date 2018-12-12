#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	   cin>>a[i];
	int ans=0;
	int height;
	int area;
	for(int i=0; i<n; i++)
	{
		height=a[i];
		for(int j=i; j<n; j++)
		{
			if(a[j]<height)
			   height=a[j];
			area=(j-i+1)*height;
			if(area>ans)
			  ans=area;   
		}
	}
	cout<<ans;
}
