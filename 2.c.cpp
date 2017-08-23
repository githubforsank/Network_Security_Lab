/*2. Implement the following traditional symmetric ciphers.
c. Affine Cipher*/
#include<iostream>
using namespace std;
int main()
{
	int k1,k2;
	cout<<"enter the value of keys: ";
	cin>>k1>>k2;;
	
	//encryption
	string str;
	char c;
	char t;
	string enc;
	cout<<"enter the input string";
	cin>>str;
	
	for(int i=0;i<str.size();i++)
	{
	   t = (((str[i]-97)*k1)%26)+97;
	   c = ((t+k2-97)%26)+97;
	   enc = enc + c;
	   
	}
	
	cout<<"the encrypted string is:";
	for(int i=0;i<enc.size();i++)
	{
		cout<<enc[i];
	}
	cout<<endl;
	
	//decryption
	string dec;
	char ch;
	char ch1;
	int k3,k4;
	
	for(int i=1;i<26;i++)
	{
		int r = (i*k1)%26;
		if(r==1)
		{
			k3= i;
		
		}
	}
	
	for(int i=1;i<26;i++)
	{
		int r = (i+k2)%26;
		if(r==0)
		{
			k4= i;
		
		}
	}
	
	for(int i=0;i<enc.size();i++)
	{
		if((enc[i]+k3-97)>0)
		{
	     ch = ((enc[i]+k4-97)%26)+97;
	     ch1 = (((ch- 97)*k3)%26)+97;
	     dec = dec + ch1;
       }
       else if((enc[i]+k3-97)<0)
       {
       	 ch = ((enc[i]+k4-97+26)%26)+97;
       	 ch1 = (((ch-97)*k3 +26)%26)+97;
       	 dec = dec + ch1;
       }
    }
    
    cout<<"the decrypted string is:";
	for(int i=0;i<dec.size();i++)
	{
		cout<<dec[i];
	}
	
}
