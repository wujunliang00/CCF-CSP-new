#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,k;
	int num=1;
	cin>>n>>k;
	queue<int> list;
	for(int i=1; i<=n; i++)
	{
		list.push(i);
	}
	while(list.size()>1)
	{
		int top=list.front();
		list.pop();
		if(num%k!=0 && (num%10)!=k)
		{
			list.push(top);
		}
		num++;
	}
	cout<<list.front();
	return 0;
}
