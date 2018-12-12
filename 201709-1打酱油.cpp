#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=n/10;
	if(sum>=5)
	{
		int sum1=sum/5;
		int sum2=(sum-sum1*5)/3;
		int sum3=sum-sum1*5-sum2*3;
		cout<<sum1*7+sum2*4+sum3;
	}
	else if(sum>=3)
	{
		int sum1=sum/3;
		int sum2=sum-sum1*3;
		cout<<sum1*4+sum2;
	}
	else cout<<sum;
	return 0;
}
