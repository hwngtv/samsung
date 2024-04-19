#include <bits/stdc++.h>
using namespace std;
int n;
bool danhdau[100009];
vector<pair<int,int>> pii;
bool sosanh(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
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
    int res=0;

    for(int i=0;i<n;i++){
        for(int j=pii[i].first;j>0;j--){
            if(danhdau[j])continue;
            danhdau[j]=true;
            res+=pii[i].second;
            j=0;
        }
    }
    cout<<res;
}
