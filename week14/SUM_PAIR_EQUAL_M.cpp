#include <bits/stdc++.h>
using namespace std;
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;cout.tie(0);
    cin>>n>>m;
    int a[100009];
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n+1);
    int i=1,j=n,res=0;
    while(i<j){
        if(a[i]+a[j]==m){
            res++;
            i++;j--;
        }
        else if(a[i]+a[j]>m)j--;
        else i++;
    }
    cout<<res;
    return 0;
}
