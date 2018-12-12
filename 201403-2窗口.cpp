#include<bits/stdc++.h>
using namespace std;
struct mode{
	int x1,y1,x2,y2;
}q[11];
int a[12];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>q[i].x1>>q[i].y1>>q[i].x2>>q[i].y2;
	}
	for(int i=0; i<n; i++)
	{
		a[i]=n-i;
	}
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin>>x>>y;
		int flag=0;
		for(int j=0; j<n; j++)
		{
			int fro=a[j];
			if(x>=q[fro-1].x1&&x<=q[fro-1].x2&&y>=q[fro-1].y1&&y<=q[fro-1].y2)
			{
				cout<<fro<<endl;
				flag=1;
				for(int k=j; k>=1; k--)  a[k]=a[k-1];
				a[0]=fro;
				break;
			}
		}
		if(!flag) cout<<"IGNORED"<<endl;
	} 
	return 0;
 } 
