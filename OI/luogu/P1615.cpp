#include <bits/stdc++.h>
#define _DEBUG
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int a,b,c,d,e,f,x;
    char ch;
    std::cin>>a>>ch>>b>>ch>>c>>d>>ch>>e>>ch>>f>>x;
    std::cout<<((d-a)*3600+(e-b)*60+(f-c))*x;
    return 0;
}