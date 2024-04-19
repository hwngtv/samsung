//C++
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> dscanh[10009];
bool danhdau[10009];
int color[10009];
void input() {
    cin >> n >> m;
    int dinh1, dinh2;
    for(int i = 1; i <= m; i++) {
        cin >> dinh1 >> dinh2;
        dscanh[dinh2].push_back(dinh1);
        dscanh[dinh1].push_back(dinh2);
    }
    for(int i = 1; i <= n; i++) {
        sort(dscanh[i].begin(), dscanh[i].end());
    }
}
void dfs(int k) {
    cout<<k<<" ";
    danhdau[k]=true;
    for(int i:dscanh[k])
        if(!danhdau[i]){
                dfs(i);
        }
}


int main()
{
input();
    for(int i=1;i<=n;i++)if(!danhdau[i])dfs(i);


}
