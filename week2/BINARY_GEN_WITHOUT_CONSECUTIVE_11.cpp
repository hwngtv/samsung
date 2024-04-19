#include <bits/stdc++.h>
using namespace std;
int n,a[21];
void dequy(int k){
    if(k==n){
        for(int i=0;i<k;i++)cout<<a[i];
        cout<<endl;
    }
    else{
        for(int i=0;i<2;i++){
            if(a[k-1] == 1&&i==1)break;
            a[k]=i;
            dequy(k+1);
        }
    }
}
int main()
{   cin>>n;
    dequy(0);
    return 0;
}
