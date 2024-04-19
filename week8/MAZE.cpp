#include <bits/stdc++.h>
using namespace std;
#define maxN 1000
bool visited[maxN][maxN];
int n,m,r,c;
int matrix[maxN][maxN];
struct state{
    int x,y,step;
    state(int _x,int _y,int _step){
        x=_x;
        y=_y;
        step=_step;
    }
};
vector<state> timlancan(state s){
    vector<state> ns ;
    if(!matrix[s.x+1][s.y]){
        state s1(s.x+1,s.y,s.step+1);
        ns.push_back(s1);
    }
    if(!matrix[s.x-1][s.y]){
        state s2(s.x-1,s.y,s.step+1);
        ns.push_back(s2);
    }
    if(!matrix[s.x][s.y+1]){
        state s3(s.x,s.y+1,s.step+1);
        ns.push_back(s3);
    }
    if(!matrix[s.x][s.y-1]){
        state s4(s.x,s.y-1,s.step+1);
        ns.push_back(s4);
    }
    return ns;
}
int slove(){
    queue<state> q;
    state xuatphat(r,c,0);
    q.push(xuatphat);
    visited[r][c]=true;
    while(!q.empty()){
        state s=q.front();
        q.pop();
        vector<state> lancan=timlancan(s);
        for(int i=0;i<lancan.size();i++){
            state ns=lancan[i];
            if(ns.x==1||ns.y==1||ns.x==n||ns.y==m)return ns.step+1;
            if(!visited[ns.x][ns.y]){
                q.push(ns);
                visited[ns.x][ns.y]=true;
            }
        }
    }return -1;
}
int main(){
    cin>>n>>m>>r>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cin>>matrix[i][j];
    }
    cout<<slove();
    return 0;
}
