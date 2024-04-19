#include <bits/stdc++.h>
using namespace std;
    int x[10005],y[10005];
    int subsqc[10005][10005];


int main()
{    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){cin>>x[i];subsqc[i][0]=0;}
    for(int i=1;i<=m;i++){cin>>y[i];subsqc[0][i]=0;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]==y[j])subsqc[i][j]=subsqc[i-1][j-1]+1;
            else subsqc[i][j]=max(subsqc[i-1][j],subsqc[i][j-1]);
        }
    }
     cout<<subsqc[n][m];
}
\
