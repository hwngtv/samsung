#include <bits/stdc++.h>
using namespace std;
int n,m,a[100];
void Try(int k,int s){
    if(k==n){
        if(s==m){
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }}
    else{int tmp=(m-s);
        for(int i=1;i<=tmp;i++){
            a[k+1]=i;
            Try(k+1,s+i);
        }
    }

}
int main()
{     cin>>n>>m;
    a[0]=1;
    Try(0,0);
    return 0;
}
