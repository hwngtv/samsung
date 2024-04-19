#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> dscanh[N];
int n,m;
int low[N],num[N];
stack<int>scc;
bool instack[N];
int nbscc=0;
int t=0;
void input(){
    cin>>n>>m;
    int d1,d2;
    for(int i=1;i<=m;i++){
        cin>>d1>>d2;
        dscanh[d1].push_back(d2);
        //dscanhnguoc[d2].push_back(d1);
    }
for(int i=1;i<=n;i++){
        sort(dscanh[i].begin(),dscanh[i].end());
     //   sort(dscanhnguoc[i].begin(),dscanhnguoc[i].end());
    }
}
void dfs(int u){
t++;num[u]=t;low[u]=t;scc.push(u);instack[u]=true;
for(int i=0;i<dscanh[u].size();i++){
    int v=dscanh[u][i];
    if(num[v]>0){
        if(instack[v]){
            low[u]=min(low[u],num[v]);
        }
    }
    else {
        dfs(v);
        low[u]=min(low[u],low[v]);
    }
}
if(low[u]==num[u]){
    nbscc++;
    while(!scc.empty()){
        int x=scc.top();scc.pop();
        instack[x]=false;
        if(x==u)break;
    }
}
}
int main()
{
input();
for(int v=1;v<=n;v++){
    if(num[v]==0)dfs(v);
}cout<<nbscc;
return 0;
}
