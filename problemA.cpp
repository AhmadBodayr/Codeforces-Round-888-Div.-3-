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
ll t, n, m, k, H;

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
		cin >> n >> m >> k >> H;
		ll out = 0;
		for(ll i = 0; i < n; i++) {
			ll curr; cin >> curr;
			ll diff = abs(curr - H);
			if(diff == 0) continue;
			for(ll i = 1; i < m; i++) {
				if(k * i == diff) out++;
			}
		}
		cout << out << endl;
		
		
		
	} // end test cases
} // end main