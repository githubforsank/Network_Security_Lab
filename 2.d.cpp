/*2. Implement the following traditional symmetric ciphers.
d. Playfair Cipher*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
	map<char,pair<int,int> > loc;
	string inp;
	string res = "";
	cin>>inp; 
	vector<vector<char> > ke(5,vector<char>(5));
	
	int r=0;
	int col = 0;
	for(int i=0;i<9;i++)
	{
		col = col%5;
		loc[('a'+i)] = make_pair(r,col);
		ke[r][col] = ('a'+i);
		col++;
		if((col%5)==0)
		{
			r++;
		}
	}
	
	for(int i=10;i<26;i++)
	{
		col = col%5;
		loc[('a'+i)] = make_pair(r,col);
		ke[r][col] = ('a'+i);
		col++;
		if((col%5)==0)
		{
			r++;
		}
	}
	
	string teres = "";
	char ls = '1';
	for(int i=0;i<inp.size();i++)
	{
		if(ls!='1')
		{
			if(ls==inp[i])
			{
				teres = teres+'x'+inp[i];
				ls = inp[i];
			}
			
			else
			{
				teres = teres+inp[i];
				ls = inp[i];
			}
		}
		
		else
		{
			ls = inp[i];
			teres = teres+inp[i];
		}
	}
	
	if((teres.size()%2)!=0)
	{
		teres = teres+'x';
	}
	
	for(int i=0;i<teres.size();i+=2)
	{
		int r1;
		int r2;
		int c1;
		int c2;
		
		r1 = loc[teres[i]].first;
		c1 = loc[teres[i]].second;
		
		r2 = loc[teres[i+1]].first;
		c2 = loc[teres[i+1]].second;
		
		if(r1==r2)
		{
			res = res+ke[r1][(c1+1)%5];
			res = res+ke[r2][(c2+1)%5];
		}
		
		else if(c1==c2)
		{
			res = res+ke[(r1+1)%5][c1];
			res = res+ke[(r2+1)%5][c2]; 
		}
		
		else
		{
			res = res+ke[r1][c2];
			res = res+ke[r2][c1];
		}
	}
	
	cout<<res<<endl;
}
