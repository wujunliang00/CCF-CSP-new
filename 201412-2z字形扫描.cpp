#include<bits/stdc++.h>
using namespace std;
int a[500][500];
int x=0, y=0;

bool travse(bool dir, int &x, int &y, int n)
{
	while(1)
	{
		cout<<a[x][y]<<" ";
		if(dir==true)
		{
			if(x==0||y==(n-1))  return dir;
			x--;
			y++;
		}
		else 
		{
			if(y==0||x==(n-1)) return dir;
			x++;
			y--;
		}
	}
}

int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
    	for(int j=0; j<n; j++)
    	cin>>a[i][j];
	}
	
	bool direction=true;
	cout<<a[x][y]<<" ";
	while(1)
	{
		if(x==n-1&&y==n-1)  break;
		if(direction==true)
		{
			if(y<n-1)  y++;
			else x++;
			direction=travse(!direction,x,y,n);
		}
		else
		{
			if(x<n-1)  x++;
			else y++;
			direction=travse(!direction,x,y,n);
		}
	}
	return 0;
}
