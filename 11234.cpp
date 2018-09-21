/*
Queue operates like BFS
Stack operates like DFS
Now we are given an expression which is to be evaluated by stack
Evaluate it and make a parse tree
then we have to BFS and reverse the order
*/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fo(i,n) for(i=0;i<n;++i)

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back


int main(){
    #if ONLINE_JUDGE
        ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	#endif

    string s;
    int t, i;
    cin >> t;
    while(t--){
    	int arr[10005][2];
    	for(i = 0; i < 10005; ++i)arr[i][0] = arr[i][1] = -1;
    	int root = -1;
    	cin >> s;
    	stack<pair<string,int>>st;
    	for(i = 0; i < sz(s); ++i){
    		if(isupper(s[i])){
    			pair<string,int>seconds = st.top(); st.pop();
    			pair<string,int>firsts = st.top(); st.pop();
    			root = i;
    			arr[i][0] = firsts.se;
    			arr[i][1] = seconds.se;
    			string temp = firsts.fi + s[i] + seconds.fi;
    			st.push({temp, i});
    		}
    		else{
    			string temp = "";
    			temp.pb(s[i]);
    			st.push({temp, i});
    		}
    	}
    	pair<string,int>res = st.top(); st.pop();
    	string ans;
    	queue<int>q;
    	q.push(root);
    	while(!q.empty()){
    		int tt = q.front();
    		q.pop();
    		ans.pb(s[tt]);
    		if(arr[tt][0] != -1)q.push(arr[tt][0]);
    		if(arr[tt][1] != -1)q.push(arr[tt][1]);
    	}
    	reverse(all(ans));
    	cout << ans << endl;
    }        

    return 0;
}

