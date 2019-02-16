#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define mk make_pair
#define fi first
#define se second

using namespace std;


/* - usando un struct
struct Edge{
	int start, end, weight;
	Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
	bool operator < (Edge other) const{
		return weight < other.weight;
	}
};
*/
typedef pair<int, int> ii;
const int MAXN = 100005;
int parent[MAXN];
int rango[MAXN];
//vector<Edge> graph;	// Uso solo con el estruct Edge
vector<pair<int, ii> > graph;

int find(int u){
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void unionSet(int u, int v){
	int x = find(u);
	int y = find(v);
	//si pertenecen al mismo conjunto, no los une
	if(rango[x] > rango[y]) parent[y] = x;
	else{
		parent[x] = y;
		if(rango[x] == rango[y]) rango[y]++;
	}
}

int kruskal(int e){
	int cost = 0;

	/*Uso usando el struct Edge
	sort(graph.begin(), graph.end());
	for(int i=0; i<e; i++){
		if(find(graph[i].start) != find(graph[i].end)){
			unionSet(graph[i].start, graph[i].end);
			cost += graph[i].weight;
		}
	}*/

	sort(graph.begin(), graph.end());
	for(int i=0; i<e; i++){
		if(find(graph[i].se.fi) != find(graph[i].se.se)){
			cost += graph[i].fi;
			unionSet(graph[i].se.fi, graph[i].se.se);
		}
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int nodes, edges, u, v, w;
	cin >> nodes >> edges;
	for(int i=0; i<MAXN; i++){
		parent[i] = i;
		rango[i] = 0;
	}
	for(int i=0; i<edges; i++){
		cin >> u >> v >> w;
		//graph.pb(Edge(u, v, w));	//Uso solamente cuando usamos el struct Edge
		graph.pb(mk(w, ii(u, v)));
	}
	int ans = kruskal(edges);
	cout << "El costo del arbol de expasion minima es " << ans << endl;

	return 0;
}
