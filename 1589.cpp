/*
Implementation. Try all places where general can go and then see if any piece captures it. Make sure to capture after red genera's move also
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
const ll mod=1000000007;

ll powmod(ll a,ll b,ll mo=mod){ll res=1;a%=mo; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}

inline ll inv_(ll a) {return powmod(a, mod-2, mod);}
inline ll add(ll a, ll b){a%=mod; b%=mod; a+=b;if(a>=mod)a-=mod;return a;}
inline ll mul(ll a, ll b){a%=mod; b%=mod; return a*1ll*b%mod;}
inline ll sub(ll a, ll b){a%=mod; b%=mod; a-=b;if(a<0)a+=mod;return a;}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

/*USAGE
ordered_set X;
X.insert(1);
X.insert(3);
cout << *X.find_by_order(1) << endl; //3
cout << X.order_of_key(-5) << endl; //0
cout << X.order_of_key(1) << endl; //0
cout << (end(X) == X.order_of_key(100)) << endl; //true since utne elements nahi hai
*/

#if DEBUG && !ONLINE_JUDGE

    #define debug(args...)     (Debugger()) , args

    class Debugger
    {
        public:
        Debugger(const std::string& _separator = ", ") :
        first(true), separator(_separator){}

        template<typename ObjectType>
        Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std::cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std::cerr << endl;}

        private:
        bool first;
        std::string separator;
    };

    template <typename T1, typename T2>
    inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
    {
        return os << "(" << p.first << ", " << p.second << ")";
    }

    template <typename T1, unsigned long int N>
    inline std::ostream& operator << (std::ostream& os, const std::array<T1, N>& a){
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < N; i++)
        {
            if(!first)
                os << ", ";
            os << a[i];
            first = false;
        }
        return os << "]";   
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
    {
        bool first = true;
        os << "[";
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(!first)
                os << ", ";
            os << v[i];
            first = false;
        }
        return os << "]";
    }

    template<typename T>
    inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::set<T>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii;
            first = false;
        }
        return os << "]";
    }

    template<typename T1, typename T2>
    inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
    {
        bool first = true;
        os << "[";
        for (typename std::map<T1, T2>::const_iterator iii = v.begin(); iii != v.end(); ++iii)
        {
            if(!first)
                os << ", ";
            os << *iii ;
            first = false;
        }
        return os << "]";
    }

#else
    #define debug(args...)                  // Just strip off all debug tokens
#endif

bool captured[10];
int X[10], Y[10];
char C[10];
int n;

bool valid(int x, int y){
	if(x <= 0)return false;
	if(x >= 4)return false;
	if(y <= 3)return false;
	if(y >= 7)return false;
	for(int i = 0; i < n; ++i){
		if(X[i] == x && Y[i] == y)
			captured[i] = true;
	}
	return true;
}

bool General(int x, int y, int gx, int gy){
	bool intervene = false;
	int tx = x;
	while(tx >= 1){
		tx--;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == tx && Y[i] == y)
					intervene = true;
			}
		}
	}
	if(!intervene && y == gy)return true;
	return false;
}

bool Chariot(int x, int y, int gx, int gy){
	int tx = x;
	bool intervened = false;
	while(tx > 0){
		if(tx == gx && y == gy)return true;
		tx--;
		for(int i = 0; i < n; ++i){
			if(!captured[i] && X[i] == tx && Y[i] == y)
				intervened = true;
		}
		if(intervened)
			break;
	}
	tx = x;
	intervened = false;
	while(tx <= 10){
		if(tx == gx && y == gy)return true;
		tx++;
		for(int i = 0; i < n; ++i){
			if(!captured[i] && X[i] == tx && Y[i] == y)
				intervened = true;
		}
		if(intervened)
			break;
	}
	int ty = y;
	intervened = false;
	while(ty > 0){
		if(x == gx && ty == gy)return true;
		ty--;
		for(int i = 0; i < n; ++i){
			if(!captured[i] && X[i] == x && Y[i] == ty)
				intervened = true;
		}
		if(intervened)
			break;
	}
	ty = y;
	intervened = false;
	while(ty <= 9){
		if(x == gx && ty == gy)return true;
		ty++;
		for(int i = 0; i < n; ++i){
			if(!captured[i] && X[i] == x && Y[i] == ty)
				intervened = true;
		}
		if(intervened)
			break;
	}
	return false;
}

bool Cannon(int x, int y, int gx, int gy){
	int tx = x;
	int skip = 1;
	while(tx > 0){
		if(tx == gx && y == gy && skip == 0)return true;
		tx--;
		bool flag = false;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == tx && Y[i] == y){
					if(skip == 0){
						flag = true;
						break;
					}
					if(skip == 1){
						skip--;
					}
				}
			}
		}
		if(flag)break;
	}
	tx = x;
	skip = 1;
	while(tx <= 10){
		if(tx == gx && y == gy && skip == 0)return true;
		tx++;
		bool flag = false;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == tx && Y[i] == y){
					if(skip == 0){
						flag = true;
						break;
					}
					if(skip == 1){
						skip--;
					}
				}
			}
		}
		if(flag)break;
	}
	int ty = y;
	skip = 1;
	while(ty > 0){
		if(x == gx && ty == gy && skip == 0)return true;
		ty--;
		bool flag = false;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x && Y[i] == ty){
					if(skip == 0){
						flag = true;
						break;
					}
					if(skip == 1){
						skip--;
					}
				}
			}
		}
		if(flag)break;
	}
	ty = y;
	skip = 1;
	while(ty <= 9){
		if(x == gx && ty == gy && skip == 0)return true;
		ty++;
		bool flag = false;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x && Y[i] == ty){
					if(skip == 0){
						flag = true;
						break;
					}
					if(skip == 1){
						skip--;
					}
				}
			}
		}
		if(flag)break;
	}
	return false;	
}

