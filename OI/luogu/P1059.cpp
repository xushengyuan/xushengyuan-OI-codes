#include<iostream>
#include<set>
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	set<int> s;
	int i,j,n,m;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		s.insert(m);
	}
	cout<<s.size()<<endl;
	set<int>::iterator it;
	for (it=s.begin(); it!=s.end(); ++it)
    	cout <<*it<<' ' ;
	return 0;
}
