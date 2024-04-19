
#include <bits/stdc++.h>
using namespace std;
int N=1000000007;
int res=0;
int n,ta[1000007], a[1000007];;

int mergee(int L,int M,int R){
int i=L,j=M+1,cnt=0;
for(int k=L;k<=R;k++){
    if(i>M){ta[k]=a[j];j++;}
    else if(j>R){
        ta[k]=a[i];i++;
    }
    else{
        if(a[i]<=a[j]){ta[k]=a[i];
        i++;
        }
    else{
        ta[k]=a[j];
        j++;
        cnt+=(M-i+1);cnt%=N;
    }
    }}
    for(int k=L;k<=R;k++)a[k]=ta[k];
    return cnt;


}
int mergesort(int L,int R){
    if(L>=R) return 0;
    int M=(L+R)/2;
    int c1=mergesort(L,M);
    int c2=mergesort(M+1,R);
    int c3=mergee(L,M,R);
    return ((c1+c2)%N+c3%N)%N;
}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cin>>n;

for(int i=1;i<=n;i++){
    cin>>a[i];
    }
     int res=mergesort(1,n);
     cout<<res%N;
}
