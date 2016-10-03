#include<iostream>
#include<algorithm>
#include<stdin>
#define MAX_N 1000
using namespace std;
int n,data[MAX_n],sum=0;
pair<int,int> p;
priority_queue<p,vector<p>,greater<p>> pqueue;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>data[i];
        pqueue.push()
    }
    for(i=0;i<n;i++)
    {
        sum+=pqueue.top()*n-i-1;
        pqueue.pop();
        sum/=n;
    }

    return 0;
}