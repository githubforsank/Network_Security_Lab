/*2. Implement the following traditional symmetric ciphers.
b. Multiplicative Cipher*/
#include<bits/stdc++.h>

using namespace std;

int inverse(int dek)
{
	for(int i=1;i<26;i++)
	{
		if((dek*i)%26 == 1)
		{
			return i;
		}
	}
}

int main()
{
	string str;
	cin>>str;
	int k;
	cin>>k;
	string res = "";
	
	for(int i=0;i<str.size();i++)
	{
		char c = (((str[i]-'a')*k)%26)+'a';
		res = res+c;
	}
	
	cout<<res<<endl;
	
	string dec;
	cin>>dec;
	int dek;
	cin>>dek;
	res.clear();
	int invdek = inverse(dek);
	for(int i=0;i<dec.size();i++)
	{
		int val = ((dec[i]-'a')*invdek);
		
		while(val <0)
		{
			val = val+26;
		}
		char c = (val%26) + 'a';
		res = res+c;
	}
	
	cout<<res<<endl;
}
