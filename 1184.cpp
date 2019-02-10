/*input
This is Minimum path cover problem. Can be solved by maximum cardinality bipartite matching.
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

typedef long long int ll;
const ll inf = 1e9;

const int MAXN = 200;
vector<vector<int>>adj;

int match[MAXN], vis[MAXN];

int aug(int node){
	if(node == -1)return 1;
	for(auto it: adj[node]){
		if(vis[it])continue;
		vis[it] = 1;
		if(aug(match[it])){
			match[it] = node;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    int t, n, m;
    cin >> t;
    while(t--){
    	int x, y;
    
    	adj.clear();

    	cin >> n >> m;

    	adj.resize(n);

    	for(int i = 0; i < m; ++i){
    		cin >> x >> y;
    		adj[x].push_back(y);
    	}

    	int MCBM = 0;
    	memset(match, -1, sizeof(match));
    	for(int i = 0; i < n; ++i){
    		memset(vis, 0, sizeof(vis));
    		MCBM += aug(i);
    	}	

    	cout << n - MCBM << endl;

    }        

    return 0;
}

