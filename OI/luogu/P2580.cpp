#include <bits/stdc++.h>
#define MAXN 500001
using namespace std;
int n;
int son[MAXN][30],tot[MAXN];
int main()
{
    int root=1,cur=0,cnt=0,m;
    int i,j;
    char s[50];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        m=strlen(s+1);
        cur=root;
        for(j=1;j<=m;j++)
            if(son[cur][s[j]-'a'])
                cur=son[cur][s[j]-'a'];
            else    cur=son[cur][s[j]-'a']=++cnt;
        tot[cur]=1;      
    }
    cin >>n;
    for(i=1;i<=n;i++)
    {
		scanf("%s",s+1);
		m=strlen(s+1);
		for(j=1,cur=root;j<=m;j++)
			cur=son[cur][s[j]-'a'];
		if(tot[cur]==1)
        {
            puts("OK");
            tot[cur]=-1;
        }
		else if(tot[cur]==-1)
            puts("REPEAT");
		else 
            puts("WRONG");
	}
    //system("pause");
}