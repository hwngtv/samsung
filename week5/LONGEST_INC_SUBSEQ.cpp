//C++ cach 2
#include <bits/stdc++.h>
using namespace std;
#define N 10001
int a[N],n,s[N];
int computeS(int i){
    if(i==1){
        s[i]=1;
    }
    else{
        if(s[i]==0){
            s[i]=1;
            for(int j=1;j<=i-1;j++)if(a[j]<a[i]){
                int tmp=computeS(j);
                if(s[i]<tmp+1)s[i]=tmp+1;
            }
        }
    }
    return s[i];
}
int main()
{ scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)s[i]=0;
    int res=s[1];
    for(int i=1;i<=n;i++){
        int tmp=computeS(i);
        res=max(res,tmp);
    }
    cout<<res;
}
