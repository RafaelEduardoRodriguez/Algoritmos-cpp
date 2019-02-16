#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef pair<int, int> edge;
const int MAXN = 10000;
const int INF = 1e9;
vector<edge> graph[MAXN];
int dist[MAXN][MAXN];

/* Test Cases
4 4
1 2 1
2 3 1
3 2 -5
3 4 2
1 4 2

4 4
1 2 3
1 4 100
2 3 4
3 4 -2
1 4 1
*/

bool bellman_ford(int s, int ver){
	for(int i = 0; i <= ver; i++) dist[0][i] = INF;
	dist[0][s] = 0;
	for(int i = 1; i < ver; i++) {
    for(int u = 0; u <= ver; u++) dist[i][u] = dist[i-1][u];
    for(int node = 0; node <= ver; node++) {
      for(int k = 0; k < graph[node].size(); k++) {
        int curr = graph[node][k].first;
        int w_curr = graph[node][k].second;
        dist[i][curr] = min(dist[i][curr], dist[i-1][node] + w_curr);
      }
    }
	}
	for(int node = 0; node <= ver; node++) {
    for(int k = 0; k < graph[node].size(); k++){
      int curr = graph[node][k].first;
      int w_curr = graph[node][k].second;
      if(dist[ver][curr] > dist[ver-1][node] + w_curr) return true;
    }
	}
	return false;
}

void printing(int n) {
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      cout.width(11);
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int nodes, edges, u, v, w;
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		cin >> u >> v >> w;
		graph[u].pb(edge(v, w));
	}
	int s, e, cant;
	cin >> s >> e >> cant;
	if(!bellman_ford(s, nodes)){
		cout << "El costo del camino minimo entre " << s << " y " << e << endl;
		cout <<"Con exactamente " << cant << " aristas es: " << dist[cant][e] << endl;
	}
	else cout << "Existe un ciclo de peso negativo en el grafo" << endl;
	printing(nodes);

	return 0;
}
