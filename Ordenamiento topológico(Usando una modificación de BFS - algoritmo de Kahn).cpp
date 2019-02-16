#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

const int MAXN = 100000;
vector<int> graph[MAXN];
int degree[MAXN];
vector<int> topo_sort;

void topological_sort(int n){
	queue<int> q;
	topo_sort.clear();
	for(int i=1; i<=n; i++){
		if(degree[i] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int node = q.front(); q.pop();
		topo_sort.pb(node);
		for(int i=0; i<graph[node].size(); i++){
			int next = graph[node][i];
			degree[next]--;
			if(degree[next] == 0){
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int nodes, edges, u, v;
	cin >> nodes >> edges;
	memset(degree, 0, sizeof degree);
	for(int i=0; i<edges; i++){
		cin >> u >> v;
		graph[u].pb(v);
		degree[v]++;
	}
	cout << "Un ordenamiento topologico del grafo es:";
	topological_sort(nodes);
	for(int i=0; i<topo_sort.size(); i++)
		cout << " " << topo_sort[i];
	cout << endl;
	
	return 0;
}