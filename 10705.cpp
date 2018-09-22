/*
Saw the hint
First find max value possible which is placing 1s at all s[i] == 'p' and the minimum value by placing 1 at all s[i] == 'n'
Now between max and min all values are possible (how?)
Let diff = max - k where k is the value we want to make
Now lets iterate over max value
if 2^i <= diff we can greedily subtract it from diff
if it is 1 that means there was p and we make it 0 and if it is 0 then we make it 1
*/


#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define ll long long int

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    ll i, n, te;
    string s;
    cin >> te;
    ll k;
    while(te--){
    	cin >> n;
    	cin >> s;
    	cin >> k;
    	reverse(all(s));
    	string ans = "";
    	ll mx = 0, mn = 0;
    	for(i = n - 1; i >= 0; --i){
    		if(s[i] == 'p'){
    			mx = mx + (1LL << i);
    			ans.pb('1');
    		}
    		else{
    			mn = mn + (1LL << i);
    			ans.pb('0');
    		}
    	}
    	mn = -mn;
    	
    	if(k > mx || k < mn){
    		cout << "Impossible" << endl;
    		continue;
    	}

    	ll diff = mx - k;

    	for(i = 0; i < n; ++i){
    		if((1LL<<(n-i-1)) <= diff){
    			diff -= (1LL<<(n-i-1));
    			if(ans[i] == '1')ans[i] = '0';
    			else ans[i] = '1';
    		}
    	}

    	cout << ans << endl;

    }        

    return 0;
}

