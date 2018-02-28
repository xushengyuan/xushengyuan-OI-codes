//Date:2018/2/20
//OJ:Codeforces
//Problem:935 B
//Solution:
//By:xushengyuan
#include <bits/stdc++.h>
//#define _DEBUG
using namespace std;
int n;
string str;
int main()
{
    #ifdef _DEBUG
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    cin>>n>>str;
    vector<pair<int,int> >arr;
    arr.push_back({0,0});
    int cot=0;
    for(int i=0;i<2;i++)
    {
        char t=str[i];
        int p=arr.size()-1;
        int px=arr[p].first,py=arr[p].second;
        if(t=='U')
            py++;
        else if(t=='R')
            px++;
        arr.push_back({px,py});
        //for(int j=0;j<arr.size();j++)
        //    cout<<arr[j].first<<' '<<arr[j].second<<endl;
        //cout<<endl;
    }
    for(int i=2;i<n;i++)
    {
        char t=str[i];
        int p=arr.size()-1;
        int px=arr[p].first,py=arr[p].second;
        if(t=='U')
            py++;
        else if(t=='R')
            px++;
        arr.push_back({px,py});
        p++;
        //for(int j=0;j<arr.size();j++)
        //    cout<<arr[j].first<<' '<<arr[j].second<<endl;
        if((arr[p-2].first>arr[p-2].second)&&(arr[p-1].first==arr[p-1].second)&&(arr[p].first<arr[p].second))
            cot++;
        else if((arr[p-2].first<arr[p-2].second)&&(arr[p-1].first==arr[p-1].second)&&(arr[p].first>arr[p].second))
            cot++;
        //cout<<cot<<endl<<endl;;
    }
    cout<<cot;
    return 0;
}