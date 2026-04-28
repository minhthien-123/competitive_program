#include <bits/stdc++.h>
using namespace std;
#define task "heap1"
#define int long long
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen(task ".inp", "r", stdin);
	//freopen(task ".out", "w", stdout);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> heap;
		for (int i = 1, x; i <= n; i++)
		{
			cin >> x;
			heap.push(x);
		}

		int ans = 0;
		while (heap.size() > 1)
		{
			int a = heap.top();
			heap.pop();
			int b = heap.top();
			heap.pop();

			ans += a + b;

			cout << a << " " << b << "\n";

			heap.push(a + b);
		}

		cout << ans << "\n";
	}

	return 0;
}