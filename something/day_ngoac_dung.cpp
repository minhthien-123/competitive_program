#include <iostream>
using namespace std;

string kt(string st){
	int d1 = 0, d2 = 0;
	for (int i = 0; i < st.length(); i++){
		if (st[i] == '('){
			d1+=1;
		}else{
			d2+=1;
		}
		if(d1 < d2){
			cout << "False";
			exit;
		}
	}
	if(d1 == d2){
		cout << "True";
	}else{
		cout << "False";
	}
}

int main(){
	string s;
	cin >> s;
	cout << kt(s);
	return 0;
}
