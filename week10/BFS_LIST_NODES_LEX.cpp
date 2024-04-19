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
void bfs(int k) {
    queue <int>que;
    que.push(k);
    danhdau[k]=true;
    while(!que.empty()){
        int dinh=que.front();
        que.pop();
        cout<<dinh<<" ";
        for(int u:dscanh[dinh]){
            if(!danhdau[u]){
                que.push(u);
                danhdau[u]=true;
            }
        }

    }
}


int main()
{
input();
    for(int i=1;i<=n;i++)if(!danhdau[i])bfs(i);


}
