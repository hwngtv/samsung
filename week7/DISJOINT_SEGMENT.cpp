
#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> pii;
bool sosanh(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pii.push_back(make_pair(a,b));
    }
    sort(pii.begin(),pii.end(),sosanh);
    int last=-9999;
    int res=0;
    for(int i=0;i<n;i++){
        if(pii[i].first>last){
            last=pii[i].second;
            res++;
        }
    }
    cout<<res;
}
