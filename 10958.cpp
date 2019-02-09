/*
m/x + n/y = 1/p
multiply both sides by p*x*y
mpy + npx = xy
let a = mp, b = np
ay + bx = xy
ay + bx + ab = xy + ab //adding ab to both sides
xy - ay - bx + ab = xy
y(x - a)- b(x - a) = xy
(x - a)*(y - b) = xy
Let div1 and div2 be divisors of xy such that div1*div2 = xy
then x - a = div1 and y - b = div2
x - a = div2 and y - b = div1
handle cases where div1 and div2 can be negative
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sz(x) (int)(x).size()

typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    
    int ctr = 1;

    while(1){
    	ll i, m, n, p;
    	cin >> m >> n >> p;
    	if(m == 0 && n == 0 && p == 0)break;
    	ll c = p*p*m*n, div1, div2;
    	c = abs(c);
    	set<pair<ll,ll>>s;
    	ll sqrtc = (ll)sqrt(c);

    	if(n > 0 && m > 0){
			//(x - a)(y - b) = ab
			for(i = 1; i <= sqrtc; ++i){
	    		if(c % i == 0){
	    			div1 = i;
	    			div2 = c / i;
	    			if(p*m + div1 != 0 && p*n + div2 != 0)s.insert({p*m + div1, p*n + div2});
	    			if(p*m - div1 != 0 && p*n - div2 != 0)s.insert({p*m - div1, p*n - div2});
	    			if(p*m + div2 != 0 && p*n + div1 != 0)s.insert({p*m + div2, p*n + div1});
	    			if(p*m - div2 != 0 && p*n - div1 != 0)s.insert({p*m - div2, p*n - div1});
	    		}
	    	}
	    }
	    else if(n > 0 && m < 0){
	    	for(i = 1; i <= sqrtc; ++i){
	    		if(c % i == 0){
	    			div1 = i;
	    			div2 = c / i;
	    			if(-p*m + div1 != 0 && p*n + div2 != 0)s.insert({-p*m + div1, p*n + div2});
	    			if(-p*m - div1 != 0 && p*n - div2 != 0)s.insert({-p*m - div1, p*n - div2});
	    			if(-p*m + div2 != 0 && p*n + div1 != 0)s.insert({-p*m + div2, p*n + div1});
	    			if(-p*m - div2 != 0 && p*n - div1 != 0)s.insert({-p*m - div2, p*n - div1});
	    		}
	    	}	
	    }
	    else if(n < 0 && m > 0){
	    	//(x - a)(y - b) = -ab
	    	for(i = 1; i <= sqrtc; ++i){
	    		if(c % i == 0){
	    			div1 = i;
	    			div2 = c / i;
	    			if(p*m + div1 != 0 && -p*n + div2 != 0)s.insert({p*m + div1, -p*n + div2});
	    			if(p*m - div1 != 0 && -p*n - div2 != 0)s.insert({p*m - div1, -p*n - div2});
	    			if(p*m + div2 != 0 && -p*n + div1 != 0)s.insert({p*m + div2, -p*n + div1});
	    			if(p*m - div2 != 0 && -p*n - div1 != 0)s.insert({p*m - div2, -p*n - div1});
	    		}
	    	}
	    }
	    else{
	    	//(x + a)(y + b) = ab
	    	for(i = 1; i <= sqrtc; ++i){
	    		if(c % i == 0){
	    			div1 = i;
	    			div2 = c / i;
	    			if(-p*m + div1 != 0 && -p*n + div2 != 0)s.insert({-p*m + div1, -p*n + div2});
	    			if(-p*m - div1 != 0 && -p*n - div2 != 0)s.insert({-p*m - div1, -p*n - div2});
	    			if(-p*m + div2 != 0 && -p*n + div1 != 0)s.insert({-p*m + div2, -p*n + div1});
	    			if(-p*m - div2 != 0 && -p*n - div1 != 0)s.insert({-p*m - div2, -p*n - div1});
	    		}
	    	}
	    }
    	cout << "Case " << ctr++ << ": " << sz(s) << endl;
    }        

    return 0;
}

