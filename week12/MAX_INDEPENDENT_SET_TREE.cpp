#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n;
vector<int> A[N];
vector<int>C[N];
int w[N],p[N],F1[N],F0[N],F[N];
bool visited[N];
int root,d[N],ans;
void input(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void dfs(int u){
    visited[u]=true;
    for(int i=0;i<A[u].size();i++){
        int v=A[u][i];
        if(!visited[v]){
            p[v]=u;
            d[u]+=1;
            C[u].push_back(v);
            dfs(v);
        }
    }
}
void solve(){
    queue<int>Q;
    for(int v=1;v<=n;v++){
        F1[v]=0,F0[v]=0;
        if(d[v]==0){
            F0[v]=0;
            F1[v]=w[v];
            Q.push(v);
        }else{
            F1[v]=w[v];
        }
    }
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        F[v]=max(F0[v],F1[v]);
        int pv=p[v];
        F0[pv]+=F[v];
        F1[pv]+=F0[v];
        d[pv]-=1;
        if(d[pv]==0)Q.push(pv);
    }
    ans=F[root];
}
void init(){
    root=2;
    for(int v=1;v<=n;v++){
        visited[v]=false;
        p[v]=-1;
        d[v]=0;
    }
    dfs(root);
}
int main() {
    input();
    init();
    solve();
    cout<<ans;
    return 0;
}
