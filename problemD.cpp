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
ll t, n;
vector<bool> visited;
vector<ll> v;

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
		cin >> n;
		bool ok = 0;
		vector<ll> temp;
		visited.clear(), visited.resize(n + 1, 0);
		v.resize(n - 1);
		ll count = 0;
		for(ll i = 0; i < n - 1; i++) {
			cin >> v[i];
			if(i == 0) {
				if(v[i] > n) temp.push_back(v[i]);
				else visited[v[i]] = 1, count++;
			} else {
				if(v[i] - v[i - 1] > n || visited[v[i] - v[i - 1]]) 
					temp.push_back(v[i] - v[i - 1]);
				else visited[v[i] - v[i - 1]] = 1, count++;
			}
		}
		if(count == n - 1) ok = 1;
		else if(count == n - 2 && temp.size() == 1) {
			ll a = -1, b = -1;
			for(ll i = 1; i <= n; i++) {
				if(!visited[i]) {
					if(a == -1) a = i;
					else {
						b = i; break;
					}
				}
			}
			if(a + b == temp[0]) ok = 1;
		}
		
		cout << (ok ? "YES" : "NO") << endl;

		
	} // end test cases
} // end main