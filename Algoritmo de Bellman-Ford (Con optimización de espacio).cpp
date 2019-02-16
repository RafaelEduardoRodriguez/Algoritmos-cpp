#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> edge;
const int MAXN = 100000;
const int INF = 1 << 30;
vector<edge> graph[MAXN];
int dist[MAXN];

bool bellman_ford(int ver, int s){
	for(int i=0; i<MAXN; i++) dist[i] = INF;
	dist[s] = 0;
	for(int i=1; i<=ver-1; i++){
		for(int j=0; j<ver; j++){
			for(int k=0; k<graph[j].size(); k++){
				int node = graph[j][k].se;
				int w_node = graph[j][k].fi;
				if(dist[j] + w_node < dist[node]){
					dist[node] = dist[j] + w_node;
				}
			}
		}
	}
	for(int j=0; j<ver; j++){
		for(int k=0; k<graph[j].size(); k++){
			int node = graph[j][k].se;
			int w_node = graph[j][k].fi;
			if(w_node + dist[j] < dist[node])
				return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int nodes, edges, u, v, w;
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		cin >> u >> v >> w;
		graph[u].pb(edge(w, v));
		graph[v].pb(edge(w, v));
	}
	int s, e;
	cout << "Ingrese nodo fuente y nodo destino: " << endl;;
	cin >> s >> e;
	bool ans = bellman_ford(nodes, s);
	if(!ans) cout << "El costo del camino minimo entre " << s << " y " << e << " es: " << dist[e] << endl;
	else cout << "Existe un ciclo en el grafo" << endl;
	
	return 0;
}