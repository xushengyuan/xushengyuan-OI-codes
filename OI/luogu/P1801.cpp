//Date:2018/2/13
//OJ:luogu
//Problem:1801
//Solution: pb_ds
//By:xushengyuan
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>  
#include<ext/pb_ds/tree_policy.hpp>  
#define MAXN 200000
using namespace __gnu_pbds;  
using namespace std;
tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> t; 
int m,n;
long long a[MAXN],u[MAXN];
int main()
{
    cin>>m>>n;
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>u[i];
    int p=0,k=0;
    sort(u,u+n);
    for(int i=0;i<m;i++)
    {
        t.insert((a[i]<<16)+i);
        while(u[p]==i+1)
        {
            k++;
            cout<<(*(t.find_by_order(i+1-k-1)))>>16<<endl;
            p++;
        }
    }
    return 0;
}