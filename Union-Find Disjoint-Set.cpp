#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

const int MAXN = 100005;
int parent[MAXN];
int rango[MAXN];

int find(int u){
	if(parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}

void unionSet(int u, int v){
	int x = find(u);
	int y = find(v);
	if(rango[x] > rango[y]) parent[y] = x;
	else{
		parent[x] = y;
		if(rango[x] == rango[y]) rango[y]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	char limit;
	string edge;
	cin >> t;
	while(t--){
		//initialization
		for(int i=0; i<MAXN; i++){
			parent[i] = i;
			rango[i] = 0;
		}
		cin >> limit;
		cin.ignore();
		while(true){
			getline(cin, edge);
			if(edge == "") break;
			unionSet((int)(edge[0]-'A'),(int)(edge[1]-'A'));
		}
		int count = 0;
		for(int i=0; i<=(int)(limit-'A'); i++){
			if(parent[i] == i) count++;
		}
		cout << count << endl;
		if(t) cout << endl;
	}
	
	return 0;
}