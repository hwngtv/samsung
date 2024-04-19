#include <bits/stdc++.h>
using namespace std;
#define N 10000
bool visited[N][N];
int ucln(int x,int y){
    if(y==0)return x;
    return  ucln(y,x%y);
    }
    int a,b,c;
struct state{
int x,y;
int step;
    state(int _x,int _y,int _step){
        x=_x;
        y=_y;
        step=_step;
    }

};
vector<state> timlienke(state s){
    vector<state>ns;
    state s1(a,s.y,s.step+1);
    ns.push_back(s1);
    state s2(s.x,b,s.step+1);
    ns.push_back(s2);
    state s3(0,s.y,s.step+1);
    ns.push_back(s3);
    state s4(s.x,0,s.step+1);
    ns.push_back(s4);
    if(s.x+s.y>=b){
        state s5(s.x+s.y-b,b,s.step+1);
        ns.push_back(s5);
    }
    else{
        state s6(0,s.x+s.y,s.step+1);
        ns.push_back(s6);
    }
    if(s.x+s.y>=a){
        state s7(a,s.x+s.y-a,s.step+1);
        ns.push_back(s7);
    }
    else{
        state s8(s.x+s.y,0,s.step+1);
        ns.push_back(s8);
    }
    return ns;
}

int slove(){
    queue<state>q;
    state start(0,0,0);
    q.push(start);
    visited[0][0]=true;
    while(!q.empty()){
        state s=q.front();
        q.pop();
        vector<state> lienke =timlienke(s);
        for(int i=0;i<lienke.size();i++){
        state ns = lienke[i];

        if(ns.x==c||ns.y==c)return ns.step;
        if(!visited[ns.x][ns.y]){
            q.push(ns);
            visited[ns.x][ns.y]=true;
        }
    }}
    return -1;
}
int main(){
    cin>>a>>b>>c;
    cout<<slove();
    return 0;
}
