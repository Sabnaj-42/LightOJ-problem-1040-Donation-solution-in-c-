#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,w;
};
bool comp(node a,node b)
{
    if(a.w<b.w)return true;
    else return false;
}
int parent[100005];
struct node ar[100005];
int findd(int a)
{
    if(parent[a]==a)return a;
    else return parent[a]=findd(parent[a]);
}
void unionn(int a,int b)
{
    parent[a]=b;
}
int main()
{
   int t;cin>>t;
   for(int k=1;k<=t;k++)
   {
       int n;cin>>n;int index=0;
       long long sum=0,res=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=n;j++)
           {
               int c;
               cin>>c;
               if(c!=0)
               {
                   ar[index].a=i;
                   ar[index].b=j;
                   ar[index].w=c;
                   index++;
                   sum+=c;
               }
           }
       }
       for(int i=1;i<=n;i++)parent[i]=i;
       sort(ar,ar+index,comp);
       for(int i=0;i<index;i++)
       {
           int u=findd(ar[i].a);
           int v=findd(ar[i].b);
           if(u!=v)
           {
               res+=ar[i].w;
               unionn(u,v);
           }
       }
       int cnt=0;
       for(int i=1;i<=n;i++)
       {
           if(parent[i]==i)cnt++;
       }
       printf("Case %d: ",k);
       if(cnt>1)cout<<-1<<endl;
       else cout<<sum-res<<endl;
   }
}
