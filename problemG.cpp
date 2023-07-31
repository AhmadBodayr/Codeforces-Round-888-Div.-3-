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

class DSU {
private:
    vector<int> root;
    vector<int> rank;
public:
    DSU(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

/////////////////////////////////End library/////////////////////////////////////
ll t, n, m, q;
vector<ll> height;
vector<vector<ll>> road;
vector<vector<ll>> queries;
vector<bool> out;

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
		cin >> n >> m;
		height.resize(n);
		road.clear(), road.resize(m);
		DSU* dsu = new DSU(n);
		for(ll i = 0; i < n; i++) cin >> height[i];
		for(ll i = 0; i < m; i++) {
			ll u, v; cin >> u >> v, u--, v--;
			road[i] = {max(height[u], height[v]), u, v};
		}
		sort(road.begin(), road.end());
		cin >> q;
		out.clear(), out.resize(q, 0);
		queries.clear(), queries.resize(q);
		for(ll i = 0; i < q; i++) {
			ll a, b, e; cin >> a >> b >> e, a--, b--;
			queries[i] = {e + height[a], a, b, i};
		}
		sort(queries.begin(), queries.end());
		ll start = 0;
		for(auto query: queries) {
			ll limit = query[0], a = query[1], b = query[2], index = query[3];
			if(dsu -> connected(a, b)) {
				out[index] = 1; continue;
			}
			for(; start < m; start++) {
				if(road[start][0] > limit) break;
				if(!dsu -> connected(road[start][1], road[start][2])) {
					dsu -> unionSet(road[start][1], road[start][2]);
				}
			}
			if(dsu -> connected(a, b)) out[index] = 1;
		}
		for(ll i = 0; i < q; i++) {
			if(out[i]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		cout << endl;

	} // end test cases
} // end main