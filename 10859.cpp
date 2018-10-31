/*
the input is forest (many trees)
We can use dp to calculate the answer (atleast think dp one while optimization problems)
here we need to minimize lamp posts such that each road is covered (vertex cover) and after that maximize the roads which get light from 2 lamps
we have 2 options for a tree node
place a lamp post f = 1 --> we have 2 options for each child of this node. place a lamp or not
do not place a lamp post f = 0 --> we have to place a lamp post at each of the children so that all the roads having one end point at the node are lighted
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

pair<int,int> dp[MAXN][2];
bool used[MAXN];
vector<int>adj[MAXN];

pair<int,int>solve(int node, int parent, int f){
	if(dp[node][f].first != -1)return dp[node][f];
	pair<int,int>result = make_pair(0, 0);
	used[node] = true;
	for(auto it: adj[node]){
		if(it == parent)continue;
		pair<int,int>result0 = solve(it, node, 0);
		pair<int,int>result1 = solve(it, node, 1);
		if(f == 0){
			result.first += result1.first;
			result.second += result1.second;
		}
		else{
			if(result0.first == result1.first){
				result.first += min(result0.first, result1.first);
				result.second += max(result0.second, result1.second + 1);
			}	
			else if(result0.first < result1.first){
				result.first += result0.first;
				result.second += result0.second;
			}
			else{
				result.first += result1.first;
				result.second += result1.second + 1;
			}
		}
	}	
	if(f == 1)result.first++;
	return dp[node][f] = result;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    int t, n, m, a, b;
    cin >> t;
    while(t--){

    	pair<int,int>result = make_pair(0, 0);

    	for(int i = 0; i < MAXN; ++i){
    		adj[i].clear();
    		used[i] = false;
    		for(int j = 0; j < 2; ++j){
    			dp[i][j] = make_pair(-1, -1);
    		}
    	}

    	cin >> n >> m;
    	
    	for(int i = 0; i < m; ++i){
    		cin >> a >> b;
    		adj[a].push_back(b);
    		adj[b].push_back(a);
    	}

    	for(int i = 0; i < n; ++i){
    		if(used[i])continue;
    		pair<int,int>result0 = solve(i, -1, 0);
    		pair<int,int>result1 = solve(i, -1, 1);
   	
   			if(result0.first == result1.first){
   				result.first += result0.first;
   				result.second += max(result0.second, result1.second);
   			}
    		else if(result0.first < result1.first){
    			result.first += result0.first;
    			result.second += result0.second;
    		}
    		else{
    			result.first += result1.first;
    			result.second += result1.second;
    		}

    	}

    	cout << result.first << " " << result.second << " " << m - result.second << endl;

    }        

    return 0;
}

