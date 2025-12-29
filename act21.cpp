#include <bits/stdc++.h>
using namespace std;

struct thiendeptrai
{
	long long val, dex, vt;
};

bool ss(thiendeptrai x, thiendeptrai y)
{
	if (x.dex > y.dex)
		return false;
	return true;
}

thiendeptrai a[1000005];
long long s[1000005], n, i, x, d = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("act21.inp", "r", stdin);
	//freopen("act21.out", "w", stdout);

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i].val >> a[i].dex;
		a[i].vt = i;
	}

	// for (int i = 0; i < n; i++) cout << a[i].val << " " << a[i].dex << "\n";
	sort(a, a + n, ss);
	d = 0;
	x = a[0].val;
	for (i = 0; i < n; i++)
	{
		if (x <= a[i].val)
		{
			d++;
			x = a[i].dex;
			s[d] = a[i].vt + 1;
		}
	}

	// for (i = 0; i < n; i++) cout << a[i].val << " " << a[i].dex << "\n";

	cout << d << "\n";
	// for (i = 1; i <= d; i++) cout << s[i] << "\n";

	return 0;
}
