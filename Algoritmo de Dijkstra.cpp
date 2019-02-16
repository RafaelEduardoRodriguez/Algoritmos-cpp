#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;

typedef pair<int, int> edge;
const int MAXN = 100000;
const int INF = 1 << 30;
vector<edge> graph[MAXN];
int dist[MAXN];
int parent[MAXN];
vector<int> path;

void dijkstra(int s){
	//Inicializamos los arreglos de distancia y nodod antecesor
	for(int i=0; i<MAXN; i++){
		dist[i] = INF; parent[i] = -1;
	}
	//heap, en donde almacenamos los costros de los caminos y recuperamos el de menor
	//costo que estará en el tope del heap
	priority_queue <edge, vector<edge>, greater<edge> > pq;
	pq.push(edge(0, s));
	dist[s] = 0;
	while(!pq.empty()){
		int node = pq.top().se;
		int w_node = pq.top().fi;
		pq.pop();
		//No volvemos a visitar nodos con un mayor costo
		if(dist[node] < w_node) continue;
		for(int i=0; i<graph[node].size(); i++){
			int next = graph[node][i].se;
			int w_next = graph[node][i].fi;
			if(w_next + dist[node] < dist[next]){
				dist[next] = w_next + dist[node];
				parent[next] = node;
				pq.push(edge(dist[next], next));
			}
		}
	}
}

void recovery_path(int e){
	path.clear();
	int temp = e;
	while(temp != -1){
		path.pb(temp);
		temp = parent[temp];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int nodes, edges, u, v, w;
	cin >> nodes >> edges;
	//Creando lista de adyacencia
	for(int i=0; i<edges; i++){
		cin >> u >> v >> w;
		graph[u].pb(edge(w, v));
		graph[v].pb(edge(w, u));
	}
	int s, e;
	cout << "Ingrese nodo origen y nodo destino: ";
	cin >> s >> e;
	dijkstra(s);
	cout << "El camino minimo tiene un costo de " << dist[e] << endl;
	cout << "Que corresponde a la ruta:";
	recovery_path(e);
	for(int i=path.size()-1; i>=0; i--)
		cout << " " << path[i];
	cout << endl;
		
	return 0;
}