#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int mp[4][4];
bool hok(int h,int f){
	return mp[h][0]==f&&mp[h][0]==mp[h][1]&&mp[h][1]==mp[h][2];   //输出为1，行 
}
 
bool lok(int l,int f){
	return mp[0][l]==f&&mp[0][l]==mp[1][l]&&mp[1][l]==mp[2][l]; //输出为1，列 
}

int spa(){
	int res=0;
	for(int i=0; i<3; i++)
	   for(int j=0; j<3; j++)
	       if(!mp[i][j]) res++;
	return res;     //这是计数空格 ++ 
}

int win(int f){    //判断当前的局数的胜负 
	int wi=0,ans=1;
	if(hok(0,f)||hok(1,f)||hok(2,f))  wi=1;  
	if(lok(0,f)||lok(1,f)||lok(2,f))  wi=1;  
	if(mp[0][0]==f&&mp[0][0]==mp[1][1]&&mp[1][1]==mp[2][2])   wi=1;   //斜对角 
	if(mp[0][2]==f&&mp[0][2]==mp[1][1]&&mp[1][1]==mp[2][0])   wi=1;  //斜对角 
	if(!wi)  return 0;
	ans+=spa();
	return (f==1)?ans:-ans;  
}

int dfs(int peo){                      //对抗搜索 
	if(!spa())  return 0;   //这个是说如果填满了的话平手 
	int Max=-10,Min=10;     
	for(int i=0; i<3; i++){
		for(int j=0,w; j<3; j++){     
			if(!mp[i][j]){     //判断1 2  
				mp[i][j]=peo+1;   // (原本的peo + 空格)下棋位置 
				w=win(peo+1);
				if(w){
					mp[i][j]=0;
					return w>0?max(Max,w):min(Min,w);
				}
				if(!peo) Max=max(Max,dfs(1));
				else Min=min(Min,dfs(0));
				mp[i][j]=0;    //枚举可以落棋的位置 
			}
		}
	}
	return peo?Min:Max; //1选择最小，0选择最大 
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<3; i++)
		   for(int j=0; j<3; j++)
		       cin>>mp[i][j];
	    int x=win(1),y=win(2);
	    if(x)
	    {
	    	cout<<x<<endl;continue;
		}
		if(y)
		{
			cout<<y<<endl;continue;
		}
		cout<<dfs(0)<<endl;
	}
	return 0;
}



