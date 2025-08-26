#include <bits/stdc++.h>
using namespace std;

int main(){
	FILE * f = NULL;
	char n[128];
	
	f = fopen("xuly.txt", "r");
	
	fgets(n, 128, f);
	
	cout << n; 
	
	fgets(n, 128, f);
	
	cout << n;
}
