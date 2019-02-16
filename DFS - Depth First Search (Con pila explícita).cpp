#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

const int MAXN = 100000;
vector<int> graph[MAXN];
bool visited[MAXN];

bool dfs(int s, int e){
	memset(visited, false, sizeof visited);
	stack<int> st;
	st.push(s);
	visited[s] = true;
	while(!st.empty()){
		int node = st.top(); st.pop();
		if(node == e) return true;
		for(int i=0; i<graph[node].size(); i++){
			int next = graph[node][i];
			if(!visited[next]){
				st.push(next);
				visited[next] = true;
			}
		}
	}
	return false;
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
	if(dfs(s, e)) cout << "Existe un camino entre el par de nodos" << endl;
	else cout << "No existe un camino entre el par de nodos" << endl;
	
	return 0;
}