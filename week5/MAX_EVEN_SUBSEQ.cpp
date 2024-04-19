#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{    cin>>n;
     long long sum=0,ml=9999999,mc=0,res=-999999;
     for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        if(sum&1){
            ml=min(ml,sum);
            res=max(res,sum-ml);
        }
        else{
            mc=min(mc,sum);
            res=max(res,sum-mc);
        }
     }
     cout<<res;
}
