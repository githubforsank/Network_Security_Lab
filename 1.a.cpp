/*1. Implement the following in Modular Arithmetic:
a. Additive inverse of a number*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	int b;
	int m;
	int res;
	cin>>a>>m;
	
	for(int i=0;i<m;i++)
	{
		if(!((a+i)%m))
		{
			res = i;
			break;
		}
	}
	
	cout<<res<<endl;
}
