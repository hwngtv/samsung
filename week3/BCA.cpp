//C++
#include <bits/stdc++.h>
using namespace std;
#define N 50
int m,n,load[N]={},res=999;
int s[N],K;
int X[N]={};
vector <int> T[N];
int xungdot[N][N]={};
void input(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int k;cin>>k;
        int temp;
        while(k--){
            cin>>temp;
            T[temp-1].push_back(i);
        }
    }
    cin>>K;
    int a,b;
    while(K--){
        cin>>a>>b;
        xungdot[a-1][b-1]=1;
        xungdot[b-1][a-1]=1;
    }

}
void solution(){
    int tempmax=0;
    for(int i=0;i<m;i++)if(tempmax<load[i])tempmax=load[i];
    if(tempmax<res)res=tempmax;
}
bool check(int v,int k){
    for(int i=0;i<k;i++){
        if(xungdot[i][k]==1)
            if(v==X[i])return false;
    }
    return true;
}
void Try(int k){
    for(int i=0;i<T[k].size();i++){
        int v=T[k][i];
        if(check(v,k)){
            X[k]=v;
            load[v]+=1;
            if(k==n-1)solution();
            else Try(k+1);
            load[v]--;
        }
    }
}
int main()
{
    input();
    Try(0);
    cout<<res;
}
