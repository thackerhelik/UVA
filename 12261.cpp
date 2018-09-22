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

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define sz(x) (int)(x).size()

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

	    	ans = min(ans, changes + temp);

			if(where != -1){
				temp = 2*(sz(s) - where - 1) + 2 + i;
			}

			ans = min(ans, changes + temp);

    	}

    	cout << ans << endl;
    }        

    return 0;
}

