/*
Substitute H1 in H2 formula then H2 in H3 forumula and so on until Hn-1 ... (we can generalize after 2-3 values)
Formula comes out to be
(n-1)(n-2)...(n-k)Hn-k = k(n-2)(n-3)...(n-k)A + (n-2)(n-3)...(n-k-1)B - k(n-1)(n-2)...(n-k-1)
Hn-k should be positive for all k so find the corresponding B.
B >= (k(n-1)(n-k-1) - ka) / (n-k-1)
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	cout << fixed << setprecision(2);

    double a, ans, val;
    int n, k;

    while(cin >> n){
    	cin >> a;
    	ans = 0.0;
    	for(k = 1; k < n; ++k){
    		val = (1.0*k*(n-1)*(n-k-1) - k*1.0*a)/(n-k-1);
    		ans = max(ans, val);
    	}
    	cout << ans << endl;
    }        
}

