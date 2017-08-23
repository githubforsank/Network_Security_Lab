/* Assignment (3b): Write programs to carry out exhaustive key search attacks on the Shift Cipher, 
Multiplicative Cipher and Affine Cipher that you have implemented.
(Aim to attack a cipher is to break its key.)
Hence use an exhaustive key search to decrypt the following ciphertext, which was encrypted using a Multiplicative Cipher:
WFEJBYOFAJZEYDCMRBKJRKWABKXSWKJZSFQ*/
#include<iostream>
using namespace std;
int main()
{
	string str;
	cout<<"enter the long string: ";
	cin>>str;
	int n=26;
	int key[12]={1,3,5,7,9,11,15,17,19,21,23,25};
	char c;
	string dec;
	int key1[12];
	
	//decryption
	
	for(int i=1;i<26;i++)
	{
		for(int j=0;j<12;j++)
		{
		  int r = (i*key[j])%26;
		  if(r==1)
		   {
			key1[j]= j;
		
		   }
	   }
	}
	
	
	for(int i=0;i<12;i++)
	{
		cout<<key1[i]<<endl;
	}
	
	for(int j=0;j<26;j++)
	{
		for(int i=0;i<str.size();i++)
		 { 
	       c = (((str[i]-97)*key1[j])%26)+97;
	       dec = dec + c; 
         }
       
          cout<<"the decrypted string is:";
		  cout<<dec;
		  cout<<" "<<j<<endl;
	      dec="";
          cout<<endl;
       
	}
	
	
}
