#include <bits/stdc++.h>
using namespace std;
#define N 100009
long long a[N];
int Q,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0) ;cout.tie(0);
    cin>>n;

    for(int i =1;i<=n;i++){
    cin>>a[i];

    a[i]+=a[i-1];
}

cin>>Q;
while(Q--){
        int q1,q2;
    cin>>q1>>q2;
    long long tmp=a[q2]-a[q1-1];
cout<<tmp<<endl;
}
    return 0;
}
