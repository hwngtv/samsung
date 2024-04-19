//C++
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> dscanh[100009];
bool danhdau[100009];
int color[100009];
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
bool dfs(int k,int cl=1) {
    color[k]=cl;
    for(int i:dscanh[k]){
        if(!color[i]&&!dfs(i,3-color[k]))return 0;
        if(color[i]==cl)return 0;
}
return 1;
}


int main()
{ios_base::sync_with_stdio(0);
    cin.tie(0);
input();
    cout<<dfs(1,1);

}
