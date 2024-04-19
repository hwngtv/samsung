//C++
#include <bits/stdc++.h>
#define N 100009
using namespace std;
vector<int> dske[10009];
//vector<int> dskenguoc[10009];
int d[10009];
vector<int> dstopo;
bool danhdau[10009];
int n,m;
vector<int> res(10009,0);
vector<int>in(10009,0) ;
void input(){
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>d[i];
for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        dske[u].push_back(v);

        in[v]++;
}}

void xstp(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        dstopo.push_back(u);
        for(int v:dske[u]){
            in[v]--;
            if(in[v]==0)q.push(v);
        }
    }
}

int main()
{   input();
    xstp();
 /*  for(int i=1;i<=n;i++){cout<<i<<" ";for(int j:dske[i]){

            cout<<j<<" ";
        }cout<<endl;}*/
    for(int i=0;i<n;i++){
        int temp=dstopo[i];
        res[temp]+=d[temp];
     //   cout<<res[temp]<<endl;
        for(int j:dske[temp]){

            res[j]=max(res[j],res[temp]);
        }
    }
    int ress=0;
    for(int i=1;i<=n;i++)ress=max(ress,res[i]);
    cout<<ress;
    return 0;
}
