//C++
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> dscanh[100009];
bool danhdau[100009];
int color[100009];
void input(){
    cin>>n>>m;
    int d1,d2;
    for(int i=1;i<=m;i++){
        cin>>d1>>d2;
        dscanh[d1].push_back(d2);
        dscanh[d2].push_back(d1);
    }
    for(int i=1;i<=n;i++){
        sort(dscanh[i].begin(),dscanh[i].end());
    }
}

void dfs(int k){
    danhdau[k]=true;
    for(int i:dscanh[k]){
        if(!danhdau[i])dfs(i);
    }
}
int main()
{ios_base::sync_with_stdio(0);
    cin.tie(0);
input();int res=0;
for(int i=1;i<=n;i++){
    if(!danhdau[i]){
        res++;
        dfs(i);
    }
}
cout<<res;
}
