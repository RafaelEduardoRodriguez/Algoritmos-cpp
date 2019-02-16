#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> list;
	int n, k;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> k;
		list.pb(k);
	}
	
	//LIS (Longest Increasing Subsequence)
	int maxSeq[n];
	int seq[n];
	int greater;
	for(int i=0; i<n; i++) seq[i] = -1;
	for(int i=0; i<n; i++) maxSeq[i] = 1;
	int max = 1;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(list[j] < list[i]){
				maxSeq[i] = maxSeq[j] + 1;
				seq[i] = j;
				if(max < maxSeq[i]){
					max = maxSeq[i];
					greater = i;
				}
			}
		}
	}
	
	cout << max << " " << greater << endl;
	
	cout << "tamanio maximo es -> " << max << endl;
	cout << "correspondiente a la secuencia: ";
	int temp = greater;
	vector<int> final_seq;
	for(int i=0; i<max; i++){
		final_seq.push_back(list[temp]);
		temp = seq[temp];
	}
	for(int i=final_seq.size()-1; i>=0; i--) cout << final_seq[i] << " ";
	cout << endl;
	
	return 0;
}