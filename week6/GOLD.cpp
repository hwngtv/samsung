//C++
#include <bits/stdc++.h>
using namespace std;
int n,l1,l2;
int a[1000009]={};
int res[1000009]={};
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l1>>l2;
    priority_queue<int> pq;
    for(int i=1;i<=n;i++)cin>>a[i];
    //int indexM[1000009]={},mx=0;

    deque<int>dq;
int     ans=0;

    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.front()<i-l2)dq.pop_front();
        int j=i-l1;
        if(j>=1){
            while(!dq.empty()&&res[dq.back()]<res[j])dq.pop_back();
            dq.push_back(j);
        }
        res[i]=a[i]+(dq.empty()?0:res[dq.front()]);
        ans=max(ans,res[i]);
    }
      //  pq.push(a[1]);
    //maxx[tmp]=pq.top();
   // pq.push(a[1]);
   // for(int i=l1+1;i<=n;i++){
   //     int t=pq.top();
   //     res[i]=t+a[i];
   //     pq.push(res[i-l1+1]);
    //}
   // int dapso=0;
   // for(int i=n-l2;i<=n;i++)dapso=max(dapso,res[i]);
    cout<<ans;
    return 0;
}
