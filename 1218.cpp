/*DFS can be used. 
  Figure out cases where the node "HAS" to be colored black.
  Else we can color with any and find minimum.  
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define forr(i,n) for(i=n-1;i>=0;--i)
#define rep(i,a,b) for(i=a;i<=b;++i)
#define per(i,a,b) for(i=b;i>=a;--i)

#define ffs(a) __builtin_ffs(a) // find first set
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits
#define popcll(a) __builtin_popcountll(a) //count set bits for long long int

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define yolo "debug_statement"

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const ll inf = 1e9;
const ld eps = 1e-9;
const ld pi=acos(-1);
const ll mod=1000000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}


const int nax = 1e5 + 5;
vi adj[nax];

bool isleaf(int node, int par){
	return (sz(adj[node]) == 1 && adj[node][0] == par);
}

int dfs(int node, int par, int color, bool mustrepair){
	int ans = 100000000;
	if(mustrepair){
		ans = 1;
		for(auto it: adj[node]){
			if(it != par){
				ans = ans + dfs(it, node, 1, 0);
			}
		}
	}
	else{
		
		if(isleaf(node, par)){
			if(color == 0)
				return 1;
			else
				return 0;
		}

		if(color == 0){
			int sum1 = 1;
			for(auto it: adj[node]){
				if(it != par){
					sum1 = sum1 + dfs(it, node, 1, 0);
				}
			}
			int sum2 = 0;
			for(auto it: adj[node]){
				if(it != par){
					sum2 = sum2 + dfs(it, node, 0, 1);
				}
			}
			ans = min(sum1, sum2);
		}	
		else{
			int sum1 = 1;
			for(auto it: adj[node]){
				if(it != par){
					sum1 = sum1 + dfs(it, node, 1, 0);
				}
			}
			int sum2 = 0;
			for(auto it: adj[node]){
				if(it != par){
					sum2 = sum2 + dfs(it, node, 0, 0);
				}
			}
			ans = min(sum1, sum2);
		}
		if(ans == 100000000){
			if(color == 0)
				ans = 1;
			else
				ans = 0; //leaf hai
		}
	}
	return ans;
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif
	            
    int n = 0, u, v, wtf;
    while(1){
    	for(int i = 0; i <= n; ++i)adj[i].clear();
    	cin >> n;
    	if(n == 1){
    		cout << 1 << endl;
    	}
    	else{
	    	for(int i = 0; i < n - 1; ++i){
	    		cin >> u >> v;
	    		adj[u].pb(v);
	    		adj[v].pb(u);
	    	}
	    	int ans = 0;
	    	ans = dfs(1, 0, 0, 0);
	    	cout << ans << endl;
	    }
    	cin >> wtf;
    	if(wtf == -1)
    		break;
    }
    //#if !ONLINE_JUDGE
    //    cout << fixed << setprecision(12) << "-------------------------------------------------\n";
    //    cout << double(clock())/CLOCKS_PER_SEC << " seconds" << endl;
    //#endif
    return 0;
}
