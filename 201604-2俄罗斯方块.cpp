#include<bits/stdc++.h>
using namespace std;

int main()
{
	int data[23][10];
	int module[4][4];
	int n;
	int i,j,k;
	bool key=false;
	for(i=0;i<23;i++)
	   for(j=0;j<10;j++)
	      data[i][j]=0;
	for (i = 4; i < 19; i++)  
        for (j = 0; j < 10; j++)  
            cin >> data[i][j];  
    for (i = 0; i < 4; i++)  
        for (j = 0; j < 4; j++)  
            cin >> module[i][j];  
    cin >> n; 
	for(i=0;i<20;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if((i+j)<19)
				{
					if(module[j][k]+data[i+j][k+n-1]>1)
					{
						key=true;
						break;
					}
				}
				else 
				{
					if(module[j][k]+data[i+j][k+n-1]>0)
					{
						key=true;
						break;
					}
				}
			}
			if(key==true)
			break;
		}
		if(key==true)
		break;
	}	   
	i=i-1;
	for(j=0;j<4;j++)
	{
		for(k=0;k<4;k++)
		{
			data[i+j][k+n-1]+=module[j][k];
		}
	}
	for(i=4;i<19;i++)
	{
		for(j=0;j<10;j++)
		  cout<<data[i][j]<<" ";
		  cout<<endl;
	}
	return 0;
 } 
