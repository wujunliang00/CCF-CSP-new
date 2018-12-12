#include<iostream>
using namespace std;
int main()
{
	int num;
	while(cin>>num)
	{
		if(num<0||num>100)
		    cout<<"Score is error!"<<endl;
	  	else if(num<=59)
			cout<<"E"<<endl;
		else if(num<=69)
			cout<<"D"<<endl;
		else if(num<=79)
			cout<<"C"<<endl;
		else if(num<=89)
			cout<<"B"<<endl;
		else if(num<=100)
			cout<<"A"<<endl;
	}
	return 0;
}
