#include <bits/stdc++.h>
using namespace std;
int n,T,D,k1,k2;
int a[1009],t[1009];
int so[1009];
int s[1009];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cin>>n>>k1>>k2;
    s[0]=1,so[0]=1,so[1]=1;
    for(int i=1;i<=n;i++){
        so[i]=s[i-1];
        for(int j=i-k2;j<=i-k1;j++)
        if(j>=0)s[i]+=so[j];
    }
    cout<<(s[n]+so[n])%1000000007;
    return 0;
}
