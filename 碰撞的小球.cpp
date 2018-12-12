#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num,length,t;
	cin>>num>>length>>t;
	int count[num],b[num],a[num],flag[num];
	for(int i=0; i<num; i++)
	{
		cin>>a[i];
		b[i]=a[i];
		flag[i]=1; 
	}
	sort(a,a+num);
	
	for(int i=0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			if(a[i]==b[j])
			{
				count[i]=j;
				break;
			}
		}
	}
	 for(int i=0; i<num; i++)
	{
		cout<<count[i]<<" ";
	}	
    for(int j=1; j<=t; j++)
    {
    	for(int i=0; i<num; i++)
    	{
    		if(flag[i]==1&&a[i]<length&&a[i]!=a[i+1])
    		{
    			a[i]++;
			}
			else if(flag[i]==1&&a[i]==length)
			{
				flag[i]=0;
				a[i]=length-1;
			}
			else if(flag[i]==0&&a[i]>0&&a[i]!=a[i-1])
			{
				a[i]--;
			}
			else if(flag[i]==0&&a[i]==0)
			{
				flag[i]=1;
				a[i]=1;
			}
			else if(flag[i]==1&&flag[i+1]==0&&a[i]==a[i+1])
			{
				flag[i]=0;
				flag[i+1]=1;
				a[i]--;
				a[i+1]++;
				if(i+1>=num)
				break;
				else i=i+1; 
			}
			else if(flag[i]==0&&flag[i-1]==1&&a[i]==a[i-1])
			{
				flag[i]=1;
				flag[i-1]=0;
				a[i]++;
				a[i-1]--;
			}
		}			
	}
    for(int i=0; i<num; i++)
	{
		cout<<a[count[i]]<<" ";
	}
	return 0;
}
