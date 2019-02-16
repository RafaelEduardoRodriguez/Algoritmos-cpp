#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
vector<int> scc;
bool visited[MAXN];
int dfs_num[MAXN];
int dfs_low[MAXN];
int T = 0;
int numSCC = 0;

void tarjanSCC(int node){
	dfs_num[node] = T;
	dfs_low[node] = T;
	T = T + 1;
	visited[node] = true;
	scc.pb(node);
	for(int i=0; i<graph[node].size(); i++){
		int next = graph[node][i];
		if(dfs_num[next] == -1)
			tarjanSCC(next);
		if(visited[next])
			dfs_low[node] = min(dfs_low[node], dfs_low[next]);
	}
	if(dfs_low[node] == dfs_num[node]){
		cout << "Componente " << ++numSCC << ":";
		while(true){
			int temp = scc.back(); scc.pop_back(); visited[temp] = false;
			cout << " " << temp;
			if(node == temp) break;
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int nodes, edges, u, v;
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		cin >> u >> v;
		graph[u].pb(v);
	}
	
	cout << "Las componentes conexas del grafo son:" << endl;
	memset(visited, false, sizeof visited);
	memset(dfs_num, -1, sizeof dfs_num);
	for(int i=0; i<nodes; i++){
		if(dfs_num[i] == -1){
			tarjanSCC(i);
		}
	}
	
	return 0;
}