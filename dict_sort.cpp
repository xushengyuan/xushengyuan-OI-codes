#include <bits/stdc++.h>
#define N 56074
using namespace std;
struct word
{
    string zh_word;
    string py;
};
vector<word> a;
bool cmp(word x,word y)
{
    return x.zh_word<y.zh_word;
}
int main()
{
    int t;
    word tmp;
    ifstream in("py.txt");
    for(int i=0;i<N;i++)
    {
        in >>tmp.zh_word>>tmp.py>>t;
        //cout <<tmp.zh_word<<endl;
        a.push_back(tmp);
    }
    ifstream in1("py1.txt");
    for(int i=0;i<25417;i++)
    {
        in1 >>tmp.zh_word>>tmp.py;
        //cout <<tmp.zh_word<<endl;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end(),cmp);
    ofstream out("py2.txt");
    for(int i=0;i<N+25417;i++)
    {
        out <<a[i].zh_word<<' '<<a[i].py<<endl;
    }
    return 0;
}