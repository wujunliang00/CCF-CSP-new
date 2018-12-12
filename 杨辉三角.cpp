#include<iostream>
using namespace std;
int cent[35][35];
int main()
{
	int num;
	while(cin>>num)
	{
		cent[0][0]=1;
		for(int i=0; i<num; i++)
		{
			cent[i][0]=1;
			cent[i][i]=1;
		}
	
		for(int i=1; i<num; i++)
		{
		    for(int j=0; j<num; j++)
		    {
		    	cent[i][j]=cent[i-1][j]+cent[i-1][j-1];
			}
		}
		
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<=i; j++)
			{
				cout<<cent[i][j];
				if(j!=i)
				{
					cout<<" ";
				 } 
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
