//C++
#include <bits/stdc++.h>
#define N 100009
using namespace std;
struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    }
};int n,m;
vector<edge> dscanh;
bool cmp(edge a,edge b){
    return a.w<b.w;
}

int cha[N], hang[N];
int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}
bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}
void input(){
cin>>n>>m;
for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dscanh.push_back(edge(u,v,w));}
    sort(dscanh.begin(),dscanh.end(),cmp);
}


int main()
{   input();
for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }
    int mst_weight = 0;


    for (edge &e: dscanh) {
        if (join(e.u, e.v)) {
            mst_weight += e.w;
        }
    }

    cout << mst_weight;
    return 0;
}
