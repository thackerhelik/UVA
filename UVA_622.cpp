/*

*/

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
typedef long long int ll;
typedef long double ld;
string s;

int curptr;

bool overall;

ll expression();
ll component();
ll factor();
ll positiveinteger();

ll expression(){
	ll ret;
	// cout << curptr << " " << s[curptr] << endl;
	if(s[curptr] == '(' || (s[curptr] >= '0' && s[curptr] <= '9')){
		ret = component();
		if(s[curptr] == '+'){
			curptr++;
			ret = ret + expression();
		}
	}
	else{
		overall = false;
		ret = -1;
	}
	return ret;
}

ll component(){
	ll ret;
	if(s[curptr] == '(' || (s[curptr] >= '0' && s[curptr] <= '9')){
		ret = factor();
		if(s[curptr] == '*'){
			curptr++;
			ret = ret * component();
		}
	}
	else{
		overall = false;
		ret = -1;
	}
	return ret;
}

ll factor(){
	ll ret;
	if(s[curptr] == '('){
		curptr++;
		ret = expression();
		if(s[curptr] != ')'){
			overall = false;
			ret = -1;
		}
		curptr++;
	}
	else if(s[curptr] >= '0' && s[curptr] <= '9'){
		ret = positiveinteger();
	}
	else{
		overall = false;
		ret = -1;
	}
	return ret;
}

ll positiveinteger(){
	string t;
	while(curptr < sz(s) && s[curptr] >= '0' && s[curptr] <= '9'){
		t.pb(s[curptr]);
		curptr++;
	}
	return stoll(t);
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		overall = true;
		curptr = 0;
		cin >> s;
		ll val = expression();
		if(val == -1 || overall == false || curptr < sz(s))cout << "ERROR" << endl;
		else cout << val << endl;
	}            

    return 0;
}

