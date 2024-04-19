#include <bits/stdc++.h>
using namespace std;
#define N 10001

vector<int> T[N];// T[i] list cac dinh (ben phai, staff) ke voi i
int match[N]; // match[i] la dinh matched voi dinh i (i: ben phai)
int p[N];// p[j] dinh cha cua j (j: ben phai)
int q[N];// q[i] dinh cha cua i (i: ben trai)
int rMatch[N]; // rMatch[j] la dinh matched voi j (j: ben trai)
int n,m;
void input(){
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		int k; scanf("%d",&k);
		for(int j = 1; j <= k; j++){
			int u; scanf("%d",&u);
			T[i].push_back(u);
		}
	}
}
int findPath(int u){
	for(int i = 1; i <= n;i++) q[i] = -1; // not visited
	for(int j = 1; j <= m; j++) p[j] = -1;
	queue<int> Q;
	for(int v: T[u]){
			Q.push(v);p[v] = u;
	}
	while(!Q.empty()){
		int v = Q.front(); Q.pop();
		if(match[v] == -1) return v;
		int mv = match[v];
		for(int x: T[mv]) if(p[x] == -1){
			Q.push(x); p[x] = mv;
		}
	}
	return -1;// not fonud augmenting path
}
void solve(){
	for(int j = 1; j <= m; j++) match[j] = -1;
	for(int i = 1; i <= n; i++) rMatch[i] = -1;
	int res = 0;
	int cnt = 0;
	while(true){
		bool foundPath = false;
		for(int u = 1; u <= n; u++) if(rMatch[u] == -1){
			int v = findPath(u);
			if(v != -1){// found augmenting path
				int x = v;
				while(p[x] != u){
					int px = p[x];
					int nx = rMatch[px];
					match[x] = px;
					rMatch[px] = x;
					x = nx;

				}
				match[x] = p[x];
				rMatch[p[x]] = x;
				res += 1;
				foundPath = true;
				break;
			}
		}
		if(!foundPath) break;
	}
	cout << res;
}
int main(){
	input();
	solve();
	return 0;
}
