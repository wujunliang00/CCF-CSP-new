#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<ctype.h>
#include<string>

using namespace std;
const int N=105;
struct Node{
	string lable,id;
	int d;//缩进 
}a[N];

vector<string>demand;
map<string,int>an,query;//an表示各个祖先含有的标签，id属性等，query表示为查询的
//将字符串s转换为小写串 
string mystrlwr(string s)
{
    for(int i=0; i<s.length();i++)
	 s[i]=tolower(s[i]);
	 return s;	
}

void split(char *s,vector<string>&v) {
	v.clear();
	char *p=strtok(s," ");
	while(p){
		v.push_back(p);
		p=strtok(NULL," ");
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	getchar();
	for(int i=1; i<=n; i++)
	{
		string s;
		getline(cin,s);
		int cnt=0;
		for(int j=0; j<s.length()&&s[j]=='.'; j++,cnt++);
		int len=0,pos=-1;
		for(int j=cnt; j<s.length(); j++,len++)
		{
			if(s[j]==' '){
				if(j+1<s.length()&&s[j+1]=='#')
				   pos=j+1;
				   break;
			}
		}
		a[i].d=cnt;
		a[i].lable=s.substr(cnt,len);
		a[i].lable=mystrlwr(a[i].lable);
		if(pos==-1)
		   a[i].id="";
		else 
		   a[i].id=s.substr(pos);
	}
	while(m--){
		char d[100];
		gets(d);
		split(d,demand);
		vector<int>ans;
		if(demand.size()==1){
			string q=demand[0];
			if(q[0]!='#')
			   q=mystrlwr(q);
			for(int i=1; i<=n; i++)
			   if(q==a[i].lable || q==a[i].id)
			    ans.push_back(i);
		}
		else{
			query.clear();
			for(int i=0; i<demand.size()-1; i++){
				if(demand[i][0]!='#')
				   demand[i]=mystrlwr(demand[i]);
				query[demand[i]]++;
			}
			string q=demand.back();
			if(q[0]!='#')
			   q=mystrlwr(q);
			for(int i=1; i<=n; i++)
			   if(q==a[i].lable||q==a[i].id){
			   	   an.clear();
			   	   for(int j=i-1;j>0&&a[j].d<=a[i].d; j--){
			   	   	         if(a[j].d==a[i].d)  continue;
			   	   	         an[a[j].lable]++;
			   	   	         if(a[j].id!="")
			   	   	            an[a[j].id]++;
					  }
				   bool flag=true;
				   for(map<string,int>::iterator it=query.begin();it!=query.end(); it++)
				      if(an.count(it->first)==0||an[it->first]<it->second){
				      	flag=false;
				      	break;
					  }
					 if(flag)
					   ans.push_back(i);
			   }
		}
	printf("%d",ans.size());
	for(int i=0; i<ans.size(); i++)
	   cout<<" "<<ans[i];
	cout<<endl;	 
	}
	return 0;
}
