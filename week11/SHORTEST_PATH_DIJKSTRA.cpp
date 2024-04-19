
#include <bits/stdc++.h>
using namespace std;
#define N 100009
int n,m,s,t;
const int vocuc=99999999;
struct Arc{
    int node;
    int w;
    Arc(int _node,int _w){
        node=_node;
        w=_w;
    }
};
vector<Arc>A[N];
int d[N],p[N];
void input(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        A[u].push_back(Arc(v,w));
    }
    cin>>s>>t;
}
int selectmin(set<int>&F){
    int minD=vocuc,select=-1;
    for(set<int>::iterator p=F.begin();p!=F.end();p++){
        int v=*p;
        if(d[v]<minD){
            minD=d[v];
            select=v;
        }

    }
    return select;
}
int dijkstra(){
    set<int>F;
    for(int i=1;i<=n;i++){
        d[i]=vocuc;
        p[i]=-1;
    }
    d[s]=0;
    for(int i=0;i<A[s].size();i++){
        int v=A[s][i].node;
        d[v]=A[s][i].w;
    }
    for(int i=1;i<=n;i++)if(i!=s)F.insert(i);
    while(F.size()>0){
        int u=selectmin(F);
        F.erase(u);
        if(u==t)return d[t];
        for(int i=0;i<A[u].size();i++){
            int v=A[u][i].node;int w= A[u][i].w;
            if(F.find(v)!=F.end()){
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                   p[v]=u;
                }
            }

                    }
    }
    //while()
}
int dijkstraV2(){
    for(int i=1;i<=n;i++)d[i]=vocuc;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>F;
    F.push(make_pair(0,s));d[s]=0;
    while(!F.empty()){
        pair<int,int> p=F.top();F.pop();
        int u=p.second;
                if(u==t)return d[t];
        for(int i=0;i<A[u].size();i++){
            int v=A[u][i].node;int w=A[u][i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                F.push(make_pair(d[v],v));
            }
        }
    }
}
int main()
{
    input();
    cout<<dijkstraV2();
    return 0;
}
