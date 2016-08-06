for a := 0 to n do
begin
	f[a][0] := 1;
	for b := 1 to a do
		f[a][b] := f[a-1][b-1]+f[a-1][b];
end;


for (int a=0;a<=n;a++)
{
	f[a][0]=1;
	for (int b=1;b<=min(a,m);b++)
		f[a][b]=f[a-1][b-1]+f[a-1][b];
}

f[a][0] = f[a-1][-1] + f[a-1][0]

for a <- 1 to n
	f[a] <- max(f[a-1],f[a-2]) + z[a]

for a <- 0 to n
	f[a][0] <- 1
for a <- 0 to m
	f[0][a] <- 1
for a <- 1 to n
	for b <- 1 to m
		f[a][b] <- f[a][b-1] + f[a-1][b]

for a <- 0 to n
	for b <- 0 to m
		f[a+1][b] <- f[a+1][b] + f[a][b]
		f[a][b+1] <- f[a][b+1] + f[a][b]
		
for edge qidian
	dist[zhongdian] = dist[qidian] + edge.changdu		

for a <- 1 to n
	for b <- 1 to m
		f[a][b] <- max ( f[a][b-1] , f[a-1][b] ) + z[a][b]
		f[a][b] <- min ( f[a][b-1] , f[a-1][b] ) + z[a][b]

f[1][1] <- z[1][1]
for a <- 2 to n
	for b <- 1 to a
		f[a][b] <- max( f[a-1][b-1], f[a-1][b] ) + z[a][b]

f[1] <- 1
f[2] <- 1
for a <- 3 to n
	f[a] <- f[a-1] + f[a-2]

a <- 1
b <- 1
for c <- 3 to n
	d <- a+b
	a <- b
	b <- d

for(int i=1; i<=n; i++)
{
	f[i]=1;
	for(int j=1;j<i;j++)
		if(a[i]>a[j]) f[i]=max(f[i],f[j]+1);
}
int t=1;
for(int i=1; i<=n; i++)
	t=max(t,f[i]);

for i:=1 to n do
begin
  b[i]:=1;
  for j:=1 to i do
    if (a[i]>a[j]) f[j]:=max(f[i],f[j]+1);
end;
for i:=1 to n do
begin
  t:=max(t,b[i]);
end;

f[1] <- 1
f[2] <- 1
for a <- 3 to n
	f[a] <- f[a-1] + f[a-2]

f=[]
g=[]

function dfs(i)
	if (g[i] true) return f[i]
	g[i] <- true
	x
	if (i<=2) then x <- 1
	else x <- dfs(i-2)+dfs(i-1)
	f[i] <- x
	return x

dfs(n)

O(f(n))=

((sqrt(5)+1)/2)^n-((sqrt(5)-1)/2)^n

#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
const int maxn=20000;
int r,c,l,dp[maxn];
struct point
{
	int x,y,h;
}p[maxn];
int qsort(int a,int b)
{
	int c=a,d=b,e=p[(a+b)>>1].h;
	point f;
	do
	{
		while (p[c].h<e)
			c++;
		while (e<p[d].h)
			d--;
		if (c<=d)
		{
			f=p[c];p[c]=p[d];p[d]=f;
			c++;d--;
		}
	}while (c<=d);
	if (a<d) qsort(a,d);
	if (c<b) qsort(c,b);
	return(0);
}
int abs(int a)
{
	if (a<0) return(-a);
	return(a);
}
bool close(int a,int b)
{
	if (abs(p[a].x-p[b].x)+abs(p[a].y-p[b].y)==1) return(true);
	return(false);
}
int main()
{
	scanf("%d%d",&r,&c);
	for (int a=1;a<=r;a++)
		for (int b=1;b<=c;b++)
		{
			l++;
			scanf("%d",&p[l].h);
			p[l].x=a;
			p[l].y=b;
		}
	qsort(1,l);
	dp[1]=1;
	int ans=1;
	for (int a=2;a<=l;a++)
	{
		for (int b=1;b<a;b++)
			if ((p[b].h<p[a].h) && (close(a,b)) && (dp[b]>dp[a])) dp[a]=dp[b];
		dp[a]++;
		if (dp[a]>ans) ans=dp[a];
	}
	printf("%d\n",ans);
	return(0);
}

