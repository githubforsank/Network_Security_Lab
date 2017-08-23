/*1. Implement the following in Modular Arithmetic:
	c. Inverse of an mÅ~m matrix with m . 3*/
#include<bits/stdc++.h>
using namespace std;
vector<int> arr(26, -1);
int  calc(int r1, int r2, int s1, int s2, int t1, int t2)
{
	//cout<<r1<<"  "<<r2<<endl;
	if(!r2)
	{
		if(r1==1)
		{
			return(s1);
		}
		else
		{
			return -26;
		}
	}
	int q = r1/r2;
	int r = r1- q*r2;
	int s = s1- q*s2;
	int t = t1- q*t2;
	return(calc(r2, r, s2, s, t2, t));
}
void func()
{
	
	for(int i=1; i<26; i++)
	{
		int k = calc(26, i, 0, 1, 1, 0);
		
		if(k!=-26)
		{
			if(k>0)
			{
				arr[i] = k;
			}
			else
			{
				while(k<0)
				{
					k+=26;
				}
				arr[i] = k;
			}
		}
		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	func();
	cout<<"Enter the order of matrix: "<<endl;
	int n = 0;
	cin>>n;
	vector<vector<int> > mat(n, vector<int> (n));
	vector<vector<int> > vec(n, vector<int> (n, 0));
	cout<<"Enter a valid matrix: "<<endl;
	bool flag = 1;
	vector<int> vec1;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>mat[i][j];
		}
	}
	for(int i=0; i<n; i++)
	{
		vec[i][i] = 1;
	}
	for(int i=0; i<n; i++)
	{
		int k = arr[mat[i][i]];
		cout<<mat[i][i]<<" invert is "<<k<<endl; 
		if(k==-1)
		{
			flag = 0;
			cout<<"Inversion not possible !!"<<endl;
		}
		for(int j=0; j<n; j++)
		{
			mat[i][j]  = (mat[i][j]*k)%26;
			vec[i][j]  = (vec[i][j]*k)%26;
		}
		for(int j=(i+1)%n; j!=i; j = (j+1)%n)
		{
			int m = mat[j][i];
			for(int k=0; k<n; k++)
			{
				mat[j][k] = (mat[j][k] - mat[i][k]*m);
				while(mat[j][k]<0)
				{
					mat[j][k] += 26;
				}
				mat[j][k] %= 26;
				vec[j][k] = (vec[j][k] - vec[i][k]*m);
				while(vec[j][k]<0)
				{
					vec[j][k] += 26;
				}
				vec[j][k] %= 26;
			}
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<vec[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
}
