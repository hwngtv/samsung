 #include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long a,b,a1,a2,b1,b2,c,c1;
    cin>>a>>b;
    a2=a%10;
    b2=b%10;
    a1=a/10;
    b1=b/10;
    c=a1+b1;
    c1=a2+b2;
    if(c==0)cout<<c1;
    else{
        if(c1>9){
            c+=c1/10;
            c1%=10;
        }
        cout<<c<<c1;
    }
    return 0;
}
