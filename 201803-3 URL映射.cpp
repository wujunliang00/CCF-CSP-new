#include<iostream>
#include<ctype.h>
using namespace std;

const int N=100;
string p[N],r[N],s;

bool match(string &s, string &t, bool flag)
{
	int lent =t.size();   //t 的长度 
	int lens =s.size();   //s 的长度 
	int ps=0,pt=0;
	while(ps<lens && pt<lent)
	{
		if(t[pt]==s[ps]){
			ps++,pt++;
		}
		else{   //匹配<XXX> 
			if(t[pt++]!='<')
			return false;
			if(flag)
			  cout<<' ';
			if(t[pt]=='i'){
				bool ok=false;
				while(s[ps]&&isdigit(s[ps])){ 
					if(s[ps]!='0')
					   ok=true;
					if(flag && ok)
					   cout<<s[ps];
					ps++;
			}
			if(!ok)
			   return false;
			pt +=4;
		}
		else if (t[pt]=='s'){
		     bool ok=false;
		     while(s[ps]&&s[ps]!='/'){
		     	ok=true;
		     	if(flag)
		     	   cout<<s[ps];
		     	ps++;
			 }
			 if(!ok)
			     return false;
		     pt+=4;
		}
		else if(t[pt]=='p'){
			if(flag)
			   while(s[ps])
			      cout<< s[ps++];
			return true;
		}
	}
	} 
	return pt==lent && ps==lens;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	   cin>>p[i]>>r[i];
	for(int i=0; i<m; i++){
		cin>>s;
		bool flag=true;
		for(int j=0; flag && j<n ; j++)
		    if(match(s,p[j],false)){
		    	flag=false;
		    	cout<<r[j];
		    	match(s,p[j],true);
			}
			if(flag)
			   cout<<"404";
			cout<<endl;
	}
    return 0;
}






