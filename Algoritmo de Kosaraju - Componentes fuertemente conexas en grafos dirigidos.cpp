#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

const int MAXN = 1000005;
vector<int> graph[MAXN];
vector<int> traversal[MAXN];
bool visited[MAXN];
stack<int> s;

void dfs1(int v){
	visited[v] = true;
	for(int i=0; i<graph[v].size(); i++){
		int u = graph[v][i];
		if(!visited[u]) dfs1(u);
	}
	s.push(v);
}

void dfs2(int v){
	visited[v] = true;
	//erase
	cout << " " << v;
	for(int i=0; i<traversal[v].size(); i++){
		int u = traversal[v][i];
		if(!visited[u]) dfs2(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int nodes, edges, u, v;
	cin >> nodes >> edges;
	for(int i=0; i<edges; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		traversal[v].push_back(u);
	}
	memset(visited, false, sizeof visited);
	for(int i=0; i<nodes; i++){
		if(!visited[i]) dfs1(i);
	}
	memset(visited, false, sizeof visited);
	int count = 0;
	while(!s.empty()){
		int curr = s.top();
		s.pop();
		if(!visited[curr]){
      //erase
      cout << "Componente " << count + 1 << ":";
      dfs2(curr);
      count++;
      //erase
      cout << endl;
    }
	}
	cout << "hay " << count << " componentes fuertemente conexas" << endl;

	return 0;
}
