#include<iostream>
#include<cstdlib>
using namespace std;
int t,count;
int a[400],b[400];//����˼ۣ�����˼� 
bool f[301][301][301]; //����״̬��Ϣ��Ҳ����dfs��n,x,y 
void dfs(int n,int x,int y)//�ֱ����ѵ���n�죬b[n-1]�����˵�n-1��Ĳ˼ۣ�,b[n]�����˵�n��Ĳ˼ۣ�
{ 
	if(f[n][x][y])return;//��֦������ֻ��80�� 
	f[n][x][y]=1;
	if(n==t-1) //���һ��˼����⴦������nֻ�õ���t-1�͹��� 
	{
		if((3*a[n]-x)/2==a[t]||(3*a[n]-x+1)/2==a[t]||(3*a[n]-x+2)/2==a[t]) //���һ��˼� 
		{
			//cout<<count<<endl;
			for(int i=1;i<=n;++i)    //��� 
			cout<<b[i]<<" ";
			for(int i=0;i<3;++i)
			{
				if((3*a[n]-x+i)/2==a[t]) //������һ��˼�
				{
					cout<<3*a[n]-x-y+i;
					exit(0);  //ֱ�ӽ�������������ʱ���� 
				}
			}
		}
		return;
	}
	for(int i=0;i<3;++i) 
	{
		b[n+1]=3*a[n]-x-y+i; //���ƹ�ϵʽ 
		if(b[n+1]>=1)
		dfs(n+1,y,b[n+1]);
	}
}
int main()
{
	cin>>t;
	for(int i=1;i<=t;++i)
	cin>>a[i];
	for(int i=1;i<=2*a[1];++i)
	{
		b[1]=i,b[2]=2*a[1]-i;  //��һ��˼ۣ������ֿ��� 
		dfs(2,i,b[2]);
		b[1]=i,b[2]=2*a[1]-i+1; //�ڶ��ֿ��� 
		dfs(2,i,b[2]);
	} 
	return 0;
}