program area;
type
  step=array[1..4] of longint;
const
  bx:step=(0,1,0,-1);
  by:step=(1,0,-1,0);
var
  z:array[0..100,0..100] of longint;
  a,b,c,r,max:longint;
  x,y:array[0..5000] of longint;
procedure suan(a,b,now:longint);
var
d,ba,bb:longint;
t:boolean;
begin
  t:=false;
  for d:=1 to 4 do
  begin
    ba:=a+bx[d];
    bb:=b+by[d];
    if (ba>0) and (ba<=r) and (bb>0) and (bb<=c) and (z[ba,bb]>z[a,b]) then begin
                                                                              t:=true;
                                                                              suan(ba,bb,now+1);
                                                                            end;
  end;
  if t=false then if now>max then max:=now;
end;
begin
  read(r,c);
  for a:=1 to r do
    for b:=1 to c do
    read(z[a,b]);
  readln;
  for a:=0 to c+1 do
  begin
    z[0,a]:=maxlongint;
    z[r+1,a]:=maxlongint;
  end;
  for a:=1 to r do
  begin
    z[a,0]:=maxlongint;
    z[a,c+1]:=maxlongint;
  end;
  for a:=1 to r do
    for b:=1 to c do
    begin
      if (z[a-1,b]>=z[a,b]) and (z[a+1,b]>=z[a,b]) and (z[a,b-1]>=z[a,b]) and (z[a,b+1]>=z[a,b]) then begin
                                                                                                        inc(x[0]);
                                                                                                        x[x[0]]:=a;
                                                                                                        inc(y[0]);
                                                                                                        y[y[0]]:=b;
                                                                                                      end;
    end;
  for a:=0 to c+1 do
  begin
    z[0,a]:=-1;
    z[r+1,a]:=-1;
  end;
  for a:=1 to r do
  begin
    z[a,0]:=-1;
    z[a,c+1]:=-1;
  end;
  for a:=1 to x[0] do
    suan(x[a],y[a],1);
  writeln(max);
end.

w[] v[]
for a <- 0 to n-1 do
	for b <- 0 to m do
		f[a+1][b+v[a+1]] = max( f[a+1][b+v[a+1]],f[a][b]+w[a+1])
		f[a+1][b] = max ( f[a+1][b], f[a][b])
nm
ans
for b <- 0 to m
	ans = max (ans, f[n][b])

z[]
maxv = z[1]
for a <- 2 to n 
	maxv = max ( maxv , z[a])

for a <- 0 to n-1 do
	for b <- 0 to m do
		for c <- 0 to num[a] do
			f[a+1][b+c*v[a+1]] = max( f[a+1][b+c*v[a+1]],f[a][b]+c*w[a+1])

	nm^2

	f[i][j]
	f[i] i

for a <- 1 to n
	for b <- m-v[a] downto 0 
	for (int b=m-v[a];b>=0;b--)
	for (int b=0;b<=m-v[a];b++)
		f[b+v[a]] = max ( f[b+v[a]] , f[b]+w[a] )

for a <- 1 to n
	for b <- 0 to m-v[a]
		f[b+v[a]] = max ( f[b+v[a]] , f[b]+w[a])

v w x
1*v 1*w 1
2*v 2*w 1
4*v 4*w 1
бнбн
2^r*v 2^r*w 1
t*v t*w 1
r=log(x)
log x

nmx
nmlogx

1+2+4+бнбн2^r = 2^(r+1)-1 <= x
t = x - (2^(r+1) - 1) = x - 2^(r+1) + 1


tyvj 1005 1011 1014 1016 1023 1024 1034 1044 1045 1046 1047 1048 1049 1050 1051 1054 1057 1059 1061 1062 1064 1071 1073 1076 1079 1084 1086 1087 1088 1089 1091 1095 1097 1098
