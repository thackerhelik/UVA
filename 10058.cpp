/*
grammer parsing
A -> B | A , B has left recursion take care for that cases
*/
#include <bits/stdc++.h>
#define sz(x) (int)(x).size()

using namespace std;

bool statement();
bool action();
bool active_list();
bool actor();
bool article();
bool noun();
bool verb();


bool final;
int cur;
string s;

bool statement(){
	if(action()){
		if(cur >= sz(s))return true;
		else if((cur + 2) < sz(s) && s[cur] == ' ' && s[cur + 1] == ',' && s[cur + 2] == ' '){
			cur = cur + 3;
			if(statement())return true;
			else return false;
		}
		else return false;
	}
	else return false;
}

bool action(){
	if(active_list()){
		// cout << cur << endl;
		if((cur) < sz(s) && s[cur] == ' '){
			cur = cur + 1;
			// cout << s[cur+1] << endl;
			if(verb()){
				if((cur) < sz(s) && s[cur] == ' '){
					cur = cur + 1;
					if(active_list()){
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool active_list(){
	if(actor()){
		if((cur + 4) < sz(s) && s[cur] == ' ' && s[cur + 1] == 'a' && s[cur + 2] == 'n' && s[cur + 3] == 'd' && s[cur + 4] == ' '){
			cur = cur + 5;
			if(active_list()){
				return true;
			}
			else return false;
		}
		return true;
	}
	return false;
}

bool actor(){
	if(noun()){
		return true;
	}
	else{
		if(article()){
			if(cur < sz(s) && s[cur] == ' '){
				cur = cur + 1;
				if(noun()){
					return true;
				}
			}
		}
		return false;
	}
}

bool article(){
	if((cur) < sz(s) && s[cur] == 'a'){
		cur = cur + 1;
		return true;
	}

	if((cur + 2) < sz(s) && s[cur] == 't' && s[cur + 1] == 'h' && s[cur + 2] == 'e'){
		cur = cur + 3;
		return true;
	}

	return false;
}

bool noun(){
	if((cur + 2) < sz(s) && s[cur] == 't' && s[cur + 1] == 'o' && s[cur + 2] == 'm'){
		cur = cur + 3;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'j' && s[cur + 1] == 'e' && s[cur + 2] == 'r' && s[cur + 3] == 'r' && s[cur + 4] == 'y'){
		cur = cur + 5;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'g' && s[cur + 1] == 'o' && s[cur + 2] == 'o' && s[cur + 3] == 'f' && s[cur + 4] == 'y'){
		cur = cur + 5;
		return true;
	}
	if((cur + 5) < sz(s) && s[cur] == 'm' && s[cur + 1] == 'i' && s[cur + 2] == 'c' && s[cur + 3] == 'k' && s[cur + 4] == 'e' && s[cur +5] == 'y'){
		cur = cur + 6;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'j' && s[cur + 1] == 'i' && s[cur + 2] == 'm' && s[cur + 3] == 'm' && s[cur + 4] == 'y'){
		cur = cur + 5;
		return true;
	}
	if((cur + 2) < sz(s) && s[cur] == 'd' && s[cur + 1] == 'o' && s[cur + 2] == 'g'){
		cur = cur + 3;
		return true;
	}
	if((cur + 2) < sz(s) && s[cur] == 'c' && s[cur + 1] == 'a' && s[cur + 2] == 't'){
		cur = cur + 3;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'm' && s[cur + 1] == 'o' && s[cur + 2] == 'u' && s[cur + 3] == 's' && s[cur + 4] == 'e'){
		cur = cur + 5;
		return true;
	}
	return false;
}

bool verb(){

	//plural gets more preference

	if((cur + 4) < sz(s) && s[cur] == 'h' && s[cur + 1] == 'a' && s[cur + 2] == 't' && s[cur + 3] == 'e' && s[cur + 4] == 's'){
		cur = cur + 5;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'l' && s[cur + 1] == 'o' && s[cur + 2] == 'v' && s[cur + 3] == 'e' && s[cur + 4] == 's'){
		cur = cur + 5;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'k' && s[cur + 1] == 'n' && s[cur + 2] == 'o' && s[cur + 3] == 'w' && s[cur + 4] == 's'){
		cur = cur + 5;
		return true;
	}
	if((cur + 4) < sz(s) && s[cur] == 'l' && s[cur + 1] == 'i' && s[cur + 2] == 'k' && s[cur + 3] == 'e' && s[cur + 4] == 's'){
		cur = cur + 5;
		return true;
	}

	//singluar

	if((cur + 3) < sz(s) && s[cur] == 'h' && s[cur + 1] == 'a' && s[cur + 2] == 't' && s[cur + 3] == 'e'){
		cur = cur + 4;
		return true;
	}
	if((cur + 3) < sz(s) && s[cur] == 'l' && s[cur + 1] == 'o' && s[cur + 2] == 'v' && s[cur + 3] == 'e'){
		cur = cur + 4;
		return true;
	}
	if((cur + 3) < sz(s) && s[cur] == 'k' && s[cur + 1] == 'n' && s[cur + 2] == 'o' && s[cur + 3] == 'w'){
		cur = cur + 4;
		return true;
	}
	if((cur + 3) < sz(s) && s[cur] == 'l' && s[cur + 1] == 'i' && s[cur + 2] == 'k' && s[cur + 3] == 'e'){
		cur = cur + 4;
		return true;
	}

	return false;

}

int main(){
	while(getline(cin, s, '\n')){
		cur = 0;
		if(statement() && cur >= sz(s)){
			cout << "YES I WILL" << endl;
		}
		else{
			cout << "NO I WON'T" << endl;
		}
	}
}
