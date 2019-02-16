#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10001;
vector<int> adjList[MAXN];
bool seen[MAXN];
stack<int> topo_sort;

void dfs(int s) {
  seen[s] = true;
  for(int i = 0; i < (int)adjList[s].size(); i++) {
    int node = adjList[s][i];
    if(!seen[node]) {
      dfs(node);
    }
  }
  topo_sort.push(s);
}

int main() {

  int nodes, edges, u, v;
  cin >> nodes >> edges;
  for(int i = 0; i < edges; i++) {
    cin >> u >> v;
    adjList[u].push_back(v);
  }

  cout << "Ordenamiento topologico:";
  memset(seen, false, sizeof seen);
  for(int i = 0; i < nodes; i++) {
    if(!seen[i]) dfs(i);
  }
  while(!topo_sort.empty()) {
    cout << " " << topo_sort.top();
    topo_sort.pop();
  }
  cout << endl;

  return 0;
}
