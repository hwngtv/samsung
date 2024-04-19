#include <bits/stdc++.h>
using namespace std;
#define N 1009
long long a[N][N],b[N][N];
int Q,n,m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;cout.tie(0);

    cin>>n>>m;

    for(int i =1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>a[i][j];
        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
}

cin>>Q;
while(Q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        int temp;

            temp=a[r2][c2]+a[r1-1][c1-1]-a[r2][c1-1]-a[r1-1][c2];

cout<<temp<<"\n";}
    return 0;
}
