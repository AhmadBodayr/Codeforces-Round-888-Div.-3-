#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll; 					
typedef unsigned long long ull; 
typedef long double ld;
#define inf 1000000000000000005
//////////////////Library///////////////////////////////////
struct Trie {
	Trie* child[26];
	bool isLeaf;

	Trie() {
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}

	void insert(char* str) {
		if(*str == '\0') isLeaf = 1;
		else {
			int curr = *str - '0';
			if(child[curr] == 0) child[curr] = new Trie();
			child[curr] -> insert(str + 1);
		}
	} 

	bool wordExist(char* str) {
		if(*str == '\0') return isLeaf;
		int curr = *str - '0';
		if(child[curr] == 0) return false;
		return child[curr] -> wordExist(str + 1); 
	}

	bool prefExist(char* str) {
		if(*str == '\0') return true;
		int curr = *str - '0';
		if(child[curr] == 0) return false;
		return child[curr] -> wordExist(str + 1);
	}
};
/////////////////////////////////End library/////////////////////////////////////
ll t, n, k;
vector<pair<ll, ll>> v;

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
		v.resize(n);
		for(ll i = 0; i < n; i++) {
			ll curr; cin >> curr;
			v[i] = {curr, i + 1};
		}
		sort(v.begin(), v.end());
		ll ans = -1;
		vector<ll> out = {0, 0, 0};
		for(ll i = 0; i < n - 1; i++) {
			ll a = v[i].first, b = v[i + 1].first;
			ll x = 0;
			for(ll j = k - 1; j >= 0; j--) {
				if(((a & (1 << j)) == (b & (1 << j))) && !(a & (1 << j))) {
					x |= (1 << j);
				}
			}
			if(((a ^ x) & (b ^ x)) > ans) {
				out = {v[i].second, v[i + 1].second, x};
				ans = (a ^ x) & (b ^ x);
			}
		}
		cout << out[0] << " " << out[1] << " " << out[2] << endl;
		
		
	} // end test cases
} // end main