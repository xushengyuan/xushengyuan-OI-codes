#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int data[10005],f[10005];
int n,m;
int find(int a)
{
    if(f[a]==a)
        return a;
    else
        return f[a]=find(f[a]); 
}
int getint()
{
    int result=0;
    char c;
    c=getchar();
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        result*=10;
        result+=c-'0';
        c=getchar();
    }
    return result;
}
int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,temp,x,y;
    cin>>n>>m;
    for(i=0;i<n;i++)
        f[i]=i;
    for(i=0;i<m;i++)
    {
        temp=getint();
        x=getint();
        y=getint();
        if(temp==1)
        {
            f[find(x)]=find(y);
        }
        else if(temp==2)
        {
            if(find(x)==find(y))
                cout<<'Y'<<endl;
            else
                cout<<'N'<<endl;
        }
    }
    return 0;
}