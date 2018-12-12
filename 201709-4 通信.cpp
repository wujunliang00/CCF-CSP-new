#include<iostream>
#include<vector>
using namespace std;

int map[1001][1001];
vector<int> path[1001];  //ถþฮฌสýื้ 

void dfs(int a,int visit[], int b){
	visit[a]=1;
	map[a][b]=1;
	map[b][a]=1;
	for(int i=0; i<path[a].size(); i++){
		if(visit[path[a][i]]==0)
		   dfs(path[a][i],visit,b);
	}
} 

int main()
{
	int n,m,i,j,a,b,cnt=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		path[a].push_back(b);
	}
	for(i=1;i<=n;i++)
	{
		int visit[1001]={0};
		dfs(i,visit,i);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
		{
			if(map[i][j]==0)
			break;
		}
		if(j==n+1)
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
} 
