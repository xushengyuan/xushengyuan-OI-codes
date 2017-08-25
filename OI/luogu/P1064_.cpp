#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int f[32000],v[60],w[60],q[60];
int n,m;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k;
    int tempA1,tempA2,tempB1,tempB2;
    cin>>n>>m;
    for(i=0;i<m;i++)
        cin>>w[i]>>v[i]>>q[i];
    for(i=0;i<m;i++)
    {
        tempA1=0;
        tempA2=0;
        tempB1=0;
        tempB2=0;
        if(q[i]==0)
        {
            k=i+1;
            while(k<m && q[k]!=i)
                k++;
            tempB1=k;
            tempA1=1;
            k=tempB1+1;
            while(k<m && q[k]!=i)
                k++;
            tempB2=k;
            tempA2=1;
            for(j=n;j>=w[i];j--)  
            {         
                f[j]=max(f[j-w[i]]+w[i]*v[i],f[j]);    //不选附件

                if((j-w[i]-w[tempB1])>=0
                    &&tempA1==1)                           
                    f[j]=max(f[j-w[i]-w[tempB1]]
                    +w[i]*v[i]+w[tempB1]*v[tempB1],f[j]); //选第一件附件

                if((j-w[i]-w[tempB2])>=0
                    &&tempA2==1)                                             
                    f[j]=max(f[j-w[i]-w[tempB2]]
                    +w[i]*v[i]+w[tempB2]*v[tempB2],f[j]);  //选第二件附件

                if((j-w[i]-w[tempB1]-w[tempB2])>=0
                    &&tempA1==1
                    &&tempA2==1)                                             
                    f[j]=max(f[j-w[i]-w[tempB1]-w[tempB2]]  
                    +w[i]*v[i]+w[tempB1]*v[tempB1]
                    +w[tempB2]*v[tempB2],f[j]);           //选两件附件
            }
        }
    }
    cout<<f[n];
    return 0;
}
