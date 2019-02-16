#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef pair<int, int> bridge;
const int MAXN = 100005;
vector<int> graph[MAXN];
int visited[MAXN];
int dfs_low[MAXN];//El menor nodo alcanzable desde el actual
int parents[MAXN];
bool articulationPoints[MAXN];
vector<bridge> bridges;
int T = 0; // time
int root; //raiz del DFS spanning tree
int rootChildren;

//DFS para detectar los puentes y puntos de articulacion
void dfs(int node){
	//P parent
	visited[node] = dfs_low[node] = T;
	T++;
	for(int i=0; i<graph[node].size(); i++){
		int next = graph[node][i];
		if(visited[next] == -1){
      parents[next] = node;
			if(root == node) rootChildren++;
			dfs(next);
			if(visited[node] <= dfs_low[next]){
				articulationPoints[node] = true;
			}
			if(dfs_low[next] > visited[node]){
				bridges.pb(bridge(node, next));
			}
			dfs_low[node] = min(dfs_low[node], dfs_low[next]);
		}
		else if (parents[node] != next) dfs_low[node] = min(dfs_low[node], visited[next]);
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
	memset(visited, -1, sizeof visited);
	memset(articulationPoints, false, sizeof articulationPoints);
	memset(parents, -1, sizeof parents);
	//corremos un DFS suponiendo que el grafo es conexo
	//en caso contrario, correr el DFS desde cada componente del grafo usando un for
	for (int i = 0; i < nodes; i++) {
    if (visited[i] == -1) {
      root = i; rootChildren = 0;
      dfs(i);
      articulationPoints[i] = (rootChildren > 1);
    }
	}
	for(int i=0; i<bridges.size(); i++){
		cout << "Puente entre los nodos " << bridges[i].fi << " y " << bridges[i].se << endl;
	}
	cout << "\nEl grafo tiene los siguientes nodos como puntos de articulacion:" << endl;
	for(int i=0; i<nodes; i++){
		if(articulationPoints[i]) cout << i << " ";
	}
	cout << endl;

	return 0;
}
