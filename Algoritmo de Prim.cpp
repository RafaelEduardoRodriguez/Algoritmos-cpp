#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define fi first
#define se second
#define mk make_pair

using namespace std;

typedef pair<int, int> edge;
const int MAXN = 100000;
vector<edge> graph[MAXN];
bool visited[MAXN];

int prim(){
	int cost = 0;
	memset(visited, false, sizeof visited);
	priority_queue<edge, vector<edge>, greater<edge> > pq;
	pq.push(edge(0, 1));
	while(!pq.empty()){
		int node = pq.top().se;
		int w_node = pq.top().fi;
		pq.pop();
		if(visited[node]) continue;
		visited[node] = true;
		cost += w_node;
		for(int i=0; i<graph[node].size(); i++){
			int next = graph[node][i].se;
			int w_next = graph[node][i].fi;
			if(!visited[next]){
				pq.push(edge(w_next, next));
			}
		}
	}
	return cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int nodes, edges, u, v, w;
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		cin >> u >> v >> w;
		graph[u].pb(edge(w, v));
		graph[v].pb(edge(w, u));
	}
	cout << "El peso del arbol de expasion minima es: " << prim() << endl;
	
	return 0;
}