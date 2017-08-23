/*2. Implement the following traditional symmetric ciphers.
a. Shift Cipher*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	cin>>str;
	int k;
	cin>>k;
	string res = "";
	
	for(int i=0;i<str.size();i++)
	{
		char c = (((str[i]-'a')+k)%26)+'a';
		res = res+c;
	}
	
	cout<<res<<endl;
	
	string dec;
	cin>>dec;
	int dek;
	cin>>dek;
	res.clear();
	for(int i=0;i<dec.size();i++)
	{
		int val = ((dec[i]-'a')-dek);
		
		while(val <0)
		{
			val = val+26;
		}
		char c = (val%26) + 'a';
		res = res+c;
	}
	
	cout<<res<<endl;
}
