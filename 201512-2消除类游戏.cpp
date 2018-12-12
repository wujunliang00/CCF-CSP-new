#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int data[n][m],data1[n][m];
	for(int i=0; i<n; i++)
	   for(int j=0; j<m; j++)
	       {
		   cin>>data[i][j];
		   data1[i][j]=data[i][j];
	       }
	for(int i=0; i<n; i++)
	{
		for(int j=1; j<m-1; j++)
		{
			if(data[i][j]==data[i][j-1]&&data[i][j]==data[i][j+1])
			{
				data1[i][j]=0;
				data1[i][j-1]=0;
				data1[i][j+1]=0;
			}
		}
    }   
	for(int i=1; i<n-1; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(data[i][j]==data[i-1][j]&&data[i][j]==data[i+1][j])
			{
				data1[i][j]=0;
				data1[i-1][j]=0;
				data1[i+1][j]=0;
			}
		}
    } 
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<data1[i][j]<<" ";
		}
		cout<<endl;
	}   
	return 0;
}
