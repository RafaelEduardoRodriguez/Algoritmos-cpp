#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back

using namespace std;

typedef long long ll;
const int MAXN = 10000000;
bitset<MAXN> sieve;
vector<ll> primes;

void create_sieve(){
	sieve.set();
	sieve[0] = sieve[1] = 0;
	for(ll i = 2; i<MAXN; i++){
		if(sieve[i]){
			primes.pb(i);
			for(ll j = i*i; j<MAXN; j += i){
				sieve[j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	create_sieve();
	while(true){
		cin >> n;
		if(n < 0) break;
		if(sieve[n]) cout << n << " es un numero primo" << endl;
		else cout << n << " no es un numero primo" << endl;
	}

	return 0;
}
