#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int begin;
	int end;
};

int main()
{
	int n;
	cin>>n;
	node a[n],b[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i].begin>>a[i].end;
	}
	for(int i=0; i<n; i++)
	{
		cin>>b[i].begin>>b[i].end;
	}
	int time=0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++){
		
		if(a[i].begin>=b[j].begin&&a[i].begin<=b[j].end&&a[i].end>=b[j].end)
		{
			time+=b[j].end-a[i].begin;
		}
		else if(a[i].end>=b[j].begin&&a[i].end<=b[j].end&&a[i].begin<=b[j].begin)
		{
			time+=a[i].end-b[j].begin;
		}
		else if(a[i].begin<b[j].begin&&a[i].end>b[j].end)
		{
			time+=(b[j].end-b[j].begin);
		}
		else if(a[i].begin>b[j].begin&&a[i].end<b[j].end)
		{
			time+=(a[i].end-a[i].begin);
		}
	    }
	}
	cout<<time;
	return 0;
}
