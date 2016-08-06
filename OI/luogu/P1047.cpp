#include<iostream>

using namespace std;
bool tree[10002];
int main()
{
	int i,j,l,m,rl,ll,sum=0;
	cin>>l>>m;
	l;
	for(i=0;i<=l;i++)
		tree[i]=true;
	for(i=0;i<m;i++)
	{
		cin>>rl>>ll;
		for(j=rl;j<=ll;j++)
			tree[j]=false;
	}
	for(i=0;i<=l;i++)
		if(tree[i]==true)
			sum++;
	cout<<sum;
	return 0;
}
