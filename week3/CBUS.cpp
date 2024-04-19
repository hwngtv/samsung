#include <bits/stdc++.h>
using namespace std;
#define N 1000000007
int n,K,load=0,X[51],c[51][51],cmin=99999999,f=0,danhdau[51],res=9999999;
bool check(int v,int k){
    if(danhdau[v])return false;
    if(v<=n){
        if(load>=K)return false;
        if(danhdau[v+n])return false;
    }
    else if(danhdau[v-n]==0)return false;
    return true;

}
void solution(){
    if(f+c[X[2*n]][0]<res)res=f+c[X[2*n]][0];
}
void dequy(int k){
    for(int v=1;v<=2*n;v++){
        if(check(v,k)){
            X[k]=v;
            danhdau[v]=1;
            f+=c[X[k-1]][v];
            if(v<=n)load++;
            else load--;
            if(k==2*n)solution();
            else{
                if(f+cmin*(2*n+1-k)<res)dequy(k+1);
            }
            f-=c[X[k-1]][v];
            danhdau[v]=0;
            if(v<=n)load--;
            else load++;
        }
    }
}
int main()
{   cin>>n>>K;
    danhdau[0]=1;
    X[0]=0;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            cin>>c[i][j];
            if(i!=j&&cmin>c[i][j])cmin=c[i][j];
        }
    }
    dequy(1);
    cout<<res;
    return 0;
}
