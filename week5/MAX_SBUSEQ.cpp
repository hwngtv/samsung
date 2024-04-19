#include <bits/stdc++.h>
using namespace std;
int n,a[1000009],b[1000009];

int main()
{    cin>>n;
     for(int i=1;i<=n;i++){
        cin>>a[i];
        if(b[i-1]>0)b[i]=b[i-1]+a[i];
        else {
            b[i]=max(a[i],a[i]+b[i]);
        }
     }int res=-9999;
     for(int i=1;i<=n;i++)res=max(res,b[i]);
     cout<<res;
}
