#include <bits/stdc++.h>
#define MAXN 5100
using namespace std;
int f[MAXN],wi[MAXN],hi[MAXN],po[MAXN];
int n,c_w,c_h;
int dfs(int p)
{
    int result=-1,max_n,t;
    if(f[p]!=-1)
        return f[p];
    for (int i = 0; i < n; i++)
        if(wi[i]>wi[p] && hi[i]>hi[p])
        {
            t=dfs(i);
            //result=max(result,dfs(i));
            if(t>result)
            {
                result=t;
                max_n=i;
            }
        }
    if(result==-1)
    {
        po[p]=-1;
        result=1;
    }
    else
    {
        po[p]=max_n;
        result++;
    }
    f[p]=result;
    
    return result;
}
void pr(int p)
{
    cout <<p+1<<' ';
    if(po[p]==-1)
        return;
    else
        pr(po[p]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n>>c_w>>c_h;
    bool flag=false;
    for (int i = 0; i < n; i++)
    {
        cin >>wi[i]>>hi[i];
        if(c_w<wi[i] && c_h<hi[i])
            flag=true;
    }
    if(!flag)
    {
        cout <<0;
        //system("pause");
        exit(0);
    }
    fill(&f[0],&f[MAXN-1],-1);
    fill(&po[0],&po[MAXN-1],-1);
    int result=-1,max_n,t;
    for (int i = 0; i < n; i++)
    {
        if(wi[i]>c_w && hi[i]>c_h)
        {
            t=dfs(i);
            //result=max(result,dfs(i));
            if(t>result)
            {
                result=t;
                max_n=i;
            }
        }
    }
    cout <<result<<endl;
    pr(max_n);
    system("pause");
    return 0;
}