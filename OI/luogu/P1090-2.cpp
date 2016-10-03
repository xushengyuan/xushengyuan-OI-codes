#include<iostream>
#include<queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > q;//优先队列……
long long ans;int n,t,x,y;
int main()
{
    freopen("in.txt","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        q.push(t);
    }
    for (int i=1;i<n;i++)
    {
        x=q.top();q.pop();
        y=q.top();q.pop();
        ans+=x+y;q.push(x+y);
    }
    cout<<ans;
}
