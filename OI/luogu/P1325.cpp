//Date:2017/9/10
//OJ:luogu
//Problem:1325
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;
vector<pair<double,double> >segs;
pair<int,int> islands[MAXN];
bool isCovered[MAXN]={false};
int n,d,ans=0;
bool cmp(pair<double,double> a,pair<double,double> b)
{
    return a.second==b.second?a.first<b.first : a.second <b.second;
}
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin >> n>>d;
    for(int i=0;i<n;i++)
    {
        cin >> islands[i].first>>islands[i].second;
        segs.push_back({0,0});
        segs[i].first=islands[i].first-sqrt(d*d-islands[i].second*islands[i].second);
        segs[i].second=islands[i].first+sqrt(d*d-islands[i].second*islands[i].second);
    }
    sort(segs.begin(),segs.end(),cmp);
    for(int i=0;i<n;i++) 
    {
        if(isCovered[i])    continue;
        pair<double,double> p;
        p=segs[i];
        isCovered[i]=true;
        ans++;
        //segs.erase(segs.begin());
        for(int j=0;j<n;j++)
            if(!isCovered[j] && segs[j].first <= p.second && segs[j].second >= p.second)
                isCovered[j]=true;
                //segs.erase(segs.begin()+i);
    }
    cout <<ans;
    return 0;
}