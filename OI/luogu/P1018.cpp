//Date:2017/9/28
//OJ:luogu
//Problem:1018
//Solution:DP+HP
//By:xushengyuan
#include <bits/stdc++.h>
#define MAXN 45
using namespace std;
struct BI
{
    int top,numb[MAXN];
    BI()
    {
        top=0;
        memset(numb,0,sizeof(numb));
    }
    BI(string s)
    {
        memset(numb,0,sizeof(numb));
        top=s.length()-1;
        for(int i=0;i<s.length();i++)
            numb[s.length()-i-1]=s[i]-'0';
    }
    print()
    {
        for(int i=top;i>=0;i--)
            cout<<numb[i];
    }
};
const BI operator*(const BI &x,const BI &y)
{
    BI ret;
    ret.top=x.top+y.top-1;
    for(int i=0;i<=x.top;i++)
        for(int j=0;j<=y.top;j++)
        {
            ret.numb[i+j] += x.numb[i]*y.numb[i];
            ret.numb[i+j+1] += ret.numb[i+j]/10;
            ret.numb[i+j]%=10;
        }
    for(int i=0;i<=ret.top;i++)
    {
        ret.numb[i+1] +=ret.numb[i]/10;
        ret.numb[i]%=10;
    }
    if(ret.numb[ret.top+1]!=0)
        ret.top++;
    return ret;
}
bool operator<(const BI &x,const BI &y)
{
    if(x.top!=y.top)
        return x.top<y.top;
    for(int i=x.top;i>=0;i--)
        if(x.numb[i]!=y.numb[i])
            return x.numb[i]<y.numb[i];
    return true;
}
int k;
BI n;
BI st_num[50][50];
string tmp;
void init()
{
    string t;
    for(int i=0;i<=n.top;i++)
    {
        for(int j=i;j<=n.top;j++)
        {
            t.clear();
            t.insert(0,tmp,i,j-i+1);
            //cout<<t<<endl;
            st_num[i+1][j+1]=*(new BI(t));
            st_num[j+1][i+1]=st_num[i+1][j+1];
        }
    }
    return ;
}
int main()
{
    //#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    //#endif
    int zzzz;
    cin>>zzzz>>k>>tmp;
    n=*(new BI(tmp));
    init();
    BI f[MAXN][10];
    //n.print();
    //cout<<endl;
    for(int i=1;i<=n.top+1;i++)
    {
        for(int j=1;j<=n.top+1;j++)
        {
            st_num[i][j].print();
            cout<<' ';
        }
        cout<<endl;
    }
    for (int i=1;i<=zzzz;i++)
        f[i][0]=st_num[1][i];
    for(int l=1;l<=k;l++)
        for(int i=2;i<=zzzz;i++)
            for(int j=i-1;j>=1;j--)
                f[i][l]=max(f[i][l],f[j][l-1]*st_num[j+1][i]);
    
    for(int i=1;i<=zzzz;i++)
    {
        for(int j=1;j<=k;j++)
        {
            f[i][j].print();
            cout<<' ';
        }
        cout<<endl;
    }
    f[zzzz][k].print();
    return 0;
}