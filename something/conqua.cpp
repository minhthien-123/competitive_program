#include<iostream>
using namespace std;

int v1, v2, n, a[55], dem, j;

void bt(int i, int s){
	for (int j = i; j <= n; j++){
		if (a[j] > s) return;
		if (s == a[j]){
			for (int k = 0; k <= n; k++){
				if (a[k] != 0) cout << a[k] << " ";
			}
			return;
			dem ++;
		}
		bt(j + 1; s - a[j]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v1 >> v2;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	bt(1, v1 - v2);
	
	if (dem == 0) cout << -1;

	return 0;
}
