#include<bits/stdc++.h>
using namespace std;
#define MAX  100005
vector<pair<int, int>> adj[MAX];
int dist[MAX];
pair<int, int> dfs(int node, int parent) {
    pair<int, int> res = {0, node};
    for(auto it : adj[node]) {
        if(it.first != parent) {
            pair<int, int> temp = dfs(it.first, node);
            temp.first += it.second;
            res = max(res, temp);
        }
    }
    dist[node] = res.first;
    return res;
}

int main() {
    int N;
    cin >> N;
    for(int i=1; i<N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int node = dfs(1, -1).second;
    dfs(node, -1);
    int res=0;
    for(int i=1;i<=N;i++)res=max(res,dist[i]);
    cout << res;
    return 0;
}
