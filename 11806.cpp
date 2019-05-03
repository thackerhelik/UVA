/*
dp parameters are row, column, remaining cheerleaders and mask (4 bit value to show the covering of sides)
Also read mod values in every question, not everything is 1e9 + 7
*/

/*
When you walk through a storm
Hold your head up high
And don't be afraid of the dark
At the end of the storm
There's a golden sky
And the sweet silver song
of the lark
Walk on, through the wind
Walk on, through the rain
Though your dreams be tossed
and blown
Walk on, walk on
With hope in your heart
And you'll never walk alone
YNWA
*/

//hell_hacker
//IT TAKES EVERYTHING and IT IS NOT LUCK
//PICK ME LAST -- COME OUT OF N^WHERE
//WHY NOT?

/*
And you came my way on a winner's day
Shouted loudly come out and play
Can't you tell I got news for you
Sun is shining and so are you
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
const ll mod=1000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a%=mod; b%=mod; a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){a%=mod; b%=mod; return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a%=mod; b%=mod; a-=b;if(a<0)a+=mod;return a;}

int row, column, k;
ll dp[21][21][401][16];

ll solve(int r, int c, int rem, int mask){
	if(rem < 0)return 0;
	if(rem == 0)return (mask == 15);
	if(r >= row)return 0;
	if(dp[r][c][rem][mask] != -1)return dp[r][c][rem][mask];

	ll ans = 0;

	int newmask = mask;

	if(r == 0)newmask |= (1 << 3);
	if(r == row - 1)newmask |= (1 << 1);
	if(c == 0)newmask |= (1 << 0);
	if(c == column - 1)newmask |= (1 << 2);

	if(c == column - 1)
		ans = ans + solve(r + 1, 0, rem - 1, newmask) + solve(r + 1, 0, rem, mask);
	else
		ans = ans + solve(r, c + 1, rem - 1, newmask) + solve(r, c + 1, rem, mask);

	return dp[r][c][rem][mask] = ans % mod;
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    int t, ctr = 1;
    cin >> t;
    while(t--){
    	cout << "Case " << ctr++ << ": ";
    	memset(dp, -1, sizeof(dp));
    	cin >> row >> column >> k;
    	if(k > row*column){
    		cout << 0 << endl;
    		continue;
    	}
    	ll ans = solve(0, 0, k, 0);
    	cout << ans << endl;
    }        

    //#if !ONLINE_JUDGE
    //    cout << fixed << setprecision(12) << "-------------------------------------------------\n";
    //    cout << double(clock())/CLOCKS_PER_SEC << " seconds" << endl;
    //#endif
    return 0;
}

