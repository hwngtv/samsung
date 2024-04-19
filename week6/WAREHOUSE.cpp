#include <bits/stdc++.h>
using namespace std;
int n,T,D;
int a[1009],t[1009];
int so[1009][101];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>T>>D;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>t[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=T;j++){
            so[i][j]=a[i];
            if(j<t[i]){
                    so[i][j]=0;
                continue;
            }

            if(i>=D){
                for(int ij=i-D;ij<i;ij++){
                    so[i][j]=max(so[i][j],so[ij][j-t[i]]+a[i]);
                }
            }
        }
    }int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=T;j++){
            res=max(res,so[i][j]);
        }
    }
    cout<<res;
    return 0;
}
