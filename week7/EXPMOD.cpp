#include <bits/stdc++.h>
using namespace std;
int n=1000000007;


unsigned long long chiadetri(unsigned long long x,unsigned long long y){

    if(y==0)return 1;
    unsigned long long t=chiadetri(x,y/2);

    t=(t*t)%n;
    if(y%2==1) t=(t*(x%n))%n;
    return t;
}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);unsigned long long x,y;
    cin>>x>>y;
    unsigned long long res=chiadetri(x,y);
cout<<chiadetri(x,y);
}