bool Horse(int x, int y, int gx, int gy){
	if(x - 2 > 0 && y + 1 < 10){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x - 1 && Y[i] == y){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x - 2 && gy == y + 1)return true;
		}
	}
	if(x - 2 > 0 && y - 1 > 0){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x - 1 && Y[i] == y){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x - 2 && gy == y - 1)return true;;
		}
	}
	if(x + 2 > 0 && y + 1 < 10){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x + 1 && Y[i] == y){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x + 2 && gy == y + 1)return true;
		}
	}
	if(x + 2 > 0 && y - 1 > 0){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x + 1 && Y[i] == y){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x + 2 && gy == y - 1)return true;
		}
	}
	if(y - 2 > 0 && x + 1 < 11){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x && Y[i] == y - 1){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x + 1 && gy == y - 2)return true;
		}	
	}
	if(y - 2 > 0 && x - 1 > 0){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x && Y[i] == y - 1){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x - 1 && gy == y - 2)return true;
		}	
	}
	if(y + 2 > 0 && x + 1 < 11){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x && Y[i] == y + 1){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x + 1 && gy == y + 2)return true;
		}	
	}
	if(y + 2 > 0 && x - 1 > 0){
		bool flag = true;
		for(int i = 0; i < n; ++i){
			if(!captured[i]){
				if(X[i] == x && Y[i] == y + 1){
					flag = false;
					break;
				}
			}
		}
		if(flag){
			if(gx == x - 1 && gy == y + 2)return true;
		}	
	}
	return false;
}

int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    while(1){

		int x, y;
		cin >> n >> x >> y;

		if(n == 0 && x == 0 && y == 0)
			return 0;

		for(int i = 0; i < n; ++i){
			cin >> C[i] >> X[i] >> Y[i];
		}            

		bool finalans = false;

		memset(captured, false, sizeof(captured));
		if(valid(x - 1, y)){
			bool ans = false;
			for(int i = 0; i < n; ++i){
				if(!captured[i]){
					if(C[i] == 'G'){
						if(General(X[i], Y[i], x - 1, y))
							ans = true;
					}
					if(C[i] == 'R'){
						if(Chariot(X[i], Y[i], x - 1, y))
							ans = true;
					}
					if(C[i] == 'H'){
						if(Horse(X[i], Y[i], x - 1, y))
							ans = true;
					}
					if(C[i] == 'C'){
						if(Cannon(X[i], Y[i], x - 1, y))
							ans = true;
					}
				}
			}
			if(!ans)finalans = true;
		}
		memset(captured, false, sizeof(captured));
		if(valid(x + 1, y)){
			bool ans = false;
			for(int i = 0; i < n; ++i){
				if(!captured[i]){
					if(C[i] == 'G'){
						if(General(X[i], Y[i], x + 1, y))
							ans = true;
					}
					if(C[i] == 'R'){
						if(Chariot(X[i], Y[i], x + 1, y))
							ans = true;
					}
					if(C[i] == 'H'){
						if(Horse(X[i], Y[i], x + 1, y))
							ans = true;
					}
					if(C[i] == 'C'){
						if(Cannon(X[i], Y[i], x + 1, y))
							ans = true;
					}
				}
			}
			if(!ans)finalans = true;			
		}

		memset(captured, false, sizeof(captured));
		if(valid(x, y - 1)){
			bool ans = false;
			for(int i = 0; i < n; ++i){
				if(!captured[i]){
					if(C[i] == 'G'){
						if(General(X[i], Y[i], x, y - 1))
							ans = true;
					}
					if(C[i] == 'R'){
						if(Chariot(X[i], Y[i], x, y - 1))
							ans = true;
					}
					if(C[i] == 'H'){
						if(Horse(X[i], Y[i], x, y - 1))
							ans = true;
					}
					if(C[i] == 'C'){
						if(Cannon(X[i], Y[i], x, y - 1))
							ans = true;
					}
				}
			}
			if(!ans)finalans = true;			
		}

		memset(captured, false, sizeof(captured));
		if(valid(x, y + 1)){
			bool ans = false;
			for(int i = 0; i < n; ++i){
				if(!captured[i]){
					if(C[i] == 'G'){
						if(General(X[i], Y[i], x, y + 1))
							ans = true;
					}
					if(C[i] == 'R'){
						if(Chariot(X[i], Y[i], x, y + 1))
							ans = true;
					}
					if(C[i] == 'H'){
						if(Horse(X[i], Y[i], x, y + 1))
							ans = true;
					}
					if(C[i] == 'C'){
						if(Cannon(X[i], Y[i], x, y + 1))
							ans = true;
					}
				}
			}
			if(!ans)finalans = true;			
		}

		if(finalans == false)cout << "YES" << endl;
		else cout << "NO" << endl;
	}

    //#if !ONLINE_JUDGE
    //    cout << fixed << setprecision(12) << "-------------------------------------------------\n";
    //    cout << double(clock())/CLOCKS_PER_SEC << " seconds" << endl;
    //#endif
    return 0;
}

