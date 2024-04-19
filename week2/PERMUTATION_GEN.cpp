#include <bits/stdc++.h>
using namespace std;
int n,a[100],b[100];
void dequy(int k){
    if(k==n){
        for(int i=0;i<k;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!b[i]){
                a[k]=i;
                b[i]=1;
                dequy(k+1);
                b[i]=0;
            }
        }
    }
}
int main()
{   cin>>n;
    dequy(0);
    return 0;
}
