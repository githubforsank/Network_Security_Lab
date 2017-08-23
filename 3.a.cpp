/*3. Write programs to carry out exhaustive key search attacks on the Shift Cipher, Multiplicative Cipher and Affine Cipher that you have implemented. (Aim to attack a cipher is to break its key.)
a. Hence use an exhaustive key search to decrypt the following ciphertext, which was encrypted using a Shift Cipher:
BMMTDXLTANZXXYYHKMMHYKXXRHNKLXEYYKHFFXFHKR*/
#include<bits/stdc++.h>

using namespace std;

int inv(int dat)
{
	for(int i=0;i<26;i++)
	{
		if(!((dat+i)%26))
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
	string res = "";
	for(int i=0;i<26;i++)
	{
		k = inv(i);
		for(int j=0;j<str.size();j++)
		{
			char c= ((str[j]-'a'+k)%26)+'a';
			res = res+c;
		}
		cout<<res<<" "<<i<<endl;
		res.clear();
		cout<<endl;
	}
}
