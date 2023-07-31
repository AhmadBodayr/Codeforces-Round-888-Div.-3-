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
vector<ll> a;

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
		a.resize(n);
		for(ll i = 0; i < n; i++) cin >> a[i];
		vector<ll> temp = a;
		sort(temp.begin(), temp.end());
		bool ok = 1;
		for(ll i = 0; i < n; i++) {
			if(a[i] % 2 != temp[i] % 2) {
				ok = 0; break;
			} 
		}
		cout << (ok ? "YES" : "NO") << endl;
	} // end test cases
} // end main