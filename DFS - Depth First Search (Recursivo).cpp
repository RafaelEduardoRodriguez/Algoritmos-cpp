#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

const int MAXN = 100000;
vector<int> graph[MAXN];
bool visited[MAXN];
bool ans = false;

void dfs(int s, int e){
	visited[s] = true;
	if(s == e) ans = true;
	for(int i=0; i<graph[s].size(); i++){
		int node = graph[s][i];
		if(!visited[node]){
			dfs(node, e);
		}
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
		graph[v].pb(u);
	}
	int s, e;
	cout << "Ingrese nodo origen y nodo destino: " << endl;
	cin >> s >> e;
	memset(visited, false, sizeof visited);
	dfs(s, e);
	if(ans) cout << "Existe un camino entre los nodos" << endl;
	else cout << "No existe un camino entre los nodos" << endl;
	
	return 0;
}