#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 100000
using namespace std;
char str[MAXN];
int len=1;
void fun11()
{
    int i,s1=0,s2=0;
    for(i=0;i<len;i++)
    {
        if(str[i]=='W')
            s1++;
        else if(str[i]=='L')
            s2++;
        if((s1>=11 && s1-s2>=2)||(s2>=11 && s2-s1>=2))
        {
            cout<<s1<<':'<<s2<<endl;
            s1=0;
            s2=0;
        }
    }
    cout<<s1<<':'<<s2<<endl;
    return ;
}
void fun21()
{
    int i,s1=0,s2=0;
    for(i=0;i<len;i++)
    {
        if(str[i]=='W')
            s1++;
        else if(str[i]=='L')
            s2++;
        if((s1>=21 && s1-s2>=2)||(s2>=21 && s2-s1>=2))
        {
            cout<<s1<<':'<<s2<<endl;
            s1=0;
            s2=0;
        }
    }
    cout<<s1<<':'<<s2<<endl;
    return ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char stemp;
    stemp=getchar();
    while(1)
    {
        if(stemp=='E') break;
        str[len-1]=stemp;
        len++;
        stemp=getchar();
    }
    fun11();
    cout<<endl;
    fun21();
    return 0;
}
