#include<iostream>
#include<queue>
using namespace std;

long long sum;
long long n,temp,a,b;
priority_queue<long long ,vector<long long>,greater<long long> > pqueue;
int main()
{
    freopen("in.txt","r",stdin);
    long long i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        pqueue.push(temp);
    }
    for(i=0;i<n-1;i++)
    {
        a=pqueue.top();
        pqueue.pop();
        b=pqueue.top();
        pqueue.pop();
        pqueue.push(a+b);
        sum+=a+b;
    }
    cout<<sum;
    return 0;
}
