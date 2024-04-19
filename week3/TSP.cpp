//C++
#include <bits/stdc++.h>
using namespace std;
#define N 100
int n,res=99999,x[N],c[N][N],cmin=99999,f=0,visited[N]={};
void input(){
    cin>>n;
    x[1]=1;visited[1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][j];
            if(c[i][j]<cmin&&i!=j)cmin=c[i][j];
        }
    }
}
bool check(int v,int k){

    return visited[v]==0;
}
void solution(){
    if(f+c[x[n]][1]<res)res=f+c[x[n]][1];
    }
void Try(int k){
    for(int v=2;v<=n;v++){
        if(check(v,k)){
            x[k]=v;
            visited[v]=1;
            f=f+c[x[k-1]][x[k]];
            if(k==n)solution();
            else{
                if(f+cmin*(n-k+1)<res)Try(k+1);
            }
            visited[v]=0;
            f-=c[x[k-1]][x[k]];
        }
    }
}
int main()
{
    input();
    Try(2);
    cout<<res;
}

