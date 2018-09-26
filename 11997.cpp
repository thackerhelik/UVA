/*
Think about the simpler version first. 
Having only 2 arrays. How to solve this?
a0, a1, a2, ..... , an-1
b0, b1, b2, ..... , bn-1
(Assumptions: sorted arrays and priority queue first element is smallest)
Have a priority queue to store the values a[0] + b[0], a[1] + b[0], a[2] + b[0], ..... , a[n-1] + b[0]
Now a[0] + b[0] has to be the smallest value
So that is fixed. Now we can try a[0] + b[1] and push it into priority queue
so at a time priority queue has q elements and we fix the smallest one.
*/
#include <bits/stdc++.h>
using namespace std;

int l1[756], l2[756];

int main(){
	int k, i, j;
	while(cin >> k){
		for(i = 0; i < k; ++i)
			cin >> l1[i];
		sort(l1, l1 + k); //not needed as such to sort the first array since we are pushing all elements + l2[0] into the queue
		for(i = 1; i < k; ++i){
			for(j = 0; j < k; ++j){
				cin >> l2[j];
			}
			sort(l2, l2 + k);
			priority_queue<pair<int,int>>p;
			for(j = 0; j < k; ++j){
				p.push({-(l1[j] + l2[0]), 0});
			}
			for(j = 0; j < k; ++j){
				pair<int,int>pp = p.top();
				p.pop();
				l1[j] = -pp.first;
				p.push({(-l1[j] + l2[pp.second] - l2[pp.second + 1]), pp.second + 1});
			}
		}
		cout << l1[0];
		for(i = 1; i < k; ++i){
			cout << " " << l1[i];
		}
		cout << endl;
	}
}
