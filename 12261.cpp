/*
Iterate over all possible turning positions.
Also the change cost for all the cases is same which is x*(min('Z'-str[i]-1, str[i] -  'A') where x is number of non A
Moving cost can be calculated after breaking into cases
if say moving point is i
then we can have 2 cases 
go till i turn back go till the first non A after (let it be j) i which gives 2*i + 1 + j
or 1 + 2*j + 1 + i which is going till j first and then turning back and going till i
Note we have to be careful if there is no non A after the turning point in which case there is no need to go till that point
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

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a-=b;if(a<0)a+=mod;return a;}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    string s;
    int i, j, t;
    cin >> t;
    while(t--){
    	cin >> s;

    	int ans = INT_MAX;

    	int changes = 0;

    	for(i = 0; i < sz(s); ++i)
    		changes = changes + min('Z' - s[i] + 1, s[i] - 'A');


    	for(i = 0; i < sz(s); ++i){
    		//find first non a after i
    		for(j = i + 1; j < sz(s); ++j){
    			if(s[j] != 'A')break;
    		}
    		int where;
    		where = -1;
    		if(j < sz(s))
    			where = j;    		

    		int temp;
    		if(where == -1){
    			temp = i;
    		}
    		else{
	    		temp = 2*i + 1 + (sz(s) - where - 1);
	    	}

	    	// if(i == 1)cout << temp << " " << where << endl;
	    	ans = min(ans, changes + temp);

			if(where != -1){
				temp = 2*(sz(s) - where - 1) + 2 + i;
			}

			ans = min(ans, changes + temp);

    	}

    	cout << ans << endl;

    	// int lstchange = 0;
    	// int frstchange = sz(s) - 1;
    	// for(i = 0; i < sz(s); ++i){
    	// 	if(s[i] != 'A'){
    	// 		lstchange = i;
    	// 		if(i > 0)
    	// 			frstchange = min(frstchange, i);
    	// 	}
    	// }

    	// int ans1 = 0, ans2 = 0;

    	// ans1 = ans1 + min('Z' - s[0] + 1, s[0] - 'A');
    	// ans1 = ans1 + 1;


    	// for(i = sz(s) - 1; i >= frstchange; --i){
    	// 	ans1 = ans1 + min('Z' - s[i] + 1, s[i] - 'A');
    	// 	ans1 = ans1 + 1;
    	// }

		
    	// for(i = 0; i <= lstchange; ++i){
    	// 	ans2 = ans2 + min('Z' - s[i] + 1, s[i] - 'A');
    	// 	ans2 = ans2 + 1;
    	// }

    	// // cout << ans1 << " " << ans2 << endl;
    	// cout << min(ans1 - 1, ans2 - 1) << endl;
    }        

    return 0;
}

