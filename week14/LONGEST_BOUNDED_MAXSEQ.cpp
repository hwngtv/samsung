#include <bits/stdc++.h>
using namespace std;
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;cout.tie(0);
    cin>>n>>m;
    int a[1000009];
    for(int i=1;i<=n;i++){cin>>a[i];

    }int s=0;
    int i=1,res=-1;
    for(int j=1;j<=n;j++){
        s+=a[j];
        while(s>m){
            s-=a[i];
            i++;
        }
        res=max(res,j-i+1);
    }
    cout<<res;
    return 0;
}
