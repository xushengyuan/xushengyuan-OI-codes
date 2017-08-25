#include <bits/stdc++.h>
#define MAXN 30010
using namespace std;
string read()
{
    string result;
    char t;
    t = getchar();
    while(!isalpha(t))
        t = getchar();
    while(isalpha(t))
    {
        result.push_back(t);
        t = getchar();
    }
    return result;
}
int w,n;
struct word
{
    int n;
    string str;
}words[MAXN];
bool cmp(word a,word b)
{
    return a.str<b.str;
}
bool operator <(word &a,const word &b)
{
    return a.str<b.str;
}
bool match(string x,string y){
    if (y.length()>x.length()) return 0;
    return x.substr(0,y.size())==y;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> w >> n;
    for(int i=0;i<w;i++)
    {   
        words[i].n=i+1;
        words[i].str=read();
    }
    sort(words,words+w,cmp);
    /*for(int i=0;i<w;i++)
        cout <<words[i].str<<endl;
    cout <<endl;*/
    int k;
    string s;
    word tmp;
    for(int i=0;i<n;i++)
    {
        cin >>k>>s;
        tmp.str=s;
        word* p=(lower_bound(words,words+w,tmp)+k-1);;
        if(p-words>w || !match(p->str,s))
            cout <<-1<<endl;
        else
            cout<<p->n<<endl;
    }
    //system("pause");
    return 0;
}