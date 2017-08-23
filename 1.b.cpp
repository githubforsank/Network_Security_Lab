/*I1. Implement the following in Modular Arithmetic:
	b. Multiplicative inverse of a number*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	int b;
	int m;
	int res = -1;
	cin>>a>>m;
	
	for(int i=0;i<m;i++)
	{
		if(((a*i)%m)==1)
		{
			res = i;
			break;
		}
	}
	
	if(res!=-1)
	{
		cout<<res<<endl;
	}
}
