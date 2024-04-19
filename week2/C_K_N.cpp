//CPP
#include <bits/stdc++.h>
using namespace std;
int s=0;
const int p=1e9+7;
int m[1000][1000];
int c(int k,int n){
    if(k==0||k==n)m[k][n]=1;
    else{
        if(m[k][n]==0)
        m[k][n]=(c(k-1,n-1)%p+c(k,n-1)%p)%p;
    }
    return m[k][n];
}
int main()
{   int k,n;
    cin>>k>>n;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++)m[i][j]=0;
    }
    cout<<c(k,n);

}
