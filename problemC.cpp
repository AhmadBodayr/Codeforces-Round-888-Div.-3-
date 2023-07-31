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
map<ll, ll> freq;
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
		cin >> n >> k;
		freq.clear();
		v.clear(), v.resize(n);
		bool ok = 1;
		for(ll i = 0; i < n; i++) {
			cin >> v[i];			
		}
		ll color = v[n - 1];
		reverse(v.begin(), v.end());
		ll count = 0, index = -1;
		for(ll i = 0; i < n; i++) {
			if(v[i] == color) {
				count++;
				if(count == k) {
					index = i + 1;
					break;
				}
			}
		}
		if(index == -1) ok = 0;
		else if(v[0] != v[n - 1]) {
			ll count = 0;
			for(ll i = index; i < n; i++) {
				if(v[n - 1] == v[i]) {
					count++;
				}
			}
			if(count < k) ok = 0;
		}
		
	
		cout << (ok ? "YES" : "NO") << endl;
		
		
		
	} // end test cases
} // end main