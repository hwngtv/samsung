
#include <bits/stdc++.h>
using namespace std;
#define N 1009
int n,m;
const int vocuc=99999999;
int d[N][N];
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)d[i][j]=vocuc;
            else d[i][i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=w;
    }
   // cin>>s>>t;
}

int main()
{
    input();
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
            }
        }
    }

    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                    cout<<d[i][j]<<" ";
                    }
            cout<<endl;}
    return 0;
}
