//Date:2017/8/18
//OJ:codeforces
//Problem:841-B
//Solution:Simulation
//By:xushengyuan
#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > arr;
int n;
inline int read_int()
{
    int result=0;
    char t;
    t=getchar();
    while(!isdigit(t))
        t=getchar();
    while(isdigit(t))
    {
        result=result*10+t-'0';
        t=getchar();
    }
    return result;
}
inline bool is_sum_odd(int odd)
{
    if(odd&1==1)
        return true;
    return false;
}
int main()
{
    /*#ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif*/
    cin >>n;
    int t;
    int count_odd=0,count_even=0;
    for(int i=0;i<n;i++)
    {
        t=read_int();
        arr.push_back(make_pair(t,t&1));
        count_odd+= t&1==1 ?1:0;
        count_even+= t&1==0 ?1:0;
    }
    int odd_all=count_odd,even_all=count_even;
    count_odd=0;
    count_even=0;
    bool flag=false;
    while(!arr.empty())
    {
        count_odd=0;
        count_even=0;
        flag=false;
        for(int l=0;l<arr.size();l++)
        {
            count_odd+=arr[l].second;
            for(int r=arr.size()-1;r>=l;r--)
            {
                count_odd+=arr[r].second;
                if(is_sum_odd(odd_all-count_odd))
                {
                    /*for(int i=0;i<arr.size();i++)
                        cout <<arr[i].first<<' ';
                    cout <<'<'<<endl;
                    for(int i=l;i<=r;i++)
                        cout <<arr[i].first<<' ';
                    cout <<endl;*/
                    arr.erase(arr.begin()+l,arr.begin()+r+1);
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout <<"Second"<<endl;
            return 0;
        }
        if(arr.empty())
        {
            cout <<"First"<<endl;
            return 0;
        }
        count_odd=0;
        count_even=0;
        flag=false;
        for(int l=0;l<arr.size();l++)
        {
            count_odd+=arr[l].second;
            for(int r=arr.size()-1;r>=l;r--)
            {
                count_odd+=arr[r].second;
                if(!is_sum_odd(odd_all-count_odd))
                {
                    /*for(int i=0;i<arr.size();i++)
                        cout <<arr[i].first<<' ';
                    cout <<'<'<<endl;
                    for(int i=l;i<=r;i++)
                        cout <<arr[i].first<<' ';
                    cout <<endl;*/
                    arr.erase(arr.begin()+l,arr.begin()+r+1);
                    flag=true;
                    break;
                }
            }
        }
        if(!flag)
        {
            cout <<"First"<<endl;
            return 0;
        }
        if(arr.empty())
        {
            cout <<"Second"<<endl;
            return 0;
        }
    }
    return 0;
}