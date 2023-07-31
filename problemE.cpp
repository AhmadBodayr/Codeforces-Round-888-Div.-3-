#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll; 					
typedef unsigned long long ull; 
typedef long double ld;
#define inf 1000000000000000005
///////////////////////////////
ll t, n, k;
vector<ll> cost;
vector<ll> topSort;
vector<vector<ll>> obtain;
vector<bool> visited;

void dfs(ll node) {
	visited[node] = 1;
	for(auto child: obtain[node]) {
		if(!visited[child]) dfs(child);
	}
	topSort.push_back(node);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 	

	// #ifndef ONLINE_JUDGDE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);	
	// #endif
	///////////////////////////////////////////////////////////////
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cost.resize(n);
		topSort.clear();
		visited.clear(), visited.resize(n, 0);
		obtain.clear(), obtain.resize(n);
		for(ll i = 0; i < n ; i++) cin >> cost[i];
		for(ll i = 0; i < k ; i++) {
			ll curr; cin >> curr; curr--;
			cost[curr] = 0;
		}
		for(ll i = 0; i < n; i++) {
			ll m; cin >> m;
			for(ll j = 0; j < m; j++) {
				ll curr; cin >> curr, curr--;
				obtain[i].push_back(curr);
			}
		}
		for(ll i = 0; i < n; i++) {
			if(!visited[i]) dfs(i);
		}
		for(ll i = 0; i < n; i++) {
			ll potion = topSort[i];
			if(obtain[potion].size() == 0) continue;
			ll acc = 0;
			for(auto child: obtain[potion]) acc += cost[child];
			cost[potion] = min(cost[potion], acc);
		}
		for(ll i = 0; i < n; i++) cout << cost[i] << " ";
		cout << endl;
		

	} // end test cases
} // end main