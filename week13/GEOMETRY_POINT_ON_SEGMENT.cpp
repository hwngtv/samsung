#include <bits/stdc++.h>
using namespace std;

int dodai(int xa,int xb,int ya,int yb){
    return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}

int main() {
    int n;
    cin>>n;
    while(n--){
        int xa,ya,xb,yb,xc,yc;
        cin>>xa>>ya>>xb>>yb>>xc>>yc;
       int ab=dodai(xa,xb,ya,yb);
        int ac=dodai(xa,xc,ya,yc);
        int bc=dodai(xb,xc,yb,yc);
        if(ac+ab+2*sqrt(ac*ab)==bc)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
